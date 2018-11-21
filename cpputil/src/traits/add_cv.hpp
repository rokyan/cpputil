#ifndef CPPUTIL_ADD_CV_HPP
#define CPPUTIL_ADD_CV_HPP

#include "identity.hpp"

namespace traits
{

template<typename T>
struct add_cv :
    identity<const volatile T> {};

template<typename T>
using add_cv_t = typename add_cv<T>::type;

} // namespace traits

#endif // CPPUTIL_ADD_CV_HPP
