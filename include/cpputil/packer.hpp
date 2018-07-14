/**
 * Based on http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4115.hpptml
 */

#pragma once

#include <traits.hpp>

namespace cpputil
{
    // packer holds an arbitrary parameter pack.

    template<typename...>
    struct packer {};

    using empty_packer = packer<>;

    // packer related meta functions.

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

    template<typename, typename>
    struct packer_add_first;

    template<template<typename...> typename Packer, typename T, typename... Ts>
    struct packer_add_first<Packer<Ts...>, T>
    {
        using type = Packer<T, Ts...>;
    };

    template<typename Packer, typename T>
    using packer_add_first_t = typename packer_add_first<Packer, T>::type;

    template<typename, typename>
    struct packer_add_last;

    template<template<typename...> typename Packer, typename T, typename... Ts>
    struct packer_add_last<Packer<Ts...>, T>
    {
        using type = Packer<Ts..., T>;
    };

    template<typename Packer, typename T>
    using packer_add_last_t = typename packer_add_last<Packer, T>::type;

    template<typename, template<typename> typename>
    struct packer_map;

    template<typename Packer, template<typename> typename Func>
    using packer_map_t = typename packer_map<Packer, Func>::type;

    template<template<typename...> typename Packer, template<typename> typename Func, typename... Ts>
    struct packer_map<Packer<Ts...>, Func>
    {
        using type = Packer<Func<Ts>...>;
    };

    template<typename, template<typename> typename>
    struct packer_filter;

    template<typename Packer, template<typename> typename Func>
    using packer_filter_t = typename packer_filter<Packer, Func>::type;

    template<template<typename...> typename Packer, template<typename> typename Func>
    struct packer_filter<Packer<>, Func>
    {
        using type = Packer<>;
    };

    template<template<typename...> typename Packer, template<typename> typename Func, typename T, typename... Ts>
    struct packer_filter<Packer<T, Ts...>, Func>
    {
        using filtered_tail_t = packer_filter_t<Packer<Ts...>, Func>;

        using type = traits::conditional_t<Func<T>::value,
            packer_add_first_t<filtered_tail_t, T>,
            filtered_tail_t>;
    };
}
