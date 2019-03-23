#pragma once

#include "iterator_traits.hpp"
#include "iterator_tags.hpp"

namespace cpputil
{

template<typename InputIterator>
constexpr void advance_impl(InputIterator& it, difference_type_t<InputIterator> n, input_iterator_tag)
{
    while (n--)
    {
        ++it;
    }
}

template<typename InputIterator>
constexpr void advance_impl(InputIterator& it, difference_type_t<InputIterator> n, bidirectional_iterator_tag)
{
    if (n > 0)
    {
        while (n--)
        {
            ++it;
        }
    }
    else
    {
        while (n++)
        {
            --it;
        }
    }
}

template<typename InputIterator>
constexpr void advance_impl(InputIterator& it, difference_type_t<InputIterator> n, random_access_iterator_tag)
{
    it += n;
}

template<typename InputIterator>
constexpr void advance(InputIterator& it, difference_type_t<InputIterator> n)
{
    cpputil::advance_impl(it, n, iterator_category_t<InputIterator>{});
}

template<typename InputIterator>
constexpr difference_type_t<InputIterator> distance_impl(InputIterator first, InputIterator last, input_iterator_tag)
{
    difference_type_t<InputIterator> difference = 0;

    while (first != last)
    {
        ++difference;
        ++first;
    }

    return difference;
}

template<typename InputIterator>
constexpr difference_type_t<InputIterator> distance_impl(InputIterator first, InputIterator last, random_access_iterator_tag)
{
    return last - first;
}

template<typename InputIterator>
constexpr difference_type_t<InputIterator>distance(InputIterator first, InputIterator last)
{
    return cpputil::distance_impl(first, last, iterator_category_t<InputIterator>{});
}

template<typename InputIterator>
constexpr InputIterator next(InputIterator it, difference_type_t<InputIterator> n = 1)
{
    cpputil::advance(it, n);
    return it;
}

template<typename BidirectionalIterator>
constexpr BidirectionalIterator prev(BidirectionalIterator it, difference_type_t<BidirectionalIterator> n = 1)
{
    cpputil::advance(it, -n);
    return it;
}

} // namespace cpputil