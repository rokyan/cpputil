#pragma once

#include "type_identity.hpp"
#include "remove_cv.hpp"

namespace cpputil
{

template<typename T, typename U>
struct remove_pointer_impl :
    type_identity<T> {};

template<typename T, typename U>
struct remove_pointer_impl<T, U*> :
    type_identity<U> {};

template<typename T>
struct remove_pointer :
    remove_pointer_impl<T, remove_cv_t<T>> {};

template<typename T>
using remove_pointer_t = typename remove_pointer<T>::type;

} // namespace cpputil
