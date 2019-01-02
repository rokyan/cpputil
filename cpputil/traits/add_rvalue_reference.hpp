#ifndef CPPUTIL_ADD_RVALUE_REFERENCE_HPP
#define CPPUTIL_ADD_RVALUE_REFERENCE_HPP

#include "identity.hpp"
#include "void_t.hpp"

namespace cpputil
{

template<typename T, typename = void>
struct add_rvalue_reference_impl :
    identity<T> {};

template<typename T>
struct add_rvalue_reference_impl<T, void_t<T&&>> :
    identity<T&&> {};

template<typename T>
struct add_rvalue_reference :
    add_rvalue_reference_impl<T> {};

template<typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

} // namespace cpputil

#endif // CPPUTIL_ADD_RVALUE_REFERENCE_HPP
