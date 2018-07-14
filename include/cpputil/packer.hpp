/**
 * Based on http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4115.hpptml
 */

#pragma once

#include <traits.hpp>

namespace cpputil
{
    // packer holds an arbitrary parameter pack

    template<typename...>
    struct packer {};

    // contains_types checks for packer<Ts...> and packer<Us...> if Ts... is a superset of Us...

    template<typename T, typename U>
    struct contains_types;

    template<typename... Ts>
    struct contains_types<packer<Ts...>, packer<>> :
        traits::true_type {};

    template<typename... Ts, typename U, typename... Us>
    struct contains_types<packer<Ts...>, packer<U, Us...>> :
        traits::bool_constant<traits::is_contained_in_v<U, Ts...> &&
            contains_types<packer<Ts...>, packer<Us...>>::value> {};

    template<typename T, typename U>
    inline constexpr auto contains_types_v = contains_types<T, U>::value;
}
