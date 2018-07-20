/**
 * Based on http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4115.html
 */

#pragma once

#include <traits.hpp>
#include <utility> // for std::tuple and std::index_sequence

namespace cpputil
{
    namespace pck
    {
        // packer holds an arbitrary parameter pack.

        template<typename...>
        struct packer {};

        using empty_packer = packer<>;

        /**
         * packer related meta functions.
         */

        // size implementation.

        template<typename>
        struct size;

        template<template<typename...> typename Packer, typename... Ts>
        struct size<Packer<Ts...>> :
            traits::integral_constant<std::size_t, sizeof...(Ts)> {};

        template<typename T>
        inline constexpr auto size_v = size<T>::value;

        // add_first implementation.

        template<typename, typename>
        struct add_first;

        template<template<typename...> typename Packer, typename T, typename... Ts>
        struct add_first<Packer<Ts...>, T>
        {
            using type = Packer<T, Ts...>;
        };

        template<typename Packer, typename T>
        using add_first_t = typename add_first<Packer, T>::type;

        // add_last implementation.

        template<typename, typename>
        struct add_last;

        template<template<typename...> typename Packer, typename T, typename... Ts>
        struct add_last<Packer<Ts...>, T>
        {
            using type = Packer<Ts..., T>;
        };

        template<typename Packer, typename T>
        using add_last_t = typename add_last<Packer, T>::type;

        // remove_first implementation.

        template<typename>
        struct remove_first;

        template<template<typename...> typename Packer>
        struct remove_first<Packer<>>
        {
            using type = Packer<>;
        };

        template<template<typename...> typename Packer, typename T, typename... Ts>
        struct remove_first<Packer<T, Ts...>>
        {
            using type = Packer<Ts...>;
        };

        template<typename T>
        using remove_first_t = typename remove_first<T>::type;

        // remove_last implementation.

        template<typename>
        struct remove_last;

        template<template<typename...> typename Packer>
        struct remove_last<Packer<>>
        {
            using type = Packer<>;
        };

        namespace detail
        {
            template<typename, typename>
            struct remove_last_helper;

            template<typename T, typename Sequence>
            using remove_last_helper_t = typename remove_last_helper<T, Sequence>::type;

            template<template<typename...> typename Packer, typename... Ts, std::size_t... Is>
            struct remove_last_helper<Packer<Ts...>, std::index_sequence<Is...>>
            {
                using type = Packer<std::tuple_element_t<Is, std::tuple<Ts...>>...>;
            };
        }

        template<template<typename...> typename Packer, typename... Ts>
        struct remove_last<Packer<Ts...>>
        {
            using type = detail::remove_last_helper_t<Packer<Ts...>,
                std::make_index_sequence<sizeof...(Ts) - 1>>;
        };

        template<typename T>
        using remove_last_t = typename remove_last<T>::type;

        // get_first implementation.

        template<typename>
        struct get_first;

        template<template<typename...> typename Packer, typename T, typename... Ts>
        struct get_first<Packer<T, Ts...>>
        {
            using type = T;
        };

        template<typename T>
        using get_first_t = typename get_first<T>::type;

        // get_last implementation.

        template<typename>
        struct get_last;

        template<template<typename...> typename Packer, typename... Ts>
        struct get_last<Packer<Ts...>>
        {
            static_assert(sizeof...(Ts) > 0, "Packer cannot be empty.");

            using type = std::tuple_element_t<sizeof...(Ts) - 1, std::tuple<Ts...>>;
        };

        template<typename T>
        using get_last_t = typename get_last<T>::type;

        // map implementation.

        template<typename, template<typename> typename>
        struct map;

        template<template<typename...> typename Packer, template<typename> typename Func, typename... Ts>
        struct map<Packer<Ts...>, Func>
        {
            using type = Packer<Func<Ts>...>;
        };

        template<typename Packer, template<typename> typename Func>
        using map_t = typename map<Packer, Func>::type;

        // filter implementation.

        template<typename, template<typename> typename>
        struct filter;

        template<template<typename...> typename Packer, template<typename> typename Func>
        struct filter<Packer<>, Func>
        {
            using type = Packer<>;
        };

        template<template<typename...> typename Packer, template<typename> typename Func, typename T, typename... Ts>
        struct filter<Packer<T, Ts...>, Func>
        {
            using filtered_tail_t = typename filter<Packer<Ts...>, Func>::type;

            using type = traits::conditional_t<Func<T>::value,
                add_first_t<filtered_tail_t, T>,
                filtered_tail_t>;
        };

        template<typename Packer, template<typename> typename Func>
        using filter_t = typename filter<Packer, Func>::type;

        // chain implementation.

        template<typename...>
        struct chain;

        template<template<typename...> typename Packer, typename... Ts>
        struct chain<Packer<Ts...>>
        {
            using type = Packer<Ts...>;
        };

        template<template<typename...> typename Packer, typename... Ts, typename... Us>
        struct chain<Packer<Ts...>, Packer<Us...>>
        {
            using type = Packer<Ts..., Us...>;
        };

        template<template<typename...> typename Packer, typename... Ts, typename... Packers>
        struct chain<Packer<Ts...>, Packers...>
        {
            using type = typename chain<Packer<Ts...>, typename chain<Packers...>::type>::type;
        };

        template<typename... Packers>
        using chain_t = typename chain<Packers...>::type;

        // same implementation

        template<typename, typename>
        struct same;

        template<template<typename...> typename Packer, template<typename...> typename OtherPacker>
        struct same<Packer<>, OtherPacker<>> :
            traits::true_type {};

        template<template<typename...> typename Packer, template<typename...> typename OtherPacker,
            typename... Ts>
        struct same<Packer<Ts...>, OtherPacker<>> :
            traits::false_type {};

        template<template<typename...> typename Packer, template<typename...> typename OtherPacker,
            typename... Us>
            struct same<Packer<>, OtherPacker<Us...>> :
            traits::false_type {};

        template<template<typename...> typename Packer, template<typename...> typename OtherPacker,
            typename T, typename... Ts, typename U, typename... Us>
            struct same<Packer<T, Ts...>, OtherPacker<U, Us...>> :
            traits::false_type {};

        template<template<typename...> typename Packer, template<typename...> typename OtherPacker,
            typename T, typename... Ts, typename... Us>
            struct same<Packer<T, Ts...>, OtherPacker<T, Us...>> :
            same<Packer<Ts...>, OtherPacker<Us...>> {};

        template<typename Packer, typename OtherPacker>
        inline constexpr auto same_v = same<Packer, OtherPacker>::value;

        // contains implementation.

        template<typename T, typename U>
        struct contains;

        template<typename... Ts>
        struct contains<packer<Ts...>, packer<>> :
            traits::true_type {};

        template<typename... Ts, typename U, typename... Us>
        struct contains<packer<Ts...>, packer<U, Us...>> :
            traits::bool_constant<traits::is_contained_in_v<U, Ts...> &&
            contains<packer<Ts...>, packer<Us...>>::value> {};

        template<typename T, typename U>
        inline constexpr auto contains_v = contains<T, U>::value;
    }
}