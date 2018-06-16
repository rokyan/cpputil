/**
 * Based on Peter Dimov's http://www.pdimov.com/cpp2/simple_cxx11_metaprogramming.html
 */

#pragma once

namespace cpputil
{
    template<typename, template<typename...> typename To>
    struct rename_type;

    template<template<typename...> typename From, template<typename...> typename To, typename... Ts>
    struct rename_type<From<Ts...>, To>
    {
        using type = To<Ts...>;
    };

    template<typename From, template<typename...> typename To>
    using rename_type_t = typename rename_type<From, To>::type;
}