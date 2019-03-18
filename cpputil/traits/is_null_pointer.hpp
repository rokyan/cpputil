#pragma once

#include "remove_cv.hpp"
#include "is_same.hpp"

namespace cpputil
{

template<typename T>
struct is_null_pointer
    : is_same<std::nullptr_t, remove_cv_t<T>> {};

template<typename T>
inline constexpr bool is_null_pointer_v = is_null_pointer<T>::value;

} // namespace cpputil
