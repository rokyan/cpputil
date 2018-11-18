#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using traits::remove_extent_t;

TEST(TraitsTest, TestRemoveExtent)
{
    EXPECT_SAME_TYPES(T0, remove_extent_t<T0[]>);
    EXPECT_SAME_TYPES(T0, remove_extent_t<T0[1]>);

    EXPECT_SAME_TYPES(T0[2], remove_extent_t<T0[][2]>);
    EXPECT_SAME_TYPES(T0[2], remove_extent_t<T0[1][2]>);
}

} // namespace test
