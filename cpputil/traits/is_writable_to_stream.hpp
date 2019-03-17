#pragma once

#include "integral_constant.hpp"
#include "declval.hpp"
#include "void_t.hpp"
#include <iosfwd>

namespace cpputil
{

template<typename, typename = void>
struct is_writable_to_stream_impl
    : false_type {};

template<typename T>
struct is_writable_to_stream_impl<T, void_t<decltype(declval<std::ostream&>() << declval<T>())>>
    : true_type {};

template<typename T>
struct is_writable_to_stream :
    is_writable_to_stream_impl<T> {};

template<typename T>
inline constexpr auto is_writable_to_stream_v = is_writable_to_stream<T>::value;

} // namespace cpputil
