#pragma once

#include "type_identity.hpp"
#include "void_t.hpp"

namespace cpputil
{

template<typename T, typename = void>
struct add_rvalue_reference_impl :
    type_identity<T> {};

template<typename T>
struct add_rvalue_reference_impl<T, void_t<T&&>> :
    type_identity<T&&> {};

template<typename T>
struct add_rvalue_reference :
    add_rvalue_reference_impl<T> {};

template<typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

} // namespace cpputil
