#ifndef CPPUTIL_REMOVE_POINTER_HPP
#define CPPUTIL_REMOVE_POINTER_HPP

#include "identity.hpp"
#include "remove_cv.hpp"

namespace traits
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
}

#endif // CPPUTIL_REMOVE_POINTER_HPP
