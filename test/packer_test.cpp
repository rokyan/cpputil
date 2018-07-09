#include <gtest\gtest.h>
#include <packer.hpp>
#include <types.hpp>

namespace test
{
    TEST(packer_test, test_is_contained_in)
    {
        EXPECT_TRUE((cpputil::is_contained_in_v<T0, T0>));
        EXPECT_TRUE((cpputil::is_contained_in_v<T0, T0, T1>));
        EXPECT_TRUE((cpputil::is_contained_in_v<T0, T0, T1, T2>));

        EXPECT_FALSE((cpputil::is_contained_in_v<T0>));
        EXPECT_FALSE((cpputil::is_contained_in_v<T0, T1>));
        EXPECT_FALSE((cpputil::is_contained_in_v<T0, T1, T2>));
        EXPECT_FALSE((cpputil::is_contained_in_v<T0, T1, T2, T3>));
    }

    TEST(packer_test, test_contains_types)
    {
        EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<T0, T1>, cpputil::packer<>>));
        EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<T0, T1>, cpputil::packer<T0>>));
        EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<T0, T1>, cpputil::packer<T1>>));
        EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<T0, T1>, cpputil::packer<T0, T1>>));

        EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<T0, T1>, cpputil::packer<T2>>));
        EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<T0, T1>, cpputil::packer<T0, T2>>));
        EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<T0, T1>, cpputil::packer<T2, T0>>));
        EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<T0, T1>, cpputil::packer<T0, T1, T2>>));
    }
}