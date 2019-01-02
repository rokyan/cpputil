#ifndef CPPUTIL_AS_CONST_HPP
#define CPPUTIL_AS_CONST_HPP

#include <traits.hpp>

namespace cpputil
{
    template<typename T>
    constexpr cpputil::add_const_t<T>& as_const(T& t) noexcept
    {
        return t;
    }

    template<typename T>
    void as_const(const T&&) = delete;
}

#endif // CPPUTIL_AS_CONST_HPP
