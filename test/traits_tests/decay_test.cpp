#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    using traits::decay_t;

    TEST(traits_test, test_reference_decay)
    {
        EXPECT_SAME_TYPES(T0, decay_t<T0>);
        EXPECT_SAME_TYPES(T0, decay_t<T0&>);
        EXPECT_SAME_TYPES(T0, decay_t<T0&&>);
    }

    TEST(traits_test, test_cv_decay)
    {
        EXPECT_SAME_TYPES(T0, decay_t<T0>);
        EXPECT_SAME_TYPES(T0, decay_t<const T0>);
        EXPECT_SAME_TYPES(T0, decay_t<volatile T0>);
        EXPECT_SAME_TYPES(T0, decay_t<const volatile T0>);
    }

    TEST(traits_test, test_cv_reference_decay)
    {
        EXPECT_SAME_TYPES(T0, decay_t<T0&>);
        EXPECT_SAME_TYPES(T0, decay_t<const T0&>);
        EXPECT_SAME_TYPES(T0, decay_t<volatile T0&>);
        EXPECT_SAME_TYPES(T0, decay_t<const volatile T0&>);

        EXPECT_SAME_TYPES(T0, decay_t<T0&&>);
        EXPECT_SAME_TYPES(T0, decay_t<const T0&&>);
        EXPECT_SAME_TYPES(T0, decay_t<volatile T0&&>);
        EXPECT_SAME_TYPES(T0, decay_t<const volatile T0&&>);
    }

    TEST(traits_test, test_function_decay)
    {
        EXPECT_SAME_TYPES(T0(*)(), decay_t<T0()>);
        EXPECT_SAME_TYPES(T0(*)(T1), decay_t<T0(T1)>);
    }

    TEST(traits_test, test_array_decay)
    {
        EXPECT_SAME_TYPES(T0*, decay_t<T0[]>);
        EXPECT_SAME_TYPES(T0*, decay_t<T0[1]>);
        EXPECT_SAME_TYPES(T0(*)[1], decay_t<T0[][1]>);
        EXPECT_SAME_TYPES(T0(*)[1], decay_t<T0[1][1]>);
    }
}