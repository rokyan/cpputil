#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(IsUnboundArrayTest, TestBoundArray)
{
    EXPECT_FALSE(cpputil::is_unbounded_array_v<int[1]>);
    EXPECT_FALSE(cpputil::is_unbounded_array_v<int[1][2]>);
}

TEST(IsUnboundArrayTest, TestUnboundArray)
{
    EXPECT_TRUE(cpputil::is_unbounded_array_v<int[]>);
    EXPECT_TRUE(cpputil::is_unbounded_array_v<int[][1]>);
}

} // namespace test