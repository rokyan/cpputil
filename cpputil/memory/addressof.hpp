#pragma once

namespace cpputil
{

template<typename T>
constexpr T* addressof(T& o) noexcept
{
    return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(o)));
}

template<typename T>
const T* addressof(const T&&) = delete;

} // namespace cpputil