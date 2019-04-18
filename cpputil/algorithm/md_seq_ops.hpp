#pragma once

namespace cpputil
{

template<typename InputIterator, typename OutputIterator>
constexpr OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
{
    for (; first != last; ++first)
    {
        *result = *first;
        ++result;
    }

    return result;
}

template<typename InputIterator, typename OutputIterator, typename Predicate>
constexpr OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred)
{
    for (; first != last; ++first)
    {
        if (pred(*first))
        {
            *result = *first;
            ++result;
        }
    }

    return result;
}

} // namespace cpputil
