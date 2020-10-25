#pragma once

#include "integral_constant.hpp"
#include "type_identity.hpp"

namespace cpputil
{

template<typename T>
struct remove_volatile :
    type_identity<T> {};

template<typename T>
struct remove_volatile<volatile T> :
    type_identity<T> {};

template<typename T>
using remove_volatile_t = typename remove_volatile<T>::type;

} // namespace cpputil
