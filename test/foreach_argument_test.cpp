#include <gtest\gtest.h>
#include <foreach_argument.h>
#include <move.h>
#include <string>

namespace test
{
    template<typename T>
    struct testable
    {
        void operator()(T t) &
        {
            value += t;
        }

        void operator()(T t) &&
        {
            value += t * t;
        }

        T value{};
    };

    TEST(foreach_argument_test, test_foreach_argument)
    {
        auto sum = 0LL;
        auto get_sum = [&sum](auto x) {
            sum += x;
        };

        cpputil::foreach_argument(get_sum, 1, 2L, 3LL);

        EXPECT_EQ(sum, 6);
    }

    TEST(foreach_argument_test, test_foreach_argument_value_category)
    {
        testable<long long> ltb;
        testable<long long> rtb;

        cpputil::foreach_argument(ltb, 1, 2L, 3LL);
        cpputil::foreach_argument(cpputil::move(rtb), 1, 2L, 3LL);

        EXPECT_EQ(ltb.value, 6);
        EXPECT_EQ(rtb.value, 14);
    }

    TEST(foreach_argument_test, test_foreach_tuple_argument)
    {
        auto sum = 0LL;
        auto get_sum = [&sum](auto x) {
            sum += x;
        };

        cpputil::foreach_tuple_argument(get_sum, std::make_tuple(1, 2L, 3LL));

        EXPECT_EQ(sum, 6);
    }

    TEST(foreach_argument_test, test_foreach_tuple_argument_value_category)
    {
        testable<long long> ltb;
        testable<long long> rtb;

        cpputil::foreach_tuple_argument(ltb, std::make_tuple(1, 2L, 3LL));
        cpputil::foreach_tuple_argument(cpputil::move(rtb), std::make_tuple(1, 2L, 3LL));

        EXPECT_EQ(ltb.value, 6);
        EXPECT_EQ(rtb.value, 14);
    }
}