#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(IsRvalueReferenceTest, TestIsRvalueReference)
{
    EXPECT_TRUE(cpputil::is_rvalue_reference_v<T0&&>);
    EXPECT_TRUE(cpputil::is_rvalue_reference_v<const T0&&>);
    EXPECT_TRUE(cpputil::is_rvalue_reference_v<volatile T0&&>);
    EXPECT_TRUE(cpputil::is_rvalue_reference_v<const volatile T0&&>);
}

} // namespace test