#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(IsVoidTest, TestIsVoid)
{
    EXPECT_TRUE(cpputil::is_void_v<void>);
    EXPECT_TRUE(cpputil::is_void_v<const void>);
    EXPECT_TRUE(cpputil::is_void_v<volatile void>);
    EXPECT_TRUE(cpputil::is_void_v<const volatile void>);
}

} // namespace test