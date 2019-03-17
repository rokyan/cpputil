#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(TraitsTest, TestIsSame)
{
    EXPECT_TRUE((cpputil::is_same_v<T0, T0>));
    EXPECT_FALSE((cpputil::is_same_v<T0, T1>));
}

} // namespace test
