#ifndef CPPUTIL_ITERATOR_OPERATIONS_HPP
#define CPPUTIL_ITERATOR_OPERATIONS_HPP

#include "iterator_traits.hpp"
#include "iterator_tags.hpp"

namespace cpputil
{

template<typename InputIterator>
constexpr auto advance_impl(InputIterator& it, difference_type_t<InputIterator> n, input_iterator_tag)
{
    while (n--) { ++it; }
}

template<typename InputIterator>
constexpr auto advance_impl(InputIterator& it, difference_type_t<InputIterator> n, bidirectional_iterator_tag)
{
    if (n > 0)
    {
        while (n--) { ++it; }
    }
    else
    {
        while (n++) { --it; }
    }
}

template<typename InputIterator>
constexpr auto advance_impl(InputIterator& it, difference_type_t<InputIterator> n, random_access_iterator_tag)
{
    it += n;
}

template<typename InputIterator>
constexpr auto advance(InputIterator& it, difference_type_t<InputIterator> n)
{
    advance_impl(it, n, iterator_category_t<InputIterator>{});
}

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

template<typename InputIterator>
constexpr auto next(InputIterator it, difference_type_t<InputIterator> n = 1) -> InputIterator
{
    cpputil::advance(it, n);
    return it;
}

template<typename BidirectionalIterator>
constexpr auto prev(BidirectionalIterator it, difference_type_t<BidirectionalIterator> n = 1) -> BidirectionalIterator
{
    cpputil::advance(it, -n);
    return it;
}

} // namespace cpputil

#endif // CPPUTIL_ITERATOR_OPERATIONS_HPP
