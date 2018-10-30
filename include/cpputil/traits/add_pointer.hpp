#ifndef CPPUTIL_ADD_POINTER_HPP
#define CPPUTIL_ADD_POINTER_HPP

#include "identity.hpp"
#include "void_t.hpp"
#include "remove_reference.hpp"

namespace traits
{
    template<typename T, typename = void>
    struct add_pointer :
        identity<T> {};

    template<typename T>
    struct add_pointer<T, void_t<remove_reference_t<T>*>> :
        identity<remove_reference_t<T>*> {};

    template<typename T>
    using add_pointer_t = typename add_pointer<T>::type;
}

#endif // CPPUTIL_ADD_POINTER_HPP
