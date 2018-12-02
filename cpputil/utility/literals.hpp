#ifndef CPPUTIL_LITERALS_HPP
#define CPPUTIL_LITERALS_HPP

#include <cstddef> // for std::size_t

namespace cpputil
{

namespace literals
{
    /**
     * Based on http://open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0330r0.pdf
     */

    constexpr std::size_t operator"" _zu(unsigned long long value)
    {
        return static_cast<std::size_t>(value);
    }

    constexpr std::size_t operator"" _zu(long double value)
    {
        return static_cast<std::size_t>(value);
    }
}

} // namespace cpputil

#endif //CPPUTIL_LITERALS_HPP
