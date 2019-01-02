#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::extent_v;

TEST(ExtentTest, TestExtent)
{
    EXPECT_EQ(extent_v<int>, 0);

    EXPECT_EQ(extent_v<int[]>, 0);
    EXPECT_EQ((extent_v<int[], 1>), 0);

    EXPECT_EQ(extent_v<int[1]>, 1);
    EXPECT_EQ((extent_v<int[1], 1>), 0);

    EXPECT_EQ(extent_v<int[][1]>, 0);
    EXPECT_EQ((extent_v<int[][1], 1>), 1);
    EXPECT_EQ((extent_v<int[][1], 2>), 0);

    EXPECT_EQ(extent_v<int[1][2]>, 1);
    EXPECT_EQ((extent_v<int[1][2], 1>), 2);
    EXPECT_EQ((extent_v<int[1][2], 2>), 0);
}

} // namespace test