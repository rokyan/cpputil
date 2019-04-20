#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(CopyNTest, TestCopyEmpty)
{
    integer_container empty;
    integer_container dest;

    cpputil::copy_n(empty.begin(), 0, dest.begin());

    EXPECT_EQ(empty, dest);
}

TEST(CopyNTest, TestCopyRanges)
{
    {
        integer_container src{ 1 };
        integer_container dest(1);

        cpputil::copy_n(src.begin(), 1, dest.begin());

        EXPECT_EQ(src, dest);
    }

    {
        integer_container src{ 1, 2 };
        integer_container dest(2);

        cpputil::copy_n(src.begin(), 2, dest.begin());

        EXPECT_EQ(src, dest);
    }

    {
        integer_container src{ 1, 2, 3, 4 };
        integer_container dest(4);

        cpputil::copy_n(src.begin(), 4, dest.begin());

        EXPECT_EQ(src, dest);
    }
}

} // namespace testt.hpp>