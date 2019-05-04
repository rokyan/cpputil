#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(MoveBackwardTest, TestMoveBackwardEmpty)
{
    integer_container empty;
    integer_container dest;

    cpputil::move_backward(empty.begin(), empty.end(), dest.end());

    EXPECT_EQ(empty, dest);
}

TEST(MoveBackwardTest, TestMoveRanges)
{
    {
        integer_container src{ 1 };
        integer_container dest(1);

        cpputil::move_backward(src.begin(), src.end(), dest.end());

        EXPECT_EQ(src, dest);
    }

    {
        integer_container src{ 1, 2 };
        integer_container dest(2);

        cpputil::move_backward(src.begin(), src.end(), dest.end());

        EXPECT_EQ(src, dest);
    }

    {
        integer_container src{ 1, 2, 3, 4 };
        integer_container dest(4);

        cpputil::move_backward(src.begin(), src.end(), dest.end());

        EXPECT_EQ(src, dest);
    }
}

} // namespace test