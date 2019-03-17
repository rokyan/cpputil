#pragma once

#include "integral_constant.hpp"

namespace cpputil
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

} // namespace cpputil
