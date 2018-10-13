#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    TEST(TraitsTest, TestIsSame)
    {
        EXPECT_TRUE((traits::is_same_v<T0, T0>));
        EXPECT_FALSE((traits::is_same_v<T0, T1>));
    }
}