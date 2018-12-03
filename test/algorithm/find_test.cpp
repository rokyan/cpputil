#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>
#include <iterator_operations.hpp>

namespace test
{

TEST(FindTest, TestEmptyRange)
{
    const integer_container data;

    const auto pred = [](int value) { return value == 1; };

    EXPECT_EQ(cpputil::find(cpputil::begin(data), cpputil::end(data), 1),
        cpputil::end(data));
    EXPECT_EQ(cpputil::find_if(cpputil::begin(data), cpputil::end(data), pred),
        cpputil::end(data));
    EXPECT_EQ(cpputil::find_if_not(cpputil::begin(data), cpputil::end(data), pred),
        cpputil::end(data));
}

TEST(FindTest, TestLookingForExistingElement)
{
    const integer_container data{ 2, 4, 1, 2, 1 };

    const auto pred = [](int value) { return value == 1; };
    const auto negative_pred = [](int value) { return value != 1; };

    EXPECT_EQ(cpputil::find(cpputil::begin(data), cpputil::end(data), 1),
        cpputil::next(cpputil::begin(data), 2));
    EXPECT_EQ(cpputil::find_if(cpputil::begin(data), cpputil::end(data), pred),
        cpputil::next(cpputil::begin(data), 2));
    EXPECT_EQ(cpputil::find_if_not(cpputil::begin(data), cpputil::end(data), negative_pred),
        cpputil::next(cpputil::begin(data), 2));
}

TEST(FindTest, TestLookingForNonExistingElement)
{
    const integer_container data{ 2, 4, 2 };

    const auto pred = [](int value) { return value == 1; };
    const auto negative_pred = [](int value) { return value != 1; };

    EXPECT_EQ(cpputil::find(cpputil::begin(data), cpputil::end(data), 1),
        cpputil::end(data));
    EXPECT_EQ(cpputil::find_if(cpputil::begin(data), cpputil::end(data), pred),
        cpputil::end(data));
    EXPECT_EQ(cpputil::find_if_not(cpputil::begin(data), cpputil::end(data), negative_pred),
        cpputil::end(data));
}

} // namespace test
