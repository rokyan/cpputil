#include <gtest.hpp>
#include <algorithm.hpp>
#include <vector>

namespace test
{
    TEST(CountTest, TestEmptyRange)
    {
        using std::begin;
        using std::end;

        std::vector<int> data;
        auto predicate = [](int value) { return value == 1; };

        EXPECT_EQ(cpputil::count(begin(data), end(data), 1), 0);
        EXPECT_EQ(cpputil::count_if(begin(data), end(data), predicate), 0);
    }

    TEST(CountTest, TestCountingExistingElement)
    {
        using std::begin;
        using std::end;

        std::vector<int> data{ 2, 4, 1, 2, 1 };
        auto predicate = [](int value) { return value == 1; };

        EXPECT_EQ(cpputil::count(begin(data), end(data), 1), 2);
        EXPECT_EQ(cpputil::count_if(begin(data), end(data), predicate), 2);
    }

    TEST(CountTest, TestCountingNonExistingElement)
    {
        using std::begin;
        using std::end;

        std::vector<int> data{ 2, 4, 2 };
        auto predicate = [](int value) { return value == 1; };

        auto expected = std::end(data);
        EXPECT_EQ(cpputil::count(begin(data), end(data), 1), 0);
        EXPECT_EQ(cpputil::count_if(begin(data), end(data), predicate), 0);
    }
}