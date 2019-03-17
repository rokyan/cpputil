#pragma once

#include "integral_constant.hpp"

namespace cpputil
{

template<typename T>
struct is_volatile :
    false_type {};

template<typename T>
struct is_volatile<volatile T> :
    true_type {};

template<typename T>
inline constexpr auto is_volatile_v = is_volatile<T>::value;

} // namespace cpputil
