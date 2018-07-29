#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::remove_volatile_t;

    TEST(traits_test, test_remove_volatile)
    {
        SAME_TYPES(T0, remove_volatile_t<T0>);
        SAME_TYPES(T0, remove_volatile_t<volatile T0>);
        SAME_TYPES(const T0, remove_volatile_t<const T0>);
        SAME_TYPES(const T0, remove_volatile_t<const volatile T0>);
    }
}