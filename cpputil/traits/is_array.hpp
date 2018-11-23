#ifndef CPPUTIL_IS_ARRAY_HPP
#define CPPUTIL_IS_ARRAY_HPP

#include "integral_constant.hpp"
#include <cstddef>

namespace traits
{

template<typename T>
struct is_array :
    false_type {};

template<typename T, std::size_t N>
struct is_array<T[N]> :
    true_type {};

template<typename T>
struct is_array<T[]> :
    true_type {};

template<typename T>
inline constexpr auto is_array_v = is_array<T>::value;

}

#endif // CPPUTIL_IS_ARRAY_HPP
