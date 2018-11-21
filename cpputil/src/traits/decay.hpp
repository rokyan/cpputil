#ifndef CPPUTIL_DECAY_HPP
#define CPPUTIL_DECAY_HPP

#include "identity.hpp"
#include "is_array.hpp"
#include "is_function.hpp"
#include "add_pointer.hpp"
#include "remove_cv.hpp"
#include "remove_extent.hpp"
#include "remove_reference.hpp"

namespace traits
{

template<typename T, bool = is_array_v<T>, bool = is_function_v<T>>
struct decay_impl :
    identity<remove_cv_t<T>> {};

template<typename T>
struct decay_impl<T, true, false> :
    identity<remove_extent_t<T>*> {};

template<typename T>
struct decay_impl<T, false, true> :
    identity<add_pointer_t<T>> {};

template<typename T>
struct decay :
    decay_impl<remove_reference_t<T>> {};

template<typename T>
using decay_t = typename decay<T>::type;

} // namespace traits

#endif // CPPUTIL_DECAY_HPP
