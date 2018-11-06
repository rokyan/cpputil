#ifndef CPPUTIL_MOVE_HPP
#define CPPUTIL_MOVE_HPP

#include <traits.hpp>
// TODO: remove <type_traits> once all required traits are implemented in traits.hpp
#include <type_traits>

namespace cpputil
{
    template<typename T>
    constexpr traits::remove_reference_t<T>&& move(T&& t) noexcept
    {
        return static_cast<traits::remove_reference_t<T>&&>(t);
    }

    namespace detail
    {
        template<typename T>
        inline constexpr auto move_if_noexcept_condition_v =
            !std::is_nothrow_move_constructible_v<T> && std::is_copy_constructible_v<T>;
    }

    template<typename T>
    constexpr traits::conditional_t<detail::move_if_noexcept_condition_v<T>, const T&, T&&> move_if_noexcept(T& t) noexcept
    {
        return cpputil::move(t);
    }
}

#endif // CPPUTIL_MOVE_HPP