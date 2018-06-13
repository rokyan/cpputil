#include <gtest\gtest.h>
#include <type_traits>
#include <packer.h>

TEST(packer_test, test_is_contained_in)
{
    EXPECT_TRUE((cpputil::is_contained_in_v<void, void>));
    EXPECT_TRUE((cpputil::is_contained_in_v<void, void, int>));
    EXPECT_TRUE((cpputil::is_contained_in_v<void, void, int, double>));

    EXPECT_FALSE((cpputil::is_contained_in_v<void>));
    EXPECT_FALSE((cpputil::is_contained_in_v<void, int>));
    EXPECT_FALSE((cpputil::is_contained_in_v<void, int, double>));
}

TEST(packer_test, test_contains_types)
{
    EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<>>));
    EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<void>>));
    EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<int>>));
    EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<void, int>>));
    EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<int, void>>));

    EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<double>>));
    EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<void, double>>));
    EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<double, void>>));
    EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<void, int>, cpputil::packer<double, void, int>>));
}