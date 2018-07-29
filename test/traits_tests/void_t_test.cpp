#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::void_t;

    TEST(traits_test, test_void_t)
    {
        using zero_types_t = void_t<>;
        SAME_TYPES(void, zero_types_t);

        using single_types_t = void_t<T0>;
        SAME_TYPES(void, single_types_t);

        using multiple_types_t = void_t<T0, T1>;
        SAME_TYPES(void, multiple_types_t);
    }
}