#pragma once

#include "type_identity.hpp"
#include <cstddef>

namespace cpputil
{

template<typename T>
struct remove_extent :
    type_identity<T> {};

template<typename T, std::size_t N>
struct remove_extent<T[N]> :
    type_identity<T> {};

template<typename T>
struct remove_extent<T[]> :
    type_identity<T> {};

template<typename T>
using remove_extent_t = typename remove_extent<T>::type;

} // namespace cpputil
