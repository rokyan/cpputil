#include <gtest\gtest.h>
#include <traits.hpp>
#include <types.hpp>

namespace test
{
    TEST(traits_test, test_is_contained_in)
    {
        EXPECT_TRUE((traits::is_contained_in_v<T0, T0>));
        EXPECT_TRUE((traits::is_contained_in_v<T0, T0, T1>));
        EXPECT_TRUE((traits::is_contained_in_v<T0, T0, T1, T2>));

        EXPECT_FALSE((traits::is_contained_in_v<T0>));
        EXPECT_FALSE((traits::is_contained_in_v<T0, T1>));
        EXPECT_FALSE((traits::is_contained_in_v<T0, T1, T2>));
        EXPECT_FALSE((traits::is_contained_in_v<T0, T1, T2, T3>));
    }
}