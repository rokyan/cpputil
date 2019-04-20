#pragma once

namespace cpputil
{

template<typename InputIterator, typename Size, typename OutputIterator>
constexpr OutputIterator copy_n(InputIterator first, Size size, OutputIterator result)
{
    while (size > 0)
    {
        *result = *first;
        ++result;

        if (--size > 0)
        {
            ++first;
        }
    }

    return result;
}

} // namespace cpputil