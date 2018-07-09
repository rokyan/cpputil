#pragma once

#include <type_traits>

namespace cpputil
{
    namespace detail
    {
        template<typename T>
        struct declval_protector
        {
            static constexpr auto always_false = false;
            static std::add_rvalue_reference_t<T> delegate();
        };
    }

    template<typename T>
    std::add_rvalue_reference_t<T> declval() noexcept
    {
        static_assert(detail::declval_protector<T>::always_false, "declval() must not be called!");
        return detail::declval_protector<T>::delegate();
    }
}