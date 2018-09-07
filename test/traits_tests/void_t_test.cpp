#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    using traits::void_t;

    TEST(TraitsTest, TestVoidT)
    {
        using zero_types_t = void_t<>;
        EXPECT_SAME_TYPES(void, zero_types_t);

        using single_types_t = void_t<T0>;
        EXPECT_SAME_TYPES(void, single_types_t);

        using multiple_types_t = void_t<T0, T1>;
        EXPECT_SAME_TYPES(void, multiple_types_t);
    }
}