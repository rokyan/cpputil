#pragma once

#include "integral_constant.hpp"

namespace cpputil
{

template<typename T>
struct is_unbounded_array
    : false_type {};

template<typename T>
struct is_unbounded_array<T[]>
    : true_type {};

template<typename T>
inline constexpr auto is_unbounded_array_v = is_unbounded_array<T>::value;

} // namespace cpputil