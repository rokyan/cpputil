#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    using traits::is_array_v;

    TEST(TraitsTest, TestIsArray)
    {
        EXPECT_TRUE(is_array_v<T0[]>);
        EXPECT_TRUE(is_array_v<T0[1]>);

        EXPECT_TRUE(is_array_v<T0[][1]>);
        EXPECT_TRUE(is_array_v<T0[1][1]>);
    }
}