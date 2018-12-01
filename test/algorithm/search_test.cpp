#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>
#include <iterator_operations.hpp>

namespace test
{

TEST(SearchTest, TestEmptyRanges)
{
    const integer_container empty;
    const integer_container data{ 0, 1 };

    const auto pred = [](int x, int y) { return x == y; };

    EXPECT_EQ(cpputil::search(cpputil::begin(empty), cpputil::end(empty),
        cpputil::begin(data), cpputil::end(data)), cpputil::begin(empty));
    EXPECT_EQ(cpputil::search(cpputil::begin(empty), cpputil::end(empty),
        cpputil::begin(data), cpputil::end(data), pred), cpputil::begin(empty));

    EXPECT_EQ(cpputil::search(cpputil::begin(data), cpputil::end(data),
        cpputil::begin(empty), cpputil::end(empty)), cpputil::begin(data));
    EXPECT_EQ(cpputil::search(cpputil::begin(data), cpputil::end(data),
        cpputil::begin(empty), cpputil::end(empty), pred), cpputil::begin(data));

    EXPECT_EQ(cpputil::search(cpputil::begin(empty), cpputil::end(empty),
        cpputil::begin(empty), cpputil::end(empty)), cpputil::begin(empty));
    EXPECT_EQ(cpputil::search(cpputil::begin(empty), cpputil::end(empty),
        cpputil::begin(empty), cpputil::end(empty), pred), cpputil::begin(empty));
}

TEST(SearchTest, TestSearchForExistingSubRange)
{
    const integer_container data_1{ 0, 1, 2, 3 };
    const integer_container data_2{ 2, 0, 1, 3 };
    const integer_container data_3{ 2, 3, 0, 1 };
    const integer_container data_4{ 0, 1 };

    const auto pred = [](int x, int y) { return x == y; };

    EXPECT_EQ(cpputil::search(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_4), cpputil::end(data_4)), cpputil::begin(data_1));
    EXPECT_EQ(cpputil::search(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_4), cpputil::end(data_4), pred), cpputil::begin(data_1));

    EXPECT_EQ(cpputil::search(cpputil::begin(data_2), cpputil::end(data_2),
        cpputil::begin(data_4), cpputil::end(data_4)), cpputil::next(cpputil::begin(data_2), 1));
    EXPECT_EQ(cpputil::search(cpputil::begin(data_2), cpputil::end(data_2),
        cpputil::begin(data_4), cpputil::end(data_4), pred), cpputil::next(cpputil::begin(data_2), 1));

    EXPECT_EQ(cpputil::search(cpputil::begin(data_3), cpputil::end(data_3),
        cpputil::begin(data_4), cpputil::end(data_4)), cpputil::next(cpputil::begin(data_3), 2));
    EXPECT_EQ(cpputil::search(cpputil::begin(data_3), cpputil::end(data_3),
        cpputil::begin(data_4), cpputil::end(data_4), pred), cpputil::next(cpputil::begin(data_3), 2));
}

TEST(SearchTest, TestSearchForNonExistingSubRange)
{
    const integer_container data_1{ 0, 2, 3 };
    const integer_container data_2{ 2, 0, 3 };
    const integer_container data_3{ 2, 3, 0 };
    const integer_container data_4{ 0, 1 };

    const auto pred = [](int x, int y) { return x == y; };

    EXPECT_EQ(cpputil::search(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_4), cpputil::end(data_4)), cpputil::end(data_1));
    EXPECT_EQ(cpputil::search(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_4), cpputil::end(data_4), pred), cpputil::end(data_1));

    EXPECT_EQ(cpputil::search(cpputil::begin(data_2), cpputil::end(data_2),
        cpputil::begin(data_4), cpputil::end(data_4)), cpputil::end(data_2));
    EXPECT_EQ(cpputil::search(cpputil::begin(data_2), cpputil::end(data_2),
        cpputil::begin(data_4), cpputil::end(data_4), pred), cpputil::end(data_2));

    EXPECT_EQ(cpputil::search(cpputil::begin(data_3), cpputil::end(data_3),
        cpputil::begin(data_4), cpputil::end(data_4)), cpputil::end(data_3));
    EXPECT_EQ(cpputil::search(cpputil::begin(data_3), cpputil::end(data_3),
        cpputil::begin(data_4), cpputil::end(data_4), pred), cpputil::end(data_3));
}

} // namespace test