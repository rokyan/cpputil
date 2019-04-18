#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(CopyTest, TestCopyEmpty)
{
    integer_container empty;
    integer_container dest;

    cpputil::copy(empty.begin(), empty.end(), dest.begin());

    EXPECT_EQ(empty, dest);
}

TEST(CopyTest, TestCopyRanges)
{
    {
        integer_container src{ 1 };
        integer_container dest(1);

        cpputil::copy(src.begin(), src.end(), dest.begin());

        EXPECT_EQ(src, dest);
    }

    {
        integer_container src{ 1, 2 };
        integer_container dest(2);

        cpputil::copy(src.begin(), src.end(), dest.begin());

        EXPECT_EQ(src, dest);
    }

    {
        integer_container src{ 1, 2, 3, 4 };
        integer_container dest(4);

        cpputil::copy(src.begin(), src.end(), dest.begin());

        EXPECT_EQ(src, dest);
    }
}

} // namespace test