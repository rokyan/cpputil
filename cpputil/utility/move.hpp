#pragma once

#include <traits.hpp>

#include <type_traits> // for some type traits.

namespace cpputil
{

template<typename T>
constexpr cpputil::remove_reference_t<T>&& move(T&& t) noexcept
{
    return static_cast<cpputil::remove_reference_t<T>&&>(t);
}

template<typename T>
inline constexpr auto move_if_noexcept_condition_v =
    !std::is_nothrow_move_constructible_v<T> && std::is_copy_constructible_v<T>;

template<typename T>
constexpr cpputil::conditional_t<move_if_noexcept_condition_v<T>, const T&, T&&> move_if_noexcept(T& t) noexcept
{
    return cpputil::move(t);
}

} // namespace cpputil