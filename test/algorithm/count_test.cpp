#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>

namespace test
{

TEST(CountTest, TestEmptyRange)
{
    const integer_container empty;

    const auto pred = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(cpputil::begin(empty), cpputil::end(empty), 1), 0);
    EXPECT_EQ(cpputil::count_if(cpputil::begin(empty), cpputil::end(empty), pred), 0);
}

TEST(CountTest, TestCountingExistingElement)
{
    const integer_container data_single{ 2, 1, 2 };
    const integer_container data_multiple{ 2, 1, 2, 1 };

    const auto pred = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(cpputil::begin(data_single), cpputil::end(data_single), 1), 1);
    EXPECT_EQ(cpputil::count_if(cpputil::begin(data_single), cpputil::end(data_single), pred), 1);

    EXPECT_EQ(cpputil::count(cpputil::begin(data_multiple), cpputil::end(data_multiple), 1), 2);
    EXPECT_EQ(cpputil::count_if(cpputil::begin(data_multiple), cpputil::end(data_multiple), pred), 2);
}

TEST(CountTest, TestCountingNonExistingElement)
{
    const integer_container data{ 2, 4, 2 };

    const auto pred = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(cpputil::begin(data), cpputil::end(data), 1), 0);
    EXPECT_EQ(cpputil::count_if(cpputil::begin(data), cpputil::end(data), pred), 0);
}

} // namespace test
