#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using traits::is_contained_in_v;

TEST(TraitsTest, TestIsContainedIn)
{
    EXPECT_TRUE((traits::is_contained_in_v<T0, T0>));
    EXPECT_TRUE((traits::is_contained_in_v<T0, T0, T1>));
    EXPECT_TRUE((traits::is_contained_in_v<T0, T0, T1, T2>));

    EXPECT_FALSE((traits::is_contained_in_v<T0>));
    EXPECT_FALSE((traits::is_contained_in_v<T0, T1>));
    EXPECT_FALSE((traits::is_contained_in_v<T0, T1, T2>));
    EXPECT_FALSE((traits::is_contained_in_v<T0, T1, T2, T3>));
}

} // namespace test
