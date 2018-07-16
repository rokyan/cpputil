#include <gtest\gtest.h>
#include <traits.hpp>
#include <types.hpp>

namespace test
{
    TEST(traits_test, test_is_contained_in)
    {
        EXPECT_TRUE((traits::is_contained_in_v<T0, T0>));
        EXPECT_TRUE((traits::is_contained_in_v<T0, T0, T1>));
        EXPECT_TRUE((traits::is_contained_in_v<T0, T0, T1, T2>));

        EXPECT_FALSE((traits::is_contained_in_v<T0>));
        EXPECT_FALSE((traits::is_contained_in_v<T0, T1>));
        EXPECT_FALSE((traits::is_contained_in_v<T0, T1, T2>));
        EXPECT_FALSE((traits::is_contained_in_v<T0, T1, T2, T3>));
    }

    TEST(traits_test, test_remove_const)
    {
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_const_t<T0>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_const_t<const T0>>));
        EXPECT_TRUE((traits::is_same_v<volatile T0, traits::remove_const_t<volatile T0>>));
        EXPECT_TRUE((traits::is_same_v<volatile T0, traits::remove_const_t<const volatile T0>>));
    }

    TEST(traits_test, test_remove_volatile)
    {
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_volatile_t<T0>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_volatile_t<volatile T0>>));
        EXPECT_TRUE((traits::is_same_v<const T0, traits::remove_volatile_t<const T0>>));
        EXPECT_TRUE((traits::is_same_v<const T0, traits::remove_volatile_t<const volatile T0>>));
    }

    TEST(traits_test, test_remove_cv)
    {
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_cv_t<T0>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_cv_t<const T0>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_cv_t<volatile T0>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_cv_t<const volatile T0>>));
    }
}