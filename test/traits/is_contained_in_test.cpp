#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::is_contained_in_v;

TEST(TraitsTest, TestIsContainedIn)
{
    EXPECT_TRUE((cpputil::is_contained_in_v<T0, T0>));
    EXPECT_TRUE((cpputil::is_contained_in_v<T0, T0, T1>));
    EXPECT_TRUE((cpputil::is_contained_in_v<T0, T0, T1, T2>));

    EXPECT_FALSE((cpputil::is_contained_in_v<T0>));
    EXPECT_FALSE((cpputil::is_contained_in_v<T0, T1>));
    EXPECT_FALSE((cpputil::is_contained_in_v<T0, T1, T2>));
    EXPECT_FALSE((cpputil::is_contained_in_v<T0, T1, T2, T3>));
}

} // namespace test
