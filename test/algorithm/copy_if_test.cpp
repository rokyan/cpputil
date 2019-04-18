#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>

namespace test
{

TEST(CopyIfTest, TestCopyEmpty)
{
    integer_container empty;
    integer_container dest;

    cpputil::copy_if(empty.begin(), empty.end(), dest.begin(), [](int) { return true; });

    EXPECT_EQ(empty, dest);
}

TEST(CopyIfTest, TestCopyRanges)
{
    auto is_odd = [](int x) { return x % 2 == 1; };
    auto is_even = [](int x) { return x % 2 == 0; };

    {
        integer_container src{ 1 };

        {
            integer_container dest(1);
            integer_container expected{ 1 };

            cpputil::copy_if(src.begin(), src.end(), dest.begin(), is_odd);
            EXPECT_EQ(dest, expected);
        }

        {
            integer_container dest;
            integer_container expected;

            cpputil::copy_if(src.begin(), src.end(), dest.begin(), is_even);
            EXPECT_EQ(dest, expected);
        }
    }

    {
        integer_container src{ 1, 2 };

        {
            integer_container dest(1);
            integer_container expected{ 1 };

            cpputil::copy_if(src.begin(), src.end(), dest.begin(), is_odd);
            EXPECT_EQ(dest, expected);
        }

        {
            integer_container dest(1);
            integer_container expected{ 2 };

            cpputil::copy_if(src.begin(), src.end(), dest.begin(), is_even);
            EXPECT_EQ(dest, expected);
        }
    }

    {
        integer_container src{ 1, 2, 3, 4 };

        {
            integer_container dest(2);
            integer_container expected{ 1, 3 };

            cpputil::copy_if(src.begin(), src.end(), dest.begin(), is_odd);
            EXPECT_EQ(dest, expected);
        }

        {
            integer_container dest(2);
            integer_container expected{ 2, 4 };

            cpputil::copy_if(src.begin(), src.end(), dest.begin(), is_even);
            EXPECT_EQ(dest, expected);
        }
    }
}

} // namespace test