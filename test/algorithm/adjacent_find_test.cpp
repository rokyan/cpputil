#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>
#include <iterator_operations.hpp>

namespace test
{

TEST(AdjacentFindTest, TestEmptyRanges)
{
    const integer_container empty;

    const auto pred = [](int x, int y) { return x == y; };

    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(empty), cpputil::end(empty)),
        cpputil::end(empty));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(empty), cpputil::end(empty), pred),
        cpputil::end(empty));
}

TEST(AdjacentFindTest, TestAdjacentFind)
{
    const integer_container data_1{ 1, 1 };
    const integer_container data_2{ 1, 2 };
    const integer_container data_3{ 1, 1, 2 };
    const integer_container data_4{ 2, 1, 1 };
    const integer_container data_5{ 2, 1, 2 };

    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_1), cpputil::end(data_1)),
        cpputil::begin(data_1));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_2), cpputil::end(data_2)),
        cpputil::end(data_2));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_3), cpputil::end(data_3)),
        cpputil::begin(data_3));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_4), cpputil::end(data_4)),
        cpputil::next(cpputil::begin(data_4)));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_5), cpputil::end(data_5)),
        cpputil::end(data_5));
}

TEST(AdjacentFindTest, TestAdjacentFindPred)
{
    const integer_container data_1{ 1, 1 };
    const integer_container data_2{ 1, 2 };
    const integer_container data_3{ 1, 1, 2 };
    const integer_container data_4{ 2, 1, 1 };
    const integer_container data_5{ 2, 1, 2 };

    const auto pred = [](int x, int y) { return x == y; };

    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_1), cpputil::end(data_1), pred),
        cpputil::begin(data_1));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_2), cpputil::end(data_2), pred),
        cpputil::end(data_2));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_3), cpputil::end(data_3), pred),
        cpputil::begin(data_3));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_4), cpputil::end(data_4), pred),
        cpputil::next(cpputil::begin(data_4)));
    EXPECT_EQ(cpputil::adjacent_find(cpputil::begin(data_5), cpputil::end(data_5), pred),
        cpputil::end(data_5));
}

} // namespace test