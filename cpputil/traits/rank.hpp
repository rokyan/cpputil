#ifndef CPPUTIL_TRAITS_RANK_HPP
#define CPPUTIL_TRAITS_RANK_HPP

#include "integral_constant.hpp"
#include <cstddef>

namespace traits
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

} // namespace traits

#endif // CPPUTIL_TRAITS_RANK_HPP