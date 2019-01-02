#ifndef CPPUTIL_ADD_CV_HPP
#define CPPUTIL_ADD_CV_HPP

#include "identity.hpp"

namespace cpputil
{

template<typename T>
struct add_cv :
    identity<const volatile T> {};

template<typename T>
using add_cv_t = typename add_cv<T>::type;

} // namespace cpputil

#endif // CPPUTIL_ADD_CV_HPP
