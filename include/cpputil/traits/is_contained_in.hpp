#ifndef CPPUTIL_IS_CONTAINED_IN_HPP
#define CPPUTIL_IS_CONTAINED_IN_HPP

#include "integral_constant.hpp"

namespace traits
{
    template<typename, typename...>
    struct is_contained_in :
        false_type {};

    template<typename T, typename... Ts>
    struct is_contained_in<T, T, Ts...> :
        true_type {};

    template<typename T, typename U, typename... Ts>
    struct is_contained_in<T, U, Ts...> :
        is_contained_in<T, Ts...> {};

    template<typename T, typename... Ts>
    inline constexpr auto is_contained_in_v = is_contained_in<T, Ts...>::value;
}

#endif // CPPUTIL_IS_CONTAINED_IN_HPP
