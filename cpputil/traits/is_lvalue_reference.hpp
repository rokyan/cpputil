#pragma once

#include "integral_constant.hpp"

namespace cpputil
{

template<typename T>
struct is_lvalue_reference
    : false_type {};

template<typename T>
struct is_lvalue_reference<T&>
    : true_type {};

template<typename T>
inline constexpr auto is_lvalue_reference_v = is_lvalue_reference<T>::value;

} // namespace cpputil