#pragma once

#include <type_identity.hpp>

namespace cpputil
{

template<bool B, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T>
    : type_identity<T> {};

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

} // namespace cpputil
