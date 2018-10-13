#pragma once

#include "identity.hpp"

namespace traits
{
    template<typename T>
    struct add_const :
        identity<const T> {};

    template<typename T>
    using add_const_t = typename add_const<T>::type;
}
