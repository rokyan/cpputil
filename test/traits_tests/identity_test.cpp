#include <gtest.hpp>
#include <traits.hpp>
#include <types.hpp>

namespace test
{
    using traits::identity_t;

    TEST(traits_test, test_identity)
    {
        SAME_TYPES(T0, identity_t<T0>);
    }
}