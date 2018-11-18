#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using traits::add_volatile_t;

TEST(TraitsTest, TestAddVolatile)
{
    EXPECT_SAME_TYPES(volatile T0, add_volatile_t<T0>);
    EXPECT_SAME_TYPES(volatile T0, add_volatile_t<volatile T0>);
    EXPECT_SAME_TYPES(const volatile T0, add_volatile_t<const T0>);
    EXPECT_SAME_TYPES(const volatile T0, add_volatile_t<const volatile T0>);
}

} // namespace test
