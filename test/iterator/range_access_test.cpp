#include <gtest.hpp>
#include <range_access.hpp>
#include "range_mocks.hpp"

namespace test
{

using cpputil::begin;
using cpputil::cbegin;
using cpputil::rbegin;
using cpputil::crbegin;

using cpputil::end;
using cpputil::cend;
using cpputil::rend;
using cpputil::crend;

TEST(RangeAccessTest, TestBegin)
{
    integer_range_mock rm(0, 1);
    const integer_range_mock crm(0, 1);

    EXPECT_SAME_TYPES(decltype(begin(rm)), integer_range_mock::iterator) <<
        "Wrong type produced by begin function";
    EXPECT_SAME_TYPES(decltype(begin(crm)), integer_range_mock::const_iterator) <<
        "Wrong type produced by begin function";
    EXPECT_SAME_TYPES(decltype(cbegin(rm)), integer_range_mock::const_iterator) <<
        "Wrong type produced by cbegin function";
    EXPECT_SAME_TYPES(decltype(cbegin(crm)), integer_range_mock::const_iterator) <<
        "Wrong type produced by cbegin function";

    EXPECT_EQ(begin(rm), 0) <<
        "Wrong value produced by begin function";
    EXPECT_EQ(begin(crm), 0) <<
        "Wrong value produced by begin function";
    EXPECT_EQ(cbegin(rm), 0) <<
        "Wrong value produced by cbegin function";
    EXPECT_EQ(cbegin(crm), 0) <<
        "Wrong value produced by cbegin function";
}

TEST(RangeAccessTest, TestBeginForArrays)
{
    int arr[] = { 0, 1 };
    const int carr[] = { 0, 1 };

    EXPECT_SAME_TYPES(decltype(begin(arr)), int*) <<
        "Wrong type produced by begin function";
    EXPECT_SAME_TYPES(decltype(begin(carr)), const int*) <<
        "Wrong type produced by begin function";
    EXPECT_SAME_TYPES(decltype(cbegin(arr)), const int*) <<
        "Wrong type produced by cbegin function";
    EXPECT_SAME_TYPES(decltype(cbegin(carr)), const int*) <<
        "Wrong type produced by cbegin function";

    EXPECT_EQ(begin(arr), arr) <<
        "Wrong value produced by begin function";
    EXPECT_EQ(begin(carr), carr) <<
        "Wrong value produced by begin function";
    EXPECT_EQ(cbegin(arr), arr) <<
        "Wrong value produced by cbegin function";
    EXPECT_EQ(cbegin(carr), carr) <<
        "Wrong value produced by cbegin function";
}

TEST(RangeAccessTest, TestReverseBegin)
{
    integer_range_mock rm(0, 1);
    const integer_range_mock crm(0, 1);

    EXPECT_SAME_TYPES(decltype(rbegin(rm)), integer_range_mock::reverse_iterator) <<
        "Wrong type produced by rbegin function";
    EXPECT_SAME_TYPES(decltype(rbegin(crm)), integer_range_mock::const_reverse_iterator) <<
        "Wrong type produced by rbegin function";
    EXPECT_SAME_TYPES(decltype(crbegin(rm)), integer_range_mock::const_reverse_iterator) <<
        "Wrong type produced by crbegin function";
    EXPECT_SAME_TYPES(decltype(crbegin(crm)), integer_range_mock::const_reverse_iterator) <<
        "Wrong type produced by crbegin function";

    EXPECT_EQ(rbegin(rm), 1) <<
        "Wrong value produced by rbegin function";
    EXPECT_EQ(rbegin(crm), 1) <<
        "Wrong value produced by rbegin function";
    EXPECT_EQ(crbegin(rm), 1) <<
        "Wrong value produced by crbegin function";
    EXPECT_EQ(crbegin(crm), 1) <<
        "Wrong value produced by crbegin function";
}

TEST(RangeAccessTest, TestReverseBeginForArrays)
{
    int arr[] = { 0, 1 };
    const int carr[] = { 0, 1 };

    EXPECT_SAME_TYPES(decltype(rbegin(arr)), std::reverse_iterator<int*>) <<
        "Wrong type produced by rbegin function";
    EXPECT_SAME_TYPES(decltype(rbegin(carr)), std::reverse_iterator<const int*>) <<
        "Wrong type produced by rbegin function";
    EXPECT_SAME_TYPES(decltype(crbegin(arr)), std::reverse_iterator<const int*>) <<
        "Wrong type produced by crbegin function";
    EXPECT_SAME_TYPES(decltype(crbegin(carr)), std::reverse_iterator<const int*>) <<
        "Wrong type produced by crbegin function";
}

TEST(RangeAccessTest, TestEnd)
{
    integer_range_mock rm(0, 1);
    const integer_range_mock crm(0, 1);

    EXPECT_SAME_TYPES(decltype(end(rm)), integer_range_mock::iterator) <<
        "Wrong type produced by end function";
    EXPECT_SAME_TYPES(decltype(end(crm)), integer_range_mock::const_iterator) <<
        "Wrong type produced by end function";
    EXPECT_SAME_TYPES(decltype(cend(rm)), integer_range_mock::const_iterator) <<
        "Wrong type produced by cend function";
    EXPECT_SAME_TYPES(decltype(cend(crm)), integer_range_mock::const_iterator) <<
        "Wrong type produced by cend function";

    EXPECT_EQ(end(rm), 1) <<
        "Wrong value produced by end function";
    EXPECT_EQ(end(crm), 1) <<
        "Wrong value produced by end function";
    EXPECT_EQ(cend(rm), 1) <<
        "Wrong value produced by cend function";
    EXPECT_EQ(cend(crm), 1) <<
        "Wrong value produced by cend function";
}

TEST(RangeAccessTest, TestEndForArrays)
{
    int arr[] = { 0, 1 };
    const int carr[] = { 0, 1 };

    const std::size_t arr_size = 2U;

    EXPECT_SAME_TYPES(decltype(end(arr)), int*) <<
        "Wrong type produced by end function";
    EXPECT_SAME_TYPES(decltype(end(carr)), const int*) <<
        "Wrong type produced by end function";
    EXPECT_SAME_TYPES(decltype(cend(arr)), const int*) <<
        "Wrong type produced by cend function";
    EXPECT_SAME_TYPES(decltype(cend(carr)), const int*) <<
        "Wrong type produced by cend function";

    EXPECT_EQ(end(arr), arr + arr_size) <<
        "Wrong value produced by end function";
    EXPECT_EQ(end(carr), carr + arr_size) <<
        "Wrong value produced by end function";
    EXPECT_EQ(cend(arr), arr + arr_size) <<
        "Wrong value produced by cend function";
    EXPECT_EQ(cend(carr), carr + arr_size) <<
        "Wrong value produced by cend function";
}

TEST(RangeAccessTest, TestReverseEnd)
{
    integer_range_mock rm(0, 1);
    const integer_range_mock crm(0, 1);

    EXPECT_SAME_TYPES(decltype(rend(rm)), integer_range_mock::reverse_iterator) <<
        "Wrong type produced by rend function";
    EXPECT_SAME_TYPES(decltype(rend(crm)), integer_range_mock::const_reverse_iterator) <<
        "Wrong type produced by rend function";
    EXPECT_SAME_TYPES(decltype(crend(rm)), integer_range_mock::const_reverse_iterator) <<
        "Wrong type produced by crend function";
    EXPECT_SAME_TYPES(decltype(crend(crm)), integer_range_mock::const_reverse_iterator) <<
        "Wrong type produced by crend function";

    EXPECT_EQ(rend(rm), 0) <<
        "Wrong value produced by rend function";
    EXPECT_EQ(rend(crm), 0) <<
        "Wrong value produced by rend function";
    EXPECT_EQ(crend(rm), 0) <<
        "Wrong value produced by crend function";
    EXPECT_EQ(crend(crm), 0) <<
        "Wrong value produced by crend function";
}

TEST(RangeAccessTest, TestReverseEndForArrays)
{
    int arr[] = { 0, 1 };
    const int carr[] = { 0, 1 };

    EXPECT_SAME_TYPES(decltype(rend(arr)), std::reverse_iterator<int*>) <<
        "Wrong type produced by rend function";
    EXPECT_SAME_TYPES(decltype(rend(carr)), std::reverse_iterator<const int*>) <<
        "Wrong type produced by rend function";
    EXPECT_SAME_TYPES(decltype(crend(arr)), std::reverse_iterator<const int*>) <<
        "Wrong type produced by crend function";
    EXPECT_SAME_TYPES(decltype(crend(carr)), std::reverse_iterator<const int*>) <<
        "Wrong type produced by crend function";
}

} // namespace test
