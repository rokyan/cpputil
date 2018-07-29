#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::remove_reference_t;

    TEST(traits_test, test_remove_reference)
    {
        SAME_TYPES(remove_reference_t<T0>, T0);
        SAME_TYPES(remove_reference_t<T0&>, T0);
        SAME_TYPES(remove_reference_t<T0&&>, T0);
    }
}