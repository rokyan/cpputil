#include <gtest\gtest.h>
#include <packer.h>
#include "test_types.h"

namespace test
{
    TEST(packer_test, test_is_contained_in)
    {
        using cpputil::is_contained_in_v;

        EXPECT_TRUE((is_contained_in_v<T0, T0>));
        EXPECT_TRUE((is_contained_in_v<T0, T0, T1>));
        EXPECT_TRUE((is_contained_in_v<T0, T0, T1, T2>));

        EXPECT_FALSE((is_contained_in_v<T0>));
        EXPECT_FALSE((is_contained_in_v<T0, T1>));
        EXPECT_FALSE((is_contained_in_v<T0, T1, T2>));
        EXPECT_FALSE((is_contained_in_v<T0, T1, T2, T3>));
    }

    TEST(packer_test, test_contains_types)
    {
        using cpputil::contains_types_v;
        using cpputil::packer;

        EXPECT_TRUE((contains_types_v<packer<T0, T1>, packer<>>));
        EXPECT_TRUE((contains_types_v<packer<T0, T1>, packer<T0>>));
        EXPECT_TRUE((contains_types_v<packer<T0, T1>, packer<T1>>));
        EXPECT_TRUE((contains_types_v<packer<T0, T1>, packer<T0, T1>>));

        EXPECT_FALSE((contains_types_v<packer<T0, T1>, packer<T2>>));
        EXPECT_FALSE((contains_types_v<packer<T0, T1>, packer<T0, T2>>));
        EXPECT_FALSE((contains_types_v<packer<T0, T1>, packer<T2, T0>>));
        EXPECT_FALSE((contains_types_v<packer<T0, T1>, packer<T0, T1, T2>>));
    }
}