#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(IsNullPointerTest, TestIsNullPointer)
{
    EXPECT_TRUE(cpputil::is_null_pointer_v<std::nullptr_t>);
    EXPECT_TRUE(cpputil::is_null_pointer_v<const std::nullptr_t>);
    EXPECT_TRUE(cpputil::is_null_pointer_v<volatile std::nullptr_t>);
    EXPECT_TRUE(cpputil::is_null_pointer_v<const volatile std::nullptr_t>);
}

} // namespace test