#include <gtest\gtest.h>
#include <apply.hpp>
#include <move.hpp>

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
        int sum_of_two(int x, int y) const
        {
            return x + y;
        }

        int one = 1;
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
        callable c;

        EXPECT_EQ(cpputil::apply(c, std::make_tuple(4, 2)), 6);
        EXPECT_EQ(cpputil::apply(cpputil::move(c), std::make_tuple(4, 2)), 2);
    }

    TEST(apply_test, test_pointer_to_member_call)
    {
        testable t;

        const auto one_ptr = &testable::one;
        const auto sum_of_two_ptr = &testable::sum_of_two;

        EXPECT_EQ(cpputil::apply(one_ptr, std::make_tuple(t)), 1);
        EXPECT_EQ(cpputil::apply(sum_of_two_ptr, std::make_tuple(t, 4, 2)), 6);
    }

    TEST(apply_test, test_variadic)
    {
        const auto gen_sum = [](auto&&... es) {
            return (es + ...);
        };

        EXPECT_EQ(cpputil::apply(gen_sum, std::make_tuple(1, 2L, 3LL, 4.0f, 5.0)), 15.0);
    }
}