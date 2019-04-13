#pragma once

#include "integral_constant.hpp"
#include "remove_cv.hpp"
#include "is_same.hpp"

namespace cpputil
{

template<typename T>
struct is_void :
    is_same<remove_cv_t<T>, void> {};

template<typename T>
inline constexpr auto is_void_v = is_void<T>::value;

} // namespace cpputil
