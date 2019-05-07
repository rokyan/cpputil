#pragma once

namespace cpputil
{

template<typename OutputIterator, typename Size, typename T>
constexpr void fill_n(OutputIterator first, Size size, const T& value)
{
    while (size > 0)
    {
        *first = value;
        ++first;
        --size;
    }
}

} // namespace cpputil
