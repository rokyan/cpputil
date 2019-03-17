#pragma once

#include <traits.hpp>

namespace cpputil
{

template<typename T>
constexpr T&& forward(cpputil::remove_reference_t<T>& t) noexcept
{
    return static_cast<T&&>(t);
}

template<typename T>
constexpr T&& forward(cpputil::remove_reference_t<T>&& t) noexcept
{
    return static_cast<T&&>(t);
}

} // namespace cpputil
