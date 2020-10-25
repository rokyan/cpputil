#pragma once

#include "type_identity.hpp"
#include "void_t.hpp"
#include "remove_reference.hpp"

namespace cpputil
{

template<typename T, typename = void>
struct add_pointer :
    type_identity<T> {};

template<typename T>
struct add_pointer<T, void_t<remove_reference_t<T>*>> :
    type_identity<remove_reference_t<T>*> {};

template<typename T>
using add_pointer_t = typename add_pointer<T>::type;

} // namespace cpputil
