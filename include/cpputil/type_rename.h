#pragma once

namespace cpputil
{
    template<typename, template<typename...> typename To>
    struct type_rename;

    template<template<typename...> typename From, template<typename...> typename To, typename... Ts>
    struct type_rename<From<Ts...>, To>
    {
        using type = To<Ts...>;
    };

    template<typename From, template<typename...> typename To>
    using type_rename_t = typename type_rename<From, To>::type;
}