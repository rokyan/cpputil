#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::remove_cv_t;

TEST(TraitsTest, TestRemoveConstVolatile)
{
    EXPECT_SAME_TYPES(T0, remove_cv_t<T0>);
    EXPECT_SAME_TYPES(T0, remove_cv_t<const T0>);
    EXPECT_SAME_TYPES(T0, remove_cv_t<volatile T0>);
    EXPECT_SAME_TYPES(T0, remove_cv_t<const volatile T0>);
}

} // namespace test
