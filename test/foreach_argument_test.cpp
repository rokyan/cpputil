#include <gtest.hpp>
#include <foreach_argument.hpp>
#include <foreach_argument_test_types.hpp>
#include <move.hpp>
#include <string>

namespace test
{
    TEST(ForeachArgumentTest, TestGeneralUseCase)
    {
        auto sum = 0LL;
        auto get_sum = [&sum](auto x) {
            sum += x;
        };

        cpputil::foreach_argument(get_sum, 1, 2L, 3LL);

        EXPECT_EQ(sum, 6LL);
    }

    TEST(ForeachArgumentTest, TestArgumentValueCategory)
    {
        testable<long long> ltb;
        testable<long long> rtb;

        cpputil::foreach_argument(ltb, 1, 2L, 3LL);
        cpputil::foreach_argument(cpputil::move(rtb), 1, 2L, 3LL);

        EXPECT_EQ(ltb.value, 6LL);
        EXPECT_EQ(rtb.value, -6LL);
    }

    TEST(ForeachArgumentTest, TestTupleArgument)
    {
        auto sum = 0LL;
        auto get_sum = [&sum](auto x) {
            sum += x;
        };

        cpputil::foreach_tuple_argument(get_sum, std::make_tuple(1, 2L, 3LL));

        EXPECT_EQ(sum, 6LL);
    }

    TEST(ForeachArgumentTest, TestTupleArgumentValueCategory)
    {
        testable<long long> ltb;
        testable<long long> rtb;

        cpputil::foreach_tuple_argument(ltb, std::make_tuple(1, 2L, 3LL));
        cpputil::foreach_tuple_argument(cpputil::move(rtb), std::make_tuple(1, 2L, 3LL));

        EXPECT_EQ(ltb.value, 6LL);
        EXPECT_EQ(rtb.value, -6LL);
    }
}