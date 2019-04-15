#pragma once

#include "integral_constant.hpp"
#include <cstdlib>

namespace cpputil
{

template<typename T>
struct is_bounded_array
    : false_type {};

template<typename T, std::size_t N>
struct is_bounded_array<T[N]>
    : true_type {};

template<typename T>
inline constexpr auto is_bounded_array_v = is_bounded_array<T>::value;

} // namespace cpputil