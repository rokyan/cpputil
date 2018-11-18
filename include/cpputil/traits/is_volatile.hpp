#ifndef CPPUTIL_IS_VOLATILE_HPP
#define CPPUTIL_IS_VOLATILE_HPP

#include "integral_constant.hpp"

namespace traits
{

template<typename T>
struct is_volatile :
    false_type {};

template<typename T>
struct is_volatile<volatile T> :
    true_type {};

template<typename T>
inline constexpr auto is_volatile_v = is_volatile<T>::value;

} // namespace traits

#endif // CPPUTIL_IS_VOLATILE_HPP
