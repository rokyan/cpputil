#ifndef CPPUTIL_IS_READABLE_FROM_STREAM_HPP
#define CPPUTIL_IS_READABLE_FROM_STREAM_HPP

#include "integral_constant.hpp"
#include "declval.hpp"
#include "void_t.hpp"
#include <iosfwd>

namespace traits
{
    template<typename, typename = void>
    struct is_readable_from_stream_impl
        : false_type {};

    template<typename T>
    struct is_readable_from_stream_impl<T,
        void_t<decltype(traits::declval<std::istream&>() >> traits::declval<T>())>>
        : true_type {};

    template<typename T>
    struct is_readable_from_stream :
        is_readable_from_stream_impl<T> {};

    template<typename T>
    inline constexpr auto is_readable_from_stream_v = is_readable_from_stream<T>::value;
}

#endif // CPPUTIL_IS_READABLE_FROM_STREAM_HPP
