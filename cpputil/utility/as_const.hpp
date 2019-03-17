#pragma once

#include <traits.hpp>

namespace cpputil
{

template<typename T>
constexpr traits::add_const_t<T>& as_const(T& t) noexcept
{
    return t;
}

// Disable for r-values to avoid dangling references.
// See: https://stackoverflow.com/questions/34566063.

template<typename T>
void as_const(const T&&) = delete;

} // namespace cpputil
