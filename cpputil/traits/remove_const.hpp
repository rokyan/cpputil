#ifndef CPPUTIL_REMOVE_CONST_HPP
#define CPPUTIL_REMOVE_CONST_HPP

#include "integral_constant.hpp"
#include "identity.hpp"

namespace cpputil
{

template<typename T>
struct remove_const :
    identity<T> {};

template<typename T>
struct remove_const<const T> :
    identity<T> {};

template<typename T>
using remove_const_t = typename remove_const<T>::type;

} // namespace cpputil

#endif // CPPUTIL_REMOVE_CONST_HPP
