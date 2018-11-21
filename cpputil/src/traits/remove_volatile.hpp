#ifndef CPPUTIL_REMOVE_VOLATILE_HPP
#define CPPUTIL_REMOVE_VOLATILE_HPP

#include "integral_constant.hpp"
#include "identity.hpp"

namespace traits
{
    template<typename T>
    struct remove_volatile :
        identity<T> {};

    template<typename T>
    struct remove_volatile<volatile T> :
        identity<T> {};

    template<typename T>
    using remove_volatile_t = typename remove_volatile<T>::type;
}

#endif // CPPUTIL_REMOVE_VOLATILE_HPP
