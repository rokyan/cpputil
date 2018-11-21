#ifndef CPPUTIL_EXCHANGE_HPP
#define CPPUTIL_EXCHANGE_HPP

#include "move.hpp"
#include "forward.hpp"

namespace cpputil
{
    template<typename T, typename U = T>
    constexpr T exchange(T& value, U&& new_value)
    {
        T old_value(cpputil::move(value));
        value = cpputil::forward<U>(new_value);
        return old_value;
    }
}

#endif // CPPUTIL_EXCHANGE_HPP
