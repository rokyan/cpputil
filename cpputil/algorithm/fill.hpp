#pragma once

namespace cpputil
{

template<typename ForwardIterator, typename T>
constexpr void fill(ForwardIterator first, ForwardIterator last, const T& value)
{
    while (first != last)
    {
        *first = value;
        ++first;
    }
}

} // namespace cpputil