#pragma once

#include <type_traits>

namespace cpputil {

    template<typename T>
    constexpr decltype(auto) forward(std::remove_reference_t<T>& t) noexcept {
        return static_cast<T&&>(t);
    }

    template<typename T>
    constexpr decltype(auto) forward(std::remove_reference_t<T>&& t) noexcept {
        return static_cast<T&&>(t);
    }
}