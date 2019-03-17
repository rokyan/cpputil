#pragma once

#include "identity.hpp"
#include "remove_cv.hpp"

namespace cpputil
{

template<typename T, typename U>
struct remove_pointer_impl :
    identity<T> {};

template<typename T, typename U>
struct remove_pointer_impl<T, U*> :
    identity<U> {};

template<typename T>
struct remove_pointer :
    remove_pointer_impl<T, remove_cv_t<T>> {};

template<typename T>
using remove_pointer_t = typename remove_pointer<T>::type;

} // namespace cpputil
