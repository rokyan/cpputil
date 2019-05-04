#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(MoveTest, TestMoveEmpty)
{
    integer_container empty;
    integer_container dest;

    const auto it = cpputil::move(empty.begin(), empty.end(), dest.begin());

    EXPECT_EQ(empty, dest);
    EXPECT_EQ(it, dest.end());
}

TEST(MoveTest, TestMoveRanges)
{
    {
        integer_container src{ 1 };
        integer_container dest(1);

        const auto it = cpputil::move(src.begin(), src.end(), dest.begin());

        EXPECT_EQ(src, dest);
        EXPECT_EQ(it, dest.end());
    }

    {
        integer_container src{ 1, 2 };
        integer_container dest(2);

        const auto it = cpputil::move(src.begin(), src.end(), dest.begin());

        EXPECT_EQ(src, dest);
        EXPECT_EQ(it, dest.end());
    }

    {
        integer_container src{ 1, 2, 3, 4 };
        integer_container dest(4);

        const auto it = cpputil::move(src.begin(), src.end(), dest.begin());

        EXPECT_EQ(src, dest);
        EXPECT_EQ(it, dest.end());
    }
}

} // namespace test