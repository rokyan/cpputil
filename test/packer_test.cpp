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

    TEST(packer_test, test_packer_add_first)
    {
        using packer_t_0 = cpputil::packer<>;
        using expected_packer_t_0 = cpputil::packer<T0>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_0,
            cpputil::packer_add_first_t<packer_t_0, T0>>)) <<
            "Error while adding a type to an empty packer as a first type";

        using packer_t_1 = cpputil::packer<T1>;
        using expected_packer_t_1 = cpputil::packer<T0, T1>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_1,
            cpputil::packer_add_first_t<packer_t_1, T0>>)) <<
            "Error while adding a type to a packer as a first type";
    }

    TEST(packer_test, test_packer_add_last)
    {
        using packer_t_0 = cpputil::packer<>;
        using expected_packer_t_0 = cpputil::packer<T0>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_0,
            cpputil::packer_add_last_t<packer_t_0, T0>>)) <<
            "Error while adding a type to an empty packer as a last type";

        using packer_t_1 = cpputil::packer<T0>;
        using expected_packer_t_1 = cpputil::packer<T0, T1>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_1,
            cpputil::packer_add_last_t<packer_t_1, T1>>)) <<
            "Error while adding a type to a packer as a last type";
    }

    TEST(packer_test, test_packer_remove_first)
    {
        using packer_t_0 = cpputil::empty_packer;
        using expected_packer_t_0 = cpputil::empty_packer;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_0,
            cpputil::packer_remove_first_t<packer_t_0>>)) <<
            "Error while removing the first type from an empty packer";

        using packer_t_1 = cpputil::packer<T0>;
        using expected_packer_t_1 = cpputil::empty_packer;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_1,
            cpputil::packer_remove_first_t<packer_t_1>>)) <<
            "Error while removing the first type from a packer with a single element";

        using packer_t_2 = cpputil::packer<T0, T1>;
        using expected_packer_t_2 = cpputil::packer<T1>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_2,
            cpputil::packer_remove_first_t<packer_t_2>>)) <<
            "Error while removing the first type from a packer with multiple element";
    }

    TEST(packer_test, test_packer_remove_last)
    {
        using packer_t_0 = cpputil::empty_packer;
        using expected_packer_t_0 = cpputil::empty_packer;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_0,
            cpputil::packer_remove_last_t<packer_t_0>>)) <<
            "Error while removing the last type from an empty packer";

        using packer_t_1 = cpputil::packer<T0>;
        using expected_packer_t_1 = cpputil::empty_packer;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_1,
            cpputil::packer_remove_last_t<packer_t_1>>)) <<
            "Error while removing the last type from a packer with a single element";

        using packer_t_2 = cpputil::packer<T0, T1>;
        using expected_packer_t_2 = cpputil::packer<T0>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_2,
            cpputil::packer_remove_last_t<packer_t_2>>)) <<
            "Error while removing the last type from a packer with multiple element";
    }

    TEST(packer_test, test_packer_map)
    {
        EXPECT_TRUE((traits::is_same_v<cpputil::empty_packer,
            cpputil::packer_map_t<cpputil::empty_packer, traits::remove_cv_t>>)) <<
            "packer_map operation has produced a wrong result on empty packer.";

        using packer_t = cpputil::packer<const T0, volatile T1, const volatile T2>;
        using expected_packer_t = cpputil::packer<T0, T1, T2>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t,
            cpputil::packer_map_t<packer_t, traits::remove_cv_t>>)) <<
            "packer_map operation has produced a wrong result.";
    }

    TEST(packer_test, test_packer_filter)
    {
        EXPECT_TRUE((traits::is_same_v<cpputil::empty_packer,
            cpputil::packer_map_t<cpputil::empty_packer, traits::remove_cv_t>>)) <<
            "packer_filter operation has produced a wrong result on empty packer.";

        using packer_t = cpputil::packer<const T0, volatile T1, const volatile T2>;
        using expected_packer_t = cpputil::packer<const T0, const volatile T2>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t,
            cpputil::packer_filter_t<packer_t, traits::is_const>>)) <<
            "packer_filter operation has produced a wrong result.";
    }
}