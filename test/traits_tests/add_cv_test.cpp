#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::add_cv_t;

    TEST(traits_test, test_add_cv)
    {
        SAME_TYPES(const volatile T0, add_cv_t<T0>);
        SAME_TYPES(const volatile T0, add_cv_t<const T0>);
        SAME_TYPES(const volatile T0, add_cv_t<volatile T0>);
        SAME_TYPES(const volatile T0, add_cv_t<const volatile T0>);
    }
}