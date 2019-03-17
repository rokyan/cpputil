#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::remove_const_t;

TEST(TraitsTest, TestRemoveConst)
{
    EXPECT_SAME_TYPES(T0, remove_const_t<T0>);
    EXPECT_SAME_TYPES(T0, remove_const_t<const T0>);
    EXPECT_SAME_TYPES(volatile T0, remove_const_t<volatile T0>);
    EXPECT_SAME_TYPES(volatile T0, remove_const_t<const volatile T0>);
}

} // namespace test
