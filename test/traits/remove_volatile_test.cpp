#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    using traits::remove_volatile_t;

    TEST(TraitsTest, TestRemoveVolatile)
    {
        EXPECT_SAME_TYPES(T0, remove_volatile_t<T0>);
        EXPECT_SAME_TYPES(T0, remove_volatile_t<volatile T0>);
        EXPECT_SAME_TYPES(const T0, remove_volatile_t<const T0>);
        EXPECT_SAME_TYPES(const T0, remove_volatile_t<const volatile T0>);
    }
}