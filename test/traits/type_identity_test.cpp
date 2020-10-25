#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::type_identity_t;

TEST(TraitsTest, TestIdentity)
{
    EXPECT_SAME_TYPES(T0, type_identity_t<T0>);
}

} // namespace test
