#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::remove_cv_t;

    TEST(traits_test, test_remove_cv)
    {
        SAME_TYPES(T0, remove_cv_t<T0>);
        SAME_TYPES(T0, remove_cv_t<const T0>);
        SAME_TYPES(T0, remove_cv_t<volatile T0>);
        SAME_TYPES(T0, remove_cv_t<const volatile T0>);
    }
}