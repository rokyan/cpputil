#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::remove_pointer_t;

    TEST(traits_test, test_remove_pointer)
    {
        SAME_TYPES(T0, remove_pointer_t<T0*>);
        SAME_TYPES(T0, remove_pointer_t<T0* const>);
        SAME_TYPES(T0, remove_pointer_t<T0* volatile>);
        SAME_TYPES(T0, remove_pointer_t<T0* const volatile>);
    }
}