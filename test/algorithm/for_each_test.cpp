#include <gtest.hpp>
#include <for_each.hpp>
#include <vector>

namespace test
{
    struct Accumulator
    {
        void operator()(int value)
        {
            acc += value;
        }

        int acc = 0;
    };

    TEST(ForEachTest, TestForEach)
    {
        using std::begin;
        using std::end;

        std::vector<int> empty;
        std::vector<int> data{ 1, 2, 3, 4, 5 };

        auto func = [](int& elem) { elem *= elem; };

        cpputil::for_each(begin(empty), end(empty), func);
        EXPECT_EQ(empty, std::vector<int>{});

        const std::vector<int> expected{ 1, 4, 9, 16, 25 };
        cpputil::for_each(begin(data), end(data), func);
        EXPECT_EQ(data, expected);
    }

    TEST(ForEachTest, TestForEachN)
    {
        using std::begin;
        using std::end;

        std::vector<int> data{ 0, 0, 0, 0, 0 };

        auto func = [](int& elem) { ++elem; };

        for (auto i = std::size_t{ 0 }; i <= data.size(); ++i)
        {
            cpputil::for_each_n(begin(data), i, func);
        }

        const std::vector<int> expected{ 5, 4, 3, 2, 1 };
        EXPECT_EQ(data, expected);
    }

    TEST(ForEachTest, TestReturnValue)
    {
        using std::begin;
        using std::end;

        std::vector<int> data{ 1, 2, 3, 4, 5 };

        Accumulator acc1;
        Accumulator ret1 = cpputil::for_each(begin(data), end(data), acc1);

        EXPECT_EQ(ret1.acc, 15);

        Accumulator acc2;
        Accumulator ret2 = cpputil::for_each_n(begin(data), data.size(), acc2);

        EXPECT_EQ(ret2.acc, 15);
    }
}