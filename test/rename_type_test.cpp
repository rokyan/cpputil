#include <gtest.hpp>
#include <rename_type.hpp>
#include <packer.hpp>
#include <types.hpp>
#include <tuple>

namespace test
{
    using cpputil::pck::packer;
    using cpputil::rename_type_t;

    TEST(rename_type_test, test_rename_type)
    {
        using empty_packer_t = packer<>;
        using empty_packer_renamed_t = rename_type_t<packer<>, packer>;
        SAME_TYPES(empty_packer_t, empty_packer_renamed_t);

        using single_element_packer_t = packer<T0>;
        using single_element_packer_renamed_t = rename_type_t<packer<T0>, packer>;
        SAME_TYPES(single_element_packer_t, single_element_packer_renamed_t);

        using multiple_elements_packer_t = packer<T0, T1>;
        using multiple_elements_packer_renamed_t = rename_type_t<packer<T0, T1>, packer>;
        SAME_TYPES(multiple_elements_packer_t, multiple_elements_packer_renamed_t);

        using empty_tuple_t = std::tuple<>;
        using empty_tuple_renamed_t = rename_type_t<packer<>, std::tuple>;
        SAME_TYPES(empty_tuple_t, empty_tuple_renamed_t);

        using single_element_tuple_t = std::tuple<T0>;
        using single_element_tuple_renamed_t = rename_type_t<packer<T0>, std::tuple>;
        SAME_TYPES(single_element_tuple_t, single_element_tuple_renamed_t);

        using multiple_elements_tuple_t = std::tuple<T0, T1>;
        using multiple_elements_tuple_renamed_t = rename_type_t<packer<T0, T1>, std::tuple>;
        SAME_TYPES(multiple_elements_tuple_t, multiple_elements_tuple_renamed_t);
    }
}