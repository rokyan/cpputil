#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    using traits::remove_reference_t;

    TEST(TraitsTest, TestRemoveReference)
    {
        EXPECT_SAME_TYPES(remove_reference_t<T0>, T0);
        EXPECT_SAME_TYPES(remove_reference_t<T0&>, T0);
        EXPECT_SAME_TYPES(remove_reference_t<T0&&>, T0);
    }
}