#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>

namespace test
{

TEST(TestOpOf, TestAllOf)
{
    auto predicate = [](int value) { return value == 1; };

    std::vector<int> empty;
    std::vector<int> all{ 1, 1, 1 };
    std::vector<int> not_all{ 1, 0, 1 };

    EXPECT_TRUE(cpputil::all_of(cpputil::begin(empty), cpputil::end(empty), predicate));
    EXPECT_TRUE(cpputil::all_of(cpputil::begin(all), cpputil::end(all), predicate));
    EXPECT_FALSE(cpputil::all_of(cpputil::begin(not_all), cpputil::end(not_all), predicate));
}

TEST(TestOpOf, TestAnyOf)
{
    auto predicate = [](int value) { return value == 1; };

    std::vector<int> empty;
    std::vector<int> any{ 0, 0, 1 };
    std::vector<int> not_any{ 0, 0, 0 };

    EXPECT_FALSE(cpputil::any_of(cpputil::begin(empty), cpputil::end(empty), predicate));
    EXPECT_TRUE(cpputil::any_of(cpputil::begin(any), cpputil::end(any), predicate));
    EXPECT_FALSE(cpputil::any_of(cpputil::begin(not_any), cpputil::end(not_any), predicate));
}

TEST(TestOpOf, TestNoneOf)
{
    auto predicate = [](int value) { return value == 1; };

    std::vector<int> empty;
    std::vector<int> none{ 0, 0, 0 };
    std::vector<int> not_none{ 0, 1, 0 };

    EXPECT_TRUE(cpputil::none_of(cpputil::begin(empty), cpputil::end(empty), predicate));
    EXPECT_TRUE(cpputil::none_of(cpputil::begin(none), cpputil::end(none), predicate));
    EXPECT_FALSE(cpputil::none_of(cpputil::begin(not_none), cpputil::end(not_none), predicate));
}

} // namespace test
