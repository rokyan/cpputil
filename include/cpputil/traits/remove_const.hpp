#pragma once

#include "integral_constant.hpp"
#include "identity.hpp"

namespace traits
{
    template<typename T>
    struct remove_const :
        identity<T> {};

    template<typename T>
    struct remove_const<const T> :
        identity<T> {};

    template<typename T>
    using remove_const_t = typename remove_const<T>::type;
}
