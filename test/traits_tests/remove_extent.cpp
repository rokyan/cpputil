#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::remove_extent_t;

    TEST(traits_test, test_remove_extent)
    {
        SAME_TYPES(T0, remove_extent_t<T0[]>);
        SAME_TYPES(T0, remove_extent_t<T0[1]>);

        SAME_TYPES(T0[2], remove_extent_t<T0[][2]>);
        SAME_TYPES(T0[2], remove_extent_t<T0[1][2]>);
    }
}