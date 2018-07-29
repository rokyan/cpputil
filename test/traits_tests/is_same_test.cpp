#include <gtest.hpp>
#include <types.hpp>
#include <traits.hpp>

namespace test
{
    TEST(traits_test, test_is_same)
    {
        EXPECT_TRUE((traits::is_same_v<T0, T0>));
        EXPECT_FALSE((traits::is_same_v<T0, T1>));
    }
}