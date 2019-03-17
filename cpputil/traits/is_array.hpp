#pragma once

#include "integral_constant.hpp"
#include <cstddef>

namespace cpputil
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

} // namespace cpputil
