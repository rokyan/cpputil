#ifndef CPPUTIL_DISTANCE_HPP
#define CPPUTIL_DISTANCE_HPP

#include "iterator_tags.hpp"
#include "iterator_traits.hpp"

namespace cpputil
{

template<typename InputIterator>
constexpr auto distance_impl(InputIterator first, InputIterator last, input_iterator_tag) ->
    difference_type_t<InputIterator>
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
constexpr auto distance_impl(InputIterator first, InputIterator last, random_access_iterator_tag) ->
    difference_type_t<InputIterator>
{
    return last - first;
}

template<typename InputIterator>
constexpr auto distance(InputIterator first, InputIterator last) ->
    difference_type_t<InputIterator>
{
    return distance_impl(first, last, iterator_category_t<InputIterator>{});
}

} // namespace cpputil

#endif // CPPUTIL_DISTANCE_HPP
