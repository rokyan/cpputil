#ifndef CPPUTIL_IS_CONST_HPP
#define CPPUTIL_IS_CONST_HPP

#include "integral_constant.hpp"

namespace traits
{
    template<typename T>
    struct is_const :
        false_type {};

    template<typename T>
    struct is_const<const T> :
        true_type {};

    template<typename T>
    inline constexpr auto is_const_v = is_const<T>::value;
}

#endif // CPPUTIL_IS_CONST_HPP
