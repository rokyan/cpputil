#include <gtest\gtest.h>
#include <apply.h>
#include <move.h>

namespace test
{
    struct callable
    {
        int operator()(int x, int y) const &
        {
            return x + y;
        }

        int operator()(int x, int y) const &&
        {
            return x - y;
        }
    };

    struct testable
    {
        int foo(int x, int y) const
        {
            return x + y;
        }

        int bar = 1;
    };

    TEST(apply_test, test_basic_apply_scenario)
    {
        const auto unary_callable =[](int x) {
            return x * x;
        };
        EXPECT_EQ(cpputil::apply(unary_callable, std::make_tuple(2)), 4);

        const auto binary_callable = [](int x, int y) {
            return x * x + y * y;
        };
        EXPECT_EQ(cpputil::apply(binary_callable, std::make_tuple(2, 4)), 20);

        const auto ternary_callable = [](int x, int y, int z) {
            return x * x + y * y + z * z;
        };
        EXPECT_EQ(cpputil::apply(ternary_callable, std::make_tuple(2, 4, 8)), 84);
    }

    TEST(apply_test, test_value_category_correctness)
    {
        callable cb;

        EXPECT_EQ(cpputil::apply(cb, std::make_tuple(4, 2)), 6);
        EXPECT_EQ(cpputil::apply(cpputil::move(cb), std::make_tuple(4, 2)), 2);
    }

    TEST(apply_test, test_pointer_to_member_call)
    {
        testable t;

        auto bar_ptr = &testable::bar;
        auto foo_ptr = &testable::foo;

        EXPECT_EQ(cpputil::apply(bar_ptr, std::make_tuple(t)), 1);
        EXPECT_EQ(cpputil::apply(foo_ptr, std::make_tuple(t, 4, 2)), 6);
    }
}