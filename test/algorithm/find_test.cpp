#include <gtest.hpp>
#include <algorithm.hpp>
#include <vector>

namespace test
{
    TEST(FindTest, TestEmptyRange)
    {
        std::vector<int> data;
        auto predicate = [](int value) { return value == 1; };

        EXPECT_EQ(cpputil::find(std::begin(data), std::end(data), 1), std::end(data));
        EXPECT_EQ(cpputil::find_if(std::begin(data), std::end(data), predicate), std::end(data));
        EXPECT_EQ(cpputil::find_if_not(std::begin(data), std::end(data), predicate), std::end(data));
    }

    TEST(FindTest, TestLookForExistingElement)
    {
        std::vector<int> data{ 2, 4, 1, 2, 1 };
        auto predicate = [](int value) { return value == 1; };
        auto negative_predicate = [](int value) { return value != 1; };

        auto expected = std::next(std::begin(data), 2);
        EXPECT_EQ(cpputil::find(std::begin(data), std::end(data), 1), expected);
        EXPECT_EQ(cpputil::find_if(std::begin(data), std::end(data), predicate), expected);
        EXPECT_EQ(cpputil::find_if_not(std::begin(data), std::end(data), negative_predicate), expected);
    }

    TEST(FindTest, TestLookForNonExistingElement)
    {
        std::vector<int> data{ 2, 4, 2 };
        auto predicate = [](int value) { return value == 1; };
        auto negative_predicate = [](int value) { return value != 1; };

        auto expected = std::end(data);
        EXPECT_EQ(cpputil::find(std::begin(data), std::end(data), 1), expected);
        EXPECT_EQ(cpputil::find_if(std::begin(data), std::end(data), predicate), expected);
        EXPECT_EQ(cpputil::find_if_not(std::begin(data), std::end(data), negative_predicate), expected);
    }
}