#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::remove_const_t;

    TEST(traits_test, test_remove_const)
    {
        EXPECT_SAME_TYPES(T0, remove_const_t<T0>);
        EXPECT_SAME_TYPES(T0, remove_const_t<const T0>);
        EXPECT_SAME_TYPES(volatile T0, remove_const_t<volatile T0>);
        EXPECT_SAME_TYPES(volatile T0, remove_const_t<const volatile T0>);
    }
}