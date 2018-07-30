#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    TEST(traits_test, test_integral_constant)
    {
        using T = int;
        using integral_constant_t = traits::integral_constant<T, T{}>;

        EXPECT_EQ(integral_constant_t::value, T{});

        EXPECT_SAME_TYPES(integral_constant_t::value_type, T);
        EXPECT_SAME_TYPES(integral_constant_t::type, integral_constant_t);

        EXPECT_EQ(integral_constant_t{}(), T{});
        EXPECT_EQ(static_cast<T>(integral_constant_t{}), T{});
    }
}