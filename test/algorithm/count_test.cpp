#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(CountTest, TestEmptyRange)
{
    const integer_container empty;

    const auto pred = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(RANGE(empty), 1), 0);
    EXPECT_EQ(cpputil::count_if(RANGE(empty), pred), 0);
}

TEST(CountTest, TestNoElements)
{
    const integer_container data{ 2, 3 };

    const auto pred = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(RANGE(data), 1), 0);
    EXPECT_EQ(cpputil::count_if(RANGE(data), pred), 0);
}

TEST(CountTest, TestSingleElement)
{
    const integer_container data{ 2, 1, 3 };

    const auto pred = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(RANGE(data), 1), 1);
    EXPECT_EQ(cpputil::count_if(RANGE(data), pred), 1);
}

TEST(CountTest, TestMultipleElements)
{
    const integer_container data{ 1, 2, 1, 3, 1 };

    const auto pred = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(RANGE(data), 1), 3);
    EXPECT_EQ(cpputil::count_if(RANGE(data), pred), 3);
}
} // namespace test
