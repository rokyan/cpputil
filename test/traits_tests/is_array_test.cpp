#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    using traits::is_array_v;

    TEST(traits_test, test_is_array)
    {
        EXPECT_TRUE(is_array_v<T0[]>);
        EXPECT_TRUE(is_array_v<T0[1]>);

        EXPECT_TRUE(is_array_v<T0[][1]>);
        EXPECT_TRUE(is_array_v<T0[1][1]>);
    }
}