#pragma once

#include "identity.hpp"
#include <cstddef>

namespace cpputil
{

template<typename T>
struct remove_extent :
    identity<T> {};

template<typename T, std::size_t N>
struct remove_extent<T[N]> :
    identity<T> {};

template<typename T>
struct remove_extent<T[]> :
    identity<T> {};

template<typename T>
using remove_extent_t = typename remove_extent<T>::type;

} // namespace cpputil
