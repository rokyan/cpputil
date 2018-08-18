#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    using traits::add_pointer_t;

    TEST(traits_test, test_add_pointer)
    {
        EXPECT_SAME_TYPES(T0*, add_pointer_t<T0>);
        EXPECT_SAME_TYPES(const T0*, add_pointer_t<const T0>);
        EXPECT_SAME_TYPES(volatile T0*, add_pointer_t<volatile T0>);
        EXPECT_SAME_TYPES(const volatile T0*, add_pointer_t<const volatile T0>);

        EXPECT_SAME_TYPES(T0*, add_pointer_t<T0&>);
        EXPECT_SAME_TYPES(const T0*, add_pointer_t<const T0&>);
        EXPECT_SAME_TYPES(volatile T0*, add_pointer_t<volatile T0&>);
        EXPECT_SAME_TYPES(const volatile T0*, add_pointer_t<const volatile T0&>);

        EXPECT_SAME_TYPES(T0*, add_pointer_t<T0&&>);
        EXPECT_SAME_TYPES(const T0*, add_pointer_t<const T0&&>);
        EXPECT_SAME_TYPES(volatile T0*, add_pointer_t<volatile T0&&>);
        EXPECT_SAME_TYPES(const volatile T0*, add_pointer_t<const volatile T0&&>);
    }
}