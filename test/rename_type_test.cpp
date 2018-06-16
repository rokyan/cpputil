#include <gtest\gtest.h>
#include <rename_type.h>
#include <packer.h>
#include <types.h>
#include <tuple>

namespace test
{
    TEST(rename_type_test, test_rename_type)
    {
        EXPECT_TRUE((std::is_same_v<cpputil::packer<>,
            cpputil::rename_type_t<cpputil::packer<>, cpputil::packer>>));
        EXPECT_TRUE((std::is_same_v<cpputil::packer<T0>,
            cpputil::rename_type_t<cpputil::packer<T0>, cpputil::packer>>));
        EXPECT_TRUE((std::is_same_v<cpputil::packer<T0, T1>,
            cpputil::rename_type_t<cpputil::packer<T0, T1>, cpputil::packer>>));

        EXPECT_TRUE((std::is_same_v<std::tuple<T0>,
            cpputil::rename_type_t<cpputil::packer<T0>, std::tuple>>));
        EXPECT_TRUE((std::is_same_v<std::tuple<T0, T1>,
            cpputil::rename_type_t<cpputil::packer<T0, T1>, std::tuple>>));
        EXPECT_TRUE((std::is_same_v<std::tuple<T0, T1, T2>,
            cpputil::rename_type_t<cpputil::packer<T0, T1, T2>, std::tuple>>));
        EXPECT_TRUE((std::is_same_v<std::tuple<T0, T1, T2, T3>,
            cpputil::rename_type_t<cpputil::packer<T0, T1, T2, T3>, std::tuple>>));
    }
}