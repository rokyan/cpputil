#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using traits::is_volatile_v;

TEST(TraitsTest, TestIsVolatile)
{
    EXPECT_FALSE(is_volatile_v<T0>);
    EXPECT_FALSE(is_volatile_v<const T0>);

    EXPECT_TRUE(is_volatile_v<volatile T0>);
    EXPECT_TRUE(is_volatile_v<const volatile T0>);
}

} // namespace test
