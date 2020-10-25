#pragma once

#include "type_identity.hpp"

namespace cpputil
{

template<bool Condition, typename T, typename U>
struct conditional :
    type_identity<T> {};

template<typename T, typename U>
struct conditional<false, T, U> :
    type_identity<U> {};

template<bool Condition, typename T, typename U>
using conditional_t = typename conditional<Condition, T, U>::type;

} // namespace cpputil
