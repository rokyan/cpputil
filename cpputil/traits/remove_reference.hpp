#ifndef CPPUTIL_REMOVE_REFERENCE_HPP
#define CPPUTIL_REMOVE_REFERENCE_HPP

#include "identity.hpp"

namespace cpputil
{

template<typename T>
struct remove_reference :
    identity<T> {};

template<typename T>
struct remove_reference<T&> :
    identity<T> {};

template<typename T>
struct remove_reference<T&&> :
    identity<T> {};

template<typename T>
using remove_reference_t = typename remove_reference<T>::type;

} // namespace cpputil

#endif // CPPUTIL_REMOVE_REFERENCE_HPP
