#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(IsBoundArrayTest, TestBoundArray)
{
    EXPECT_TRUE(cpputil::is_bounded_array_v<int[1]>);
    EXPECT_TRUE(cpputil::is_bounded_array_v<int[1][2]>);
}

TEST(IsBoundArrayTest, TestUnboundArray)
{
    EXPECT_FALSE(cpputil::is_bounded_array_v<int[]>);
    EXPECT_FALSE(cpputil::is_bounded_array_v<int[][1]>);
}

} // namespace test