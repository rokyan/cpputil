#include <gtest\gtest.h>
#include <traits.hpp>
#include <types.hpp>

namespace test
{
    // helper class.

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

    // primary type categories.

    TEST(traits_test, test_is_array)
    {
        EXPECT_TRUE(traits::is_array_v<T0[]>);
        EXPECT_TRUE(traits::is_array_v<T0[1]>);

        EXPECT_TRUE(traits::is_array_v<T0[][2]>);
        EXPECT_TRUE(traits::is_array_v<T0[1][2]>);
    }

    // type properties.

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

    // type relations.

    TEST(traits_test, test_is_same)
    {
        EXPECT_TRUE((traits::is_same_v<T0, T0>));
        EXPECT_FALSE((traits::is_same_v<T0, T1>));
    }

    // const-volatile modifications.

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

    // reference modifications.

    TEST(traits_test, test_remove_reference)
    {
        EXPECT_TRUE((traits::is_same_v<T0, T0>));
        EXPECT_TRUE((traits::is_same_v<traits::remove_reference_t<T0&>, T0>));
        EXPECT_TRUE((traits::is_same_v<traits::remove_reference_t<T0&&>, T0>));
    }

    // array modifications.

    TEST(traits_test, test_remove_extent)
    {
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_extent_t<T0[]>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_extent_t<T0[1]>>));

        EXPECT_TRUE((traits::is_same_v<T0[2], traits::remove_extent_t<T0[][2]>>));
        EXPECT_TRUE((traits::is_same_v<T0[2], traits::remove_extent_t<T0[1][2]>>));
    }

    // pointer modifications.

    TEST(traits_test, test_remove_pointer)
    {
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_pointer_t<T0*>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_pointer_t<T0* const>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_pointer_t<T0* volatile>>));
        EXPECT_TRUE((traits::is_same_v<T0, traits::remove_pointer_t<T0* const volatile>>));
    }

    TEST(traits_test, test_add_pointer)
    {
        EXPECT_TRUE((traits::is_same_v<T0*, traits::add_pointer_t<T0>>));
        EXPECT_TRUE((traits::is_same_v<const T0*, traits::add_pointer_t<const T0>>));
        EXPECT_TRUE((traits::is_same_v<volatile T0*, traits::add_pointer_t<volatile T0>>));
        EXPECT_TRUE((traits::is_same_v<const volatile T0*, traits::add_pointer_t<const volatile T0>>));

        EXPECT_TRUE((traits::is_same_v<T0*, traits::add_pointer_t<T0&>>));
        EXPECT_TRUE((traits::is_same_v<const T0*, traits::add_pointer_t<const T0&>>));
        EXPECT_TRUE((traits::is_same_v<volatile T0*, traits::add_pointer_t<volatile T0&>>));
        EXPECT_TRUE((traits::is_same_v<const volatile T0*, traits::add_pointer_t<const volatile T0&>>));
    }

    // other transformations.

    TEST(traits_test, test_void_t)
    {
        EXPECT_TRUE((traits::is_same_v<void, traits::void_t<T0>>));
        EXPECT_TRUE((traits::is_same_v<void, traits::void_t<T0, T1>>));
        EXPECT_TRUE((traits::is_same_v<void, traits::void_t<T0, T1, T2>>));
        EXPECT_TRUE((traits::is_same_v<void, traits::void_t<T0, T1, T2, T3>>));
    }

    // helper traits and traits which are not specified in the standard.

    TEST(traits_test, test_identity)
    {
        EXPECT_TRUE((traits::is_same_v<T0, traits::identity_t<T0>>));
    }

    TEST(traits_test, test_is_referenceable)
    {
        EXPECT_TRUE(traits::is_referenceable_v<int>);
        EXPECT_TRUE(traits::is_referenceable_v<int&>);
        EXPECT_TRUE(traits::is_referenceable_v<int&&>);
        EXPECT_TRUE(traits::is_referenceable_v<int*>);
        EXPECT_TRUE(traits::is_referenceable_v<int[]>);
        EXPECT_TRUE(traits::is_referenceable_v<int(&)[]>);
        EXPECT_TRUE(traits::is_referenceable_v<int(&&)[]>);
        EXPECT_TRUE(traits::is_referenceable_v<int(*)[]>);
        EXPECT_TRUE(traits::is_referenceable_v<int()>);
        EXPECT_TRUE(traits::is_referenceable_v<int(&)()>);
        EXPECT_TRUE(traits::is_referenceable_v<int(&&)()>);
        EXPECT_TRUE(traits::is_referenceable_v<int(*)()>);

        EXPECT_FALSE(traits::is_referenceable_v<void>);
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