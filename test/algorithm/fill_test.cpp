#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(FillTest, TestFillEmpty)
{
    integer_container empty;
    integer_container expected;

    cpputil::fill(RANGE(empty), 1);

    EXPECT_EQ(empty, expected);
}

TEST(FillTest, TestFillEmptyRanges)
{
    {
        integer_container src(1);
        integer_container expected(1, 1);

        cpputil::fill(RANGE(src), 1);

        EXPECT_EQ(src, expected);
    }

    {
        integer_container src(2);
        integer_container expected(2, 1);

        cpputil::fill(RANGE(src), 1);

        EXPECT_EQ(src, expected);
    }

    {
        integer_container src(4);
        integer_container expected(4, 1);

        cpputil::fill(RANGE(src), 1);

        EXPECT_EQ(src, expected);
    }
}

} // namespace test