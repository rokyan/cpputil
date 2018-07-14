#pragma once

#include "forward.hpp"
#include "move.hpp"

namespace cpputil
{
    template<typename T, typename U>
    constexpr T exchange(T& value, U&& new_value)
    {
        T old_value(cpputil::move(value));
        value = cpputil::forward<U>(new_value);
        return old_value;
    }
}