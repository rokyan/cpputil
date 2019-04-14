#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(IsLvalueReferenceTest, TestIsLvalueReference)
{
    EXPECT_TRUE(cpputil::is_lvalue_reference_v<T0&>);
    EXPECT_TRUE(cpputil::is_lvalue_reference_v<const T0&>);
    EXPECT_TRUE(cpputil::is_lvalue_reference_v<volatile T0&>);
    EXPECT_TRUE(cpputil::is_lvalue_reference_v<const volatile T0&>);
}

} // namespace test