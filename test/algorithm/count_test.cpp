#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>

namespace test
{

TEST(CountTest, TestEmptyRange)
{
    std::vector<int> data;
    auto predicate = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(cpputil::begin(data), cpputil::end(data), 1), 0);
    EXPECT_EQ(cpputil::count_if(cpputil::begin(data), cpputil::end(data), predicate), 0);
}

TEST(CountTest, TestCountingExistingElement)
{
    std::vector<int> data{ 2, 4, 1, 2, 1 };
    auto predicate = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(cpputil::begin(data), cpputil::end(data), 1), 2);
    EXPECT_EQ(cpputil::count_if(cpputil::begin(data), cpputil::end(data), predicate), 2);
}

TEST(CountTest, TestCountingNonExistingElement)
{
    std::vector<int> data{ 2, 4, 2 };
    auto predicate = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::count(cpputil::begin(data), cpputil::end(data), 1), 0);
    EXPECT_EQ(cpputil::count_if(cpputil::begin(data), cpputil::end(data), predicate), 0);
}

} // namespace test
