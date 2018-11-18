#ifndef CPPUTIL_ADD_CONST_HPP
#define CPPUTIL_ADD_CONST_HPP

#include "identity.hpp"

namespace traits
{

template<typename T>
struct add_const :
    identity<const T> {};

template<typename T>
using add_const_t = typename add_const<T>::type;

} // namespace traits

#endif // CPPUTIL_ADD_CONST_HPP
