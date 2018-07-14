#include <gtest\gtest.h>
#include <packer.hpp>
#include <types.hpp>

namespace test
{
    TEST(packer_test, test_contains_types)
    {
        EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<T0, T1>,
            cpputil::packer<>>));
        EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<T0, T1>,
            cpputil::packer<T0>>));
        EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<T0, T1>,
            cpputil::packer<T1>>));
        EXPECT_TRUE((cpputil::contains_types_v<cpputil::packer<T0, T1>,
            cpputil::packer<T0, T1>>));

        EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<T0, T1>,
            cpputil::packer<T2>>));
        EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<T0, T1>,
            cpputil::packer<T0, T2>>));
        EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<T0, T1>,
            cpputil::packer<T2, T0>>));
        EXPECT_FALSE((cpputil::contains_types_v<cpputil::packer<T0, T1>,
            cpputil::packer<T0, T1, T2>>));
    }

    TEST(packer_test, test_packer_map)
    {
        using packer_t = cpputil::packer<const T0, volatile T1, const volatile T2>;
        using expected_packer_t = cpputil::packer<T0, T1, T2>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t,
            cpputil::packer_map_t<packer_t, traits::remove_cv_t>>)) <<
            "packer_map operation has produced wrong result.";
    }
}