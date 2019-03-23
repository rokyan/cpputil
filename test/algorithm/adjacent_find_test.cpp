#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <iterator_operations.hpp>

namespace test
{

#define RANGE(cont)     cont.begin(), cont.end()

TEST(AdjacentFindTest, TestEmptyRange)
{
    const integer_container empty;

    const auto pred = [](int x, int y) { return x == y; };

    {
        const auto expected = empty.end();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(empty)), expected);
    }
    {
        const auto expected = empty.end();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(empty), pred), expected);
    }
}

TEST(AdjacentFindTest, TestSingleElement)
{
    const integer_container data{ 1 };

    const auto pred = [](int x, int y) { return x == y; };

    {
        const auto expected = data.end();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data)), data.end());
    }
    {
        const auto expected = data.end();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data), pred), data.end());
    }

}

TEST(AdjacentFindTest, TestResultAtTheBeginning)
{
    const integer_container data_1{ 1, 1 };
    const integer_container data_2{ 1, 1, 2 };

    const auto pred = [](int x, int y) { return x == y; };

    {
        const auto expected = data_1.begin();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data_1)), expected);
    }
    {
        const auto expected = data_1.begin();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data_1), pred), expected);
    }
    {
        const auto expected = data_2.begin();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data_2)), expected);
    }
    {
        const auto expected = data_2.begin();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data_2), pred), expected);
    }
}

TEST(AdjacentFindTest, TestResultAtTheEnd)
{
    const integer_container data_1{ 1, 1 };
    const integer_container data_2{ 2, 1, 1 };

    const auto pred = [](int x, int y) { return x == y; };

    {
        const auto expected = data_1.begin();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data_1)), expected);
    }
    {
        const auto expected = data_1.begin();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data_1), pred), expected);
    }
    {
        const auto expected = cpputil::next(data_2.begin());
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data_2)), expected);
    }
    {
        const auto expected = cpputil::next(data_2.begin());
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data_2), pred), expected);
    }
}

TEST(AdjacentFindTest, TestResultInTheMiddle)
{
    const integer_container data{ 2, 1, 1, 2, 3 };

    const auto pred = [](int x, int y) { return x == y; };

    {
        const auto expected = cpputil::next(data.begin());
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data)), expected);
    }
    {
        const auto expected = cpputil::next(data.begin());
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data), pred), expected);
    }
}

TEST(AdjacentFindTest, TestMultipleInclusions)
{
    const integer_container data{ 2, 1, 1, 2, 1, 1, 3 };

    const auto pred = [](int x, int y) { return x == y; };

    {
        const auto expected = cpputil::next(data.begin());
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data)), expected);
    }
    {
        const auto expected = cpputil::next(data.begin());
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data), pred), expected);
    }
}

TEST(AdjacentFindTest, TestNoResults)
{
    const integer_container data{ 1, 2, 1, 2, 1 };

    const auto pred = [](int x, int y) { return x == y; };

    {
        const auto expected = data.end();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data)), expected);
    }
    {
        const auto expected = data.end();
        EXPECT_EQ(cpputil::adjacent_find(RANGE(data), pred), expected);
    }
}

} // namespace test