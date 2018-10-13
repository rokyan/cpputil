#pragma once

#include "identity.hpp"

namespace traits
{
    template<typename T>
    struct remove_reference :
        identity<T> {};

    template<typename T>
    struct remove_reference<T&> :
        identity<T> {};

    template<typename T>
    struct remove_reference<T&&> :
        identity<T> {};

    template<typename T>
    using remove_reference_t = typename remove_reference<T>::type;
}
