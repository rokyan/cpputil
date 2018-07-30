#include <gtest.hpp>
#include <transform_type.hpp>
#include <traits.hpp>
#include <packer.hpp>
#include <types.hpp>

namespace test
{
    using cpputil::pck::packer;
    using cpputil::transform_type_t;

    TEST(transform_type_test, test_transform_type)
    {
        using packer_t = packer<T0, T1>;
        using const_packer_t = packer<const T0, const T1>;

        using transform_to_const_t = transform_type_t<traits::add_const_t, packer_t>;
        using transform_to_non_const_t = transform_type_t<traits::remove_const_t, packer_t>;

        EXPECT_SAME_TYPES(transform_to_const_t, const_packer_t);
        EXPECT_SAME_TYPES(transform_to_non_const_t, packer_t);
    }
}