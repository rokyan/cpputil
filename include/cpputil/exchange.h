#pragma once

#include <utility>

namespace cpputil {

    template<typename T, typename U>
    constexpr T exchange(T& o, U&& new_value) {
        T old_value(std::move(o));
        o = std::forward<U>(new_value);
        return old_value;
    }
}