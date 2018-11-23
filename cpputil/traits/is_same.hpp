#ifndef CPPUTIL_IS_SAME_HPP
#define CPPUTIL_IS_SAME_HPP

#include "integral_constant.hpp"

namespace traits
{

template<typename T, typename U>
struct is_same :
    false_type {};

template<typename T>
struct is_same<T, T> :
    true_type {};

template<typename T, typename U>
inline constexpr auto is_same_v = is_same<T, U>::value;

} // namespace traits

#endif // CPPUTIL_IS_SAME_HPP
