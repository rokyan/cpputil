#pragma once

#include "move.hpp"
#include "forward.hpp"

namespace cpputil
{

template<typename T, typename U = T>
constexpr T exchange(T& value, U&& new_value)
{
    T old_value{ cpputil::move(value) };
    value = cpputil::forward<U>(new_value);
    return old_value;
}

} // namespace cpputil
