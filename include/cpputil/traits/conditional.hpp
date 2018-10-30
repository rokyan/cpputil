#ifndef CPPUTIL_CONDITIONAL_HPP
#define CPPUTIL_CONDITIONAL_HPP

#include "identity.hpp"

namespace traits
{
    template<bool Condition, typename T, typename U>
    struct conditional :
        identity<T> {};

    template<typename T, typename U>
    struct conditional<false, T, U> :
        identity<U> {};

    template<bool Condition, typename T, typename U>
    using conditional_t = typename conditional<Condition, T, U>::type;
}

#endif // CPPUTIL_CONDITIONAL_HPP
