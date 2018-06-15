#include <gtest\gtest.h>
#include <type_rename.h>
#include <packer.h>
#include <tuple>
#include "test_types.h"

namespace test
{
    TEST(type_rename_test, test_rename)
    {
        EXPECT_TRUE((std::is_same_v<cpputil::packer<>,
            cpputil::type_rename_t<cpputil::packer<>, cpputil::packer>>));
        EXPECT_TRUE((std::is_same_v<cpputil::packer<T0>,
            cpputil::type_rename_t<cpputil::packer<T0>, cpputil::packer>>));
        EXPECT_TRUE((std::is_same_v<cpputil::packer<T0, T1>,
            cpputil::type_rename_t<cpputil::packer<T0, T1>, cpputil::packer>>));

        EXPECT_TRUE((std::is_same_v<std::tuple<T0>,
            cpputil::type_rename_t<cpputil::packer<T0>, std::tuple>>));
        EXPECT_TRUE((std::is_same_v<std::tuple<T0, T1>,
            cpputil::type_rename_t<cpputil::packer<T0, T1>, std::tuple>>));
        EXPECT_TRUE((std::is_same_v<std::tuple<T0, T1, T2>,
            cpputil::type_rename_t<cpputil::packer<T0, T1, T2>, std::tuple>>));
        EXPECT_TRUE((std::is_same_v<std::tuple<T0, T1, T2, T3>,
            cpputil::type_rename_t<cpputil::packer<T0, T1, T2, T3>, std::tuple>>));
    }
}