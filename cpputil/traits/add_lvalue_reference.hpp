#pragma once

#include "type_identity.hpp"
#include "void_t.hpp"

namespace cpputil
{

template<typename T, typename = void>
struct add_lvalue_reference_impl :
    type_identity<T> {};

template<typename T>
struct add_lvalue_reference_impl<T, void_t<T&>> :
    type_identity<T&> {};

template<typename T>
struct add_lvalue_reference :
    add_lvalue_reference_impl<T> {};

template<typename T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

} // namespace cpputil
