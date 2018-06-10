#include <gtest\gtest.h>
#include <apply.h>

namespace test
{
    TEST(apply_test, test_apply)
    {
        const auto unary_callable =[](int x) { return x * x; };
        EXPECT_EQ(cpputil::apply(unary_callable, std::make_tuple(2)), 2 * 2);

        const auto binary_callable = [](int x, int y) { return x * x + y * y; };
        EXPECT_EQ(cpputil::apply(binary_callable, std::make_tuple(2, 4)), 2 * 2 + 4 * 4);

        const auto ternary_callable = [](int x, int y, int z) { return x * x + y * y + z * z; };
        EXPECT_EQ(cpputil::apply(ternary_callable, std::make_tuple(2, 4, 8)), 2 * 2 + 4 * 4 + 8 * 8);
    }
}