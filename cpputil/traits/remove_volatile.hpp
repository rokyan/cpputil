#pragma once

#include "integral_constant.hpp"
#include "identity.hpp"

namespace cpputil
{

template<typename T>
struct remove_volatile :
    identity<T> {};

template<typename T>
struct remove_volatile<volatile T> :
    identity<T> {};

template<typename T>
using remove_volatile_t = typename remove_volatile<T>::type;

} // namespace cpputil
