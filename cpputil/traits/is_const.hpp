#pragma once

#include "integral_constant.hpp"

namespace cpputil
{

template<typename T>
struct is_const :
    false_type {};

template<typename T>
struct is_const<const T> :
    true_type {};

template<typename T>
inline constexpr auto is_const_v = is_const<T>::value;

} // namespace cpputil
