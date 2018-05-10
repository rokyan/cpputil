#pragma once

#include "forward.h"
#include "move.h"

namespace cpputil {

    template<typename T, typename U>
    constexpr T exchange(T& t, U&& new_value) {
        T old_value(cpputil::move(t));
        t = cpputil::forward<U>(new_value);
        return old_value;
    }
}