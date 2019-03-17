#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::add_const_t;

TEST(TraitsTest, TestAddConst)
{
    EXPECT_SAME_TYPES(const T0, add_const_t<T0>);
    EXPECT_SAME_TYPES(const T0, add_const_t<const T0>);
    EXPECT_SAME_TYPES(const volatile T0, add_const_t<volatile T0>);
    EXPECT_SAME_TYPES(const volatile T0, add_const_t<const volatile T0>);
}

} // namespace test
