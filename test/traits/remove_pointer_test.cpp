#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using traits::remove_pointer_t;

TEST(TraitsTest, TestRemovePointer)
{
    EXPECT_SAME_TYPES(T0, remove_pointer_t<T0*>);
    EXPECT_SAME_TYPES(T0, remove_pointer_t<T0* const>);
    EXPECT_SAME_TYPES(T0, remove_pointer_t<T0* volatile>);
    EXPECT_SAME_TYPES(T0, remove_pointer_t<T0* const volatile>);
}

} // namespace test
