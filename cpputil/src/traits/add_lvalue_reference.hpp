#ifndef CPPUTIL_ADD_LVALUE_REFERENCE_HPP
#define CPPUTIL_ADD_LVALUE_REFERENCE_HPP

#include "identity.hpp"
#include "void_t.hpp"

namespace traits
{
    template<typename T, typename = void>
    struct add_lvalue_reference_impl :
        identity<T> {};

    template<typename T>
    struct add_lvalue_reference_impl<T, void_t<T&>> :
        identity<T&> {};

    template<typename T>
    struct add_lvalue_reference :
        add_lvalue_reference_impl<T> {};

    template<typename T>
    using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
}

#endif // CPPUTIL_ADD_LVALUE_REFERENCE_HPP
