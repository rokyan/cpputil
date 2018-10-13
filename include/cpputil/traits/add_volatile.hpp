#pragma once

#include "identity.hpp"

namespace traits
{
    template<typename T>
    struct add_volatile :
        identity<volatile T> {};

    template<typename T>
    using add_volatile_t = typename add_volatile<T>::type;
}
