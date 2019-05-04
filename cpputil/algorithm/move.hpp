#pragma once

#include <utility.hpp>

namespace cpputil
{

template<typename InputIterator, typename OutputIterator>
constexpr OutputIterator move(InputIterator first, InputIterator last, OutputIterator dest)
{
    while (first != last)
    {
        *dest = cpputil::move(*first);

        ++first;
        ++dest;
    }

    return dest;
}

} // namespace cpputil