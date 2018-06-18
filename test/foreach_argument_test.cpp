#include <gtest\gtest.h>
#include <foreach_argument.h>

namespace test
{
    TEST(foreach_argument_test, test_foreach_argument_basic_scenario)
    {
        int sum = 0;
        auto sum_func = [&sum](auto x) {
            sum += static_cast<int>(x);
        };

        cpputil::foreach_argument(sum_func, 1, 2L, 3LL, 4.0f, 5.0);

        EXPECT_EQ(sum, 15);
    }

    TEST(foreach_argument_test, test_foreach_tuple_argument_basic_scenario)
    {
        int sum = 0;
        auto sum_func = [&sum](auto x) {
            sum += static_cast<int>(x);
        };

        cpputil::foreach_tuple_argument(sum_func, std::make_tuple(1, 2L, 3LL, 4.0f, 5.0));

        EXPECT_EQ(sum, 15);
    }
}