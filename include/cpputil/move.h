#pragma once

#include <type_traits>

namespace cpputil
{
    template<typename T>
    constexpr std::remove_reference_t<T>&& move(T&& t) noexcept
    {
        return static_cast<std::remove_reference_t<T>&&>(t);
    }
}