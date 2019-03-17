#pragma once

#include "integral_constant.hpp"
#include <cstddef>

namespace cpputil
{

template<typename T, std::size_t N = 0>
struct extent : integral_constant<std::size_t, 0> {};

template<typename T, std::size_t M, std::size_t N>
struct extent<T[M], N> : extent<T, N - 1> {};

template<typename T, std::size_t M>
struct extent<T[M], 0> : integral_constant<std::size_t, M> {};

template<typename T, std::size_t N>
struct extent<T[], N> : extent<T, N - 1> {};

template<typename T>
struct extent<T[], 0> : integral_constant<std::size_t, 0> {};

template<typename T, std::size_t N = 0>
inline constexpr std::size_t extent_v = extent<T, N>::value;

} // namespace cpputil
