#include <gtest.hpp>
#include <common.hpp>
#include <iterator.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(FindFirstOfTest, TestEmptyRange)
{
    const integer_container empty;
    const integer_container data{ 0, 1, 2 };

    const auto pred = [](int x, int y) { return x == y; };

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(empty), cpputil::end(empty),
        cpputil::begin(data), cpputil::end(data)), cpputil::end(empty));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data), cpputil::end(data),
        cpputil::begin(empty), cpputil::end(empty)), cpputil::end(data));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(empty), cpputil::begin(empty),
        cpputil::begin(empty), cpputil::end(empty)), cpputil::end(empty));

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(empty), cpputil::end(empty),
        cpputil::begin(data), cpputil::end(data), pred), cpputil::end(empty));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data), cpputil::end(data),
        cpputil::begin(empty), cpputil::end(empty), pred), cpputil::end(data));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(empty), cpputil::begin(empty),
        cpputil::begin(empty), cpputil::end(empty), pred), cpputil::end(empty));
}

TEST(FindFirstOfTest, TestOverlappingRanges)
{
    const integer_container data_1{ 0, 1 };
    const integer_container data_2{ 2, 0, 2 };
    const integer_container data_3{ 2, 1, 2 };

    const auto pred = [](int x, int y) { return x == y; };

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_2), cpputil::end(data_2)), cpputil::begin(data_1));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_2), cpputil::end(data_2), pred), cpputil::begin(data_1));

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_3), cpputil::end(data_3)), cpputil::prev(cpputil::end(data_1)));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_3), cpputil::end(data_3), pred), cpputil::prev(cpputil::end(data_1)));
}

TEST(FindFirstOfTest, TestNonOverlappingRanges)
{
    const integer_container data_1{ 0, 1 };
    const integer_container data_2{ 2, 3 };

    const auto pred = [](int x, int y) { return x == y; };

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_2), cpputil::end(data_2)), cpputil::end(data_1));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_2), cpputil::end(data_2), pred), cpputil::end(data_1));
}

} // namespace test
