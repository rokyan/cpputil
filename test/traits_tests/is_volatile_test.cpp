#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::is_volatile_v;

    TEST(traits_test, test_is_volatile)
    {
        EXPECT_FALSE(is_volatile_v<T0>);
        EXPECT_FALSE(is_volatile_v<const T0>);

        EXPECT_TRUE(is_volatile_v<volatile T0>);
        EXPECT_TRUE(is_volatile_v<const volatile T0>);
    }
}