#pragma once

#include "identity.hpp"

namespace traits
{
    template<typename T>
    struct add_cv :
        identity<const volatile T> {};

    template<typename T>
    using add_cv_t = typename add_cv<T>::type;
}
