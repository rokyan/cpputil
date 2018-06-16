#include <gtest\gtest.h>
#include <transform_type.h>
#include <packer.h>
#include <types.h>
#include <type_traits>

namespace test
{
    TEST(transform_type_test, test_transform_type)
    {
        using packer_t = cpputil::packer<T0, T1>;
        using const_packer_t = cpputil::packer<const T0, const T1>;

        using transform_to_const_t = cpputil::transform_type_t<std::add_const_t, packer_t>;
        using transform_to_non_const_t = cpputil::transform_type_t<std::remove_const_t, const_packer_t>;

        EXPECT_TRUE((std::is_same_v<transform_to_const_t, const_packer_t>));
        EXPECT_TRUE((std::is_same_v<transform_to_non_const_t, packer_t>));
    }
}