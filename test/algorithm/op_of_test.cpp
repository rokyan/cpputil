#include <gtest.hpp>
#include <algorithm.hpp>
#include <vector>

namespace test
{

TEST(TestOpOf, TestAllOf)
{
    using std::begin;
    using std::end;

    auto predicate = [](int value) { return value == 1; };

    std::vector<int> empty;
    std::vector<int> all{ 1, 1, 1 };
    std::vector<int> not_all{ 1, 0, 1 };

    EXPECT_TRUE(cpputil::all_of(begin(empty), end(empty), predicate));
    EXPECT_TRUE(cpputil::all_of(begin(all), end(all), predicate));
    EXPECT_FALSE(cpputil::all_of(begin(not_all), end(not_all), predicate));
}

TEST(TestOpOf, TestAnyOf)
{
    using std::begin;
    using std::end;

    auto predicate = [](int value) { return value == 1; };

    std::vector<int> empty;
    std::vector<int> any{ 0, 0, 1 };
    std::vector<int> not_any{ 0, 0, 0 };

    EXPECT_FALSE(cpputil::any_of(begin(empty), end(empty), predicate));
    EXPECT_TRUE(cpputil::any_of(begin(any), end(any), predicate));
    EXPECT_FALSE(cpputil::any_of(begin(not_any), end(not_any), predicate));
}

TEST(TestOpOf, TestNoneOf)
{
    using std::begin;
    using std::end;

    auto predicate = [](int value) { return value == 1; };

    std::vector<int> empty;
    std::vector<int> none{ 0, 0, 0 };
    std::vector<int> not_none{ 0, 1, 0 };

    EXPECT_TRUE(cpputil::none_of(begin(empty), end(empty), predicate));
    EXPECT_TRUE(cpputil::none_of(begin(none), end(none), predicate));
    EXPECT_FALSE(cpputil::none_of(begin(not_none), end(not_none), predicate));
}

} // namespace test
