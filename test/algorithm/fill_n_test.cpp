#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(FillNTest, TestFillNEmpty)
{
    integer_container empty;
    integer_container expected;

    cpputil::fill_n(empty.begin(), 0, 1);

    EXPECT_EQ(empty, expected);
}

TEST(FillNTest, TestFillNEmptyRanges)
{
    {
        integer_container src(1);
        integer_container expected(1, 1);

        cpputil::fill_n(src.begin(), 1, 1);

        EXPECT_EQ(src, expected);
    }

    {
        integer_container src(2);
        integer_container expected(2, 1);

        cpputil::fill_n(src.begin(), 2, 1);

        EXPECT_EQ(src, expected);
    }

    {
        integer_container src(4);
        integer_container expected(4, 1);

        cpputil::fill_n(src.begin(), 4, 1);

        EXPECT_EQ(src, expected);
    }
}

} // namespace test