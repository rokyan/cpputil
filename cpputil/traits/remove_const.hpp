#pragma once

#include "integral_constant.hpp"
#include "type_identity.hpp"

namespace cpputil
{

template<typename T>
struct remove_const :
    type_identity<T> {};

template<typename T>
struct remove_const<const T> :
    type_identity<T> {};

template<typename T>
using remove_const_t = typename remove_const<T>::type;

} // namespace cpputil
