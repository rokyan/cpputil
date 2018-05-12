#pragma once

#include <type_traits>

namespace cpputil {

    template<typename T>
    constexpr std::add_const_t<T>& as_const(T& t) noexcept {
        return t;
    }

    template<typename T>
    void as_const(const T&&) = delete;
}