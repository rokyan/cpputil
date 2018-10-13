#pragma once

#include "integral_constant.hpp"
#include "identity.hpp"
#include "remove_const.hpp"
#include "remove_volatile.hpp"

namespace traits
{
    template<typename T>
    struct remove_cv :
        identity<remove_const_t<remove_volatile_t<T>>> {};

    template<typename T>
    using remove_cv_t = typename remove_cv<T>::type;
}
