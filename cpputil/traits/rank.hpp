#pragma once

#include "integral_constant.hpp"
#include <cstddef>

namespace cpputil
{

template<typename T>
struct rank :
    integral_constant<std::size_t, 0> {};

template<typename T, std::size_t N>
struct rank<T[N]> :
    integral_constant<std::size_t, rank<T>::value + 1> {};

template<typename T>
struct rank<T[]> :
    integral_constant<std::size_t, rank<T>::value + 1> {}; 

template<typename T>
inline constexpr auto rank_v = rank<T>::value;

} // namespace cpputil
