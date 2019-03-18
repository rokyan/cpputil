#pragma once

#include "integral_constant.hpp"

namespace cpputil
{

template<typename T>
struct alignment_of
    : integral_constant<std::size_t, alignof(T)> {};

template<typename T>
inline constexpr auto alignment_of_v = alignment_of<T>::value;

} // namespace cpputil
