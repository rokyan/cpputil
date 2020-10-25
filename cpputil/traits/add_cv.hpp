#pragma once

#include "type_identity.hpp"

namespace cpputil
{

template<typename T>
struct add_cv :
    type_identity<const volatile T> {};

template<typename T>
using add_cv_t = typename add_cv<T>::type;

} // namespace cpputil
