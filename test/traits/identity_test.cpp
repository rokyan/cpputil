#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using traits::identity_t;

TEST(TraitsTest, TestIdentity)
{
    EXPECT_SAME_TYPES(T0, identity_t<T0>);
}

} // namespace test
