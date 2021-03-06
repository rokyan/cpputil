#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::add_cv_t;

TEST(TraitsTest, TestAddConstVolatile)
{
    EXPECT_SAME_TYPES(const volatile T0, add_cv_t<T0>);
    EXPECT_SAME_TYPES(const volatile T0, add_cv_t<const T0>);
    EXPECT_SAME_TYPES(const volatile T0, add_cv_t<volatile T0>);
    EXPECT_SAME_TYPES(const volatile T0, add_cv_t<const volatile T0>);
}

} // namespace test
