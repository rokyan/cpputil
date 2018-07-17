#include <gtest\gtest.h>
#include <traits.hpp>
#include <types.hpp>

namespace test
{
    TEST(traits_test, test_identity)
    {
        EXPECT_TRUE((traits::is_same_v<T0, traits::identity_t<T0>>));
    }

    TEST(traits_test, test_integral_constant)
    {
        using T = int;
        using integral_constant_t = traits::integral_constant<T, T{}>;

        EXPECT_EQ(integral_constant_t::value, T{});

        EXPECT_TRUE((traits::is_same_v<integral_constant_t::value_type, T>));
        EXPECT_TRUE((traits::is_same_v<integral_constant_t::type, integral_constant_t>));

        EXPECT_EQ(integral_constant_t{}(), T{});
        EXPECT_EQ(static_cast<T>(integral_constant_t{}), T{});
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

    TEST(traits_test, test_is_const)
    {
        EXPECT_FALSE(traits::is_const_v<T0>);
        EXPECT_FALSE(traits::is_const_v<volatile T0>);

        EXPECT_TRUE(traits::is_const_v<const T0>);
        EXPECT_TRUE(traits::is_const_v<const volatile T0>);
    }

    TEST(traits_test, test_is_volatile)
    {
        EXPECT_FALSE(traits::is_volatile_v<T0>);
        EXPECT_FALSE(traits::is_volatile_v<const T0>);

        EXPECT_TRUE(traits::is_volatile_v<volatile T0>);
        EXPECT_TRUE(traits::is_volatile_v<const volatile T0>);
    }

    TEST(traits_test, test_is_same)
    {
        EXPECT_TRUE((traits::is_same_v<T0, T0>));
        EXPECT_FALSE((traits::is_same_v<T0, T1>));
    }

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
}