/**
 * Based on http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4115.hpptml
 */

#pragma once

#include <type_traits>

namespace cpputil
{
    // packer holds an arbitrary parameter pack

    template<typename...>
    struct packer {};

    // is_contained_in type trait checks if type T is in template parameter pack Ts...

    template<typename, typename...>
    struct is_contained_in :
        std::false_type {};

    template<typename T, typename... Ts>
    struct is_contained_in<T, T, Ts...> :
        std::true_type {};

    template<typename T, typename U, typename... Ts>
    struct is_contained_in<T, U, Ts...> :
        is_contained_in<T, Ts...> {};

    template<typename T, typename... Ts>
    inline constexpr auto is_contained_in_v = is_contained_in<T, Ts...>::value;

    // contains_types checks for packer<Ts...> and packer<Us...> if Ts... is a superset of Us...

    template<typename T, typename U>
    struct contains_types;

    template<typename... Ts>
    struct contains_types<packer<Ts...>, packer<>> :
        std::true_type {};

    template<typename... Ts, typename U, typename... Us>
    struct contains_types<packer<Ts...>, packer<U, Us...>> :
        std::bool_constant<is_contained_in_v<U, Ts...> &&
            contains_types<packer<Ts...>, packer<Us...>>::value> {};

    template<typename T, typename U>
    inline constexpr auto contains_types_v = contains_types<T, U>::value;
}
