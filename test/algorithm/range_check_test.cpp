#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>

namespace test
{

TEST(TestRangeCheck, TestAllOf)
{
    const integer_container empty;
    const integer_container all{ 1, 1, 1 };
    const integer_container not_all{ 1, 0, 1 };

    const auto predicate = [](int value) { return value == 1; };

    EXPECT_TRUE(cpputil::all_of(cpputil::begin(empty), cpputil::end(empty), predicate));
    EXPECT_TRUE(cpputil::all_of(cpputil::begin(all), cpputil::end(all), predicate));
    EXPECT_FALSE(cpputil::all_of(cpputil::begin(not_all), cpputil::end(not_all), predicate));
}

TEST(TestRangeCheck, TestAnyOf)
{
    const integer_container empty;
    const integer_container any{ 0, 0, 1 };
    const integer_container not_any{ 0, 0, 0 };

    const auto predicate = [](int value) { return value == 1; };

    EXPECT_FALSE(cpputil::any_of(cpputil::begin(empty), cpputil::end(empty), predicate));
    EXPECT_TRUE(cpputil::any_of(cpputil::begin(any), cpputil::end(any), predicate));
    EXPECT_FALSE(cpputil::any_of(cpputil::begin(not_any), cpputil::end(not_any), predicate));
}

TEST(TestRangeCheck, TestNoneOf)
{
    integer_container empty;
    integer_container none{ 0, 0, 0 };
    integer_container not_none{ 0, 1, 0 };

    const auto predicate = [](int value) { return value == 1; };

    EXPECT_TRUE(cpputil::none_of(cpputil::begin(empty), cpputil::end(empty), predicate));
    EXPECT_TRUE(cpputil::none_of(cpputil::begin(none), cpputil::end(none), predicate));
    EXPECT_FALSE(cpputil::none_of(cpputil::begin(not_none), cpputil::end(not_none), predicate));
}

} // namespace test
