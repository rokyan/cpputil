#pragma once

#include "integral_constant.hpp"
#include "type_identity.hpp"
#include "remove_const.hpp"
#include "remove_volatile.hpp"

namespace cpputil
{

template<typename T>
struct remove_cv :
    type_identity<remove_const_t<remove_volatile_t<T>>> {};

template<typename T>
using remove_cv_t = typename remove_cv<T>::type;

} // namespace cpputil
