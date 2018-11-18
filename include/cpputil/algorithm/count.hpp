#ifndef CPPUTIL_COUNT_HPP
#define CPPUTIL_COUNT_HPP

#include <iterator_traits.hpp>

namespace cpputil
{

template<typename InputIterator, typename T>
constexpr auto count(InputIterator first, InputIterator last, const T& value) ->
    difference_type_t<InputIterator>
{
    difference_type_t<InputIterator> counter = 0;

    for (; first != last; ++first)
    {
        if (*first == value) { counter++; }
    }

    return counter;
}

template<typename InputIterator, typename Pred>
constexpr auto count_if(InputIterator first, InputIterator last, Pred predicate) ->
    difference_type_t<InputIterator>
{
    difference_type_t<InputIterator> counter = 0;

    for (; first != last; ++first)
    {
        if (predicate(*first)) { counter++; }
    }

    return counter;
}

} // namespace cpputil

#endif // CPPUTIL_COUNT_HPP
