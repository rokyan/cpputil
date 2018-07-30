#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::add_const_t;

    TEST(traits_test, test_add_const)
    {
        EXPECT_SAME_TYPES(const T0, add_const_t<T0>);
        EXPECT_SAME_TYPES(const T0, add_const_t<const T0>);
        EXPECT_SAME_TYPES(const volatile T0, add_const_t<volatile T0>);
        EXPECT_SAME_TYPES(const volatile T0, add_const_t<const volatile T0>);
    }
}