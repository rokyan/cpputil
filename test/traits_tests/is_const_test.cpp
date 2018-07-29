#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::is_const_v;

    TEST(traits_test, test_is_const)
    {
        EXPECT_FALSE(is_const_v<T0>);
        EXPECT_FALSE(is_const_v<volatile T0>);

        EXPECT_TRUE(is_const_v<const T0>);
        EXPECT_TRUE(is_const_v<const volatile T0>);
    }
}