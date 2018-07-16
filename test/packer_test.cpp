#include <gtest\gtest.h>
#include <literals.hpp>
#include <packer.hpp>
#include <types.hpp>

namespace test
{
    using cpputil::pck::packer;
    using cpputil::pck::empty_packer;

    TEST(packer_test, test_contains_types)
    {
        using cpputil::pck::contains_types_v;

        EXPECT_TRUE((contains_types_v<packer<T0, T1>, empty_packer>));
        EXPECT_TRUE((contains_types_v<packer<T0, T1>, packer<T0>>));
        EXPECT_TRUE((contains_types_v<packer<T0, T1>, packer<T1>>));
        EXPECT_TRUE((contains_types_v<packer<T0, T1>, packer<T0, T1>>));

        EXPECT_FALSE((contains_types_v<packer<T0, T1>, packer<T2>>));
        EXPECT_FALSE((contains_types_v<packer<T0, T1>, packer<T0, T2>>));
        EXPECT_FALSE((contains_types_v<packer<T0, T1>, packer<T2, T0>>));
        EXPECT_FALSE((contains_types_v<packer<T0, T1>, packer<T0, T1, T2>>));
    }

    TEST(packer_test, test_empty_packer)
    {
        EXPECT_TRUE((traits::is_same_v<packer<>, empty_packer>));
    }

    TEST(packer_test, test_size)
    {
        using cpputil::pck::size_v;
        using cpputil::literals::operator""_zu;

        const auto size_0 = size_v<empty_packer>;
        EXPECT_EQ(0_zu, size_0);

        const auto size_1 = size_v<packer<T0>>;
        EXPECT_EQ(1_zu, size_1);

        const auto size_2 = size_v<packer<T0, T1>>;
        EXPECT_EQ(2_zu, size_2);
    }

    TEST(packer_test, test_add_first)
    {
        using cpputil::pck::add_first_t;

        using packer_t_0 = packer<>;
        using expected_packer_t_0 = packer<T0>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_0,
            add_first_t<packer_t_0, T0>>)) <<
            "Error while adding a type to an empty packer as a first type";

        using packer_t_1 = packer<T1>;
        using expected_packer_t_1 = packer<T0, T1>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_1,
            add_first_t<packer_t_1, T0>>)) <<
            "Error while adding a type to a packer as a first type";
    }

    TEST(packer_test, test_add_last)
    {
        using cpputil::pck::add_last_t;

        using packer_t_0 = packer<>;
        using expected_packer_t_0 = packer<T0>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_0,
            add_last_t<packer_t_0, T0>>)) <<
            "Error while adding a type to an empty packer as a last type";

        using packer_t_1 = packer<T0>;
        using expected_packer_t_1 = packer<T0, T1>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_1,
            add_last_t<packer_t_1, T1>>)) <<
            "Error while adding a type to a packer as a last type";
    }

    TEST(packer_test, test_remove_first)
    {
        using cpputil::pck::remove_first_t;

        using packer_t_0 = empty_packer;
        using expected_packer_t_0 = empty_packer;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_0,
            remove_first_t<packer_t_0>>)) <<
            "Error while removing the first type from an empty packer";

        using packer_t_1 = packer<T0>;
        using expected_packer_t_1 = empty_packer;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_1,
            remove_first_t<packer_t_1>>)) <<
            "Error while removing the first type from a packer with a single element";

        using packer_t_2 = packer<T0, T1>;
        using expected_packer_t_2 = packer<T1>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_2,
            remove_first_t<packer_t_2>>)) <<
            "Error while removing the first type from a packer with multiple element";
    }

    TEST(packer_test, test_remove_last)
    {
        using cpputil::pck::remove_last_t;

        using packer_t_0 = empty_packer;
        using expected_packer_t_0 = empty_packer;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_0,
            remove_last_t<packer_t_0>>)) <<
            "Error while removing the last type from an empty packer";

        using packer_t_1 = packer<T0>;
        using expected_packer_t_1 = empty_packer;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_1,
            remove_last_t<packer_t_1>>)) <<
            "Error while removing the last type from a packer with a single element";

        using packer_t_2 = packer<T0, T1>;
        using expected_packer_t_2 = packer<T0>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t_2,
            remove_last_t<packer_t_2>>)) <<
            "Error while removing the last type from a packer with multiple element";
    }

    TEST(packer_test, test_get_first)
    {
        using cpputil::pck::get_first_t;

        using packer_t_0 = packer<T0>;

        EXPECT_TRUE((traits::is_same_v<T0, get_first_t<packer_t_0>>));

        using packer_t_1 = packer<T0, T1>;

        EXPECT_TRUE((traits::is_same_v<T0, get_first_t<packer_t_1>>));
    }

    TEST(packer_test, test_get_last)
    {
        using cpputil::pck::get_last_t;

        using packer_t_0 = packer<T0>;

        EXPECT_TRUE((traits::is_same_v<T0, get_last_t<packer_t_0>>));

        using packer_t_1 = packer<T0, T1>;

        EXPECT_TRUE((traits::is_same_v<T1, get_last_t<packer_t_1>>));
    }

    TEST(packer_test, test_map)
    {
        using cpputil::pck::map_t;

        EXPECT_TRUE((traits::is_same_v<empty_packer,
            map_t<empty_packer, traits::remove_cv_t>>)) <<
            "map operation has produced a wrong result on empty packer.";

        using packer_t = packer<const T0, volatile T1, const volatile T2>;
        using expected_packer_t = packer<T0, T1, T2>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t,
            map_t<packer_t, traits::remove_cv_t>>)) <<
            "map operation has produced a wrong result.";
    }

    TEST(packer_test, test_filter)
    {
        using cpputil::pck::filter_t;

        EXPECT_TRUE((traits::is_same_v<empty_packer,
            filter_t<empty_packer, traits::remove_cv_t>>)) <<
            "filter operation has produced a wrong result on empty packer.";

        using packer_t = packer<const T0, volatile T1, const volatile T2>;
        using expected_packer_t = packer<const T0, const volatile T2>;

        EXPECT_TRUE((traits::is_same_v<expected_packer_t,
            filter_t<packer_t, traits::is_const>>)) <<
            "filter operation has produced a wrong result.";
    }
}