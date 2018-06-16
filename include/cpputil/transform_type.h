/**
 * Based on Peter Dimov's http://www.pdimov.com/cpp2/simple_cxx11_metaprogramming.html
 */

#pragma once

namespace cpputil
{
    template<template<typename...> typename, typename>
    struct transform_type;

    template<template<typename...> typename F, template<typename...> typename T, typename... Ts>
    struct transform_type<F, T<Ts...>>
    {
        using type = T<F<Ts>...>;
    };

    template<template<typename...> typename F, typename L>
    using transform_type_t = typename transform_type<F, L>::type;
}
