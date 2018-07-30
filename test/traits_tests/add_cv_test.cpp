#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::add_cv_t;

    TEST(traits_test, test_add_cv)
    {
        EXPECT_SAME_TYPES(const volatile T0, add_cv_t<T0>);
        EXPECT_SAME_TYPES(const volatile T0, add_cv_t<const T0>);
        EXPECT_SAME_TYPES(const volatile T0, add_cv_t<volatile T0>);
        EXPECT_SAME_TYPES(const volatile T0, add_cv_t<const volatile T0>);
    }
}