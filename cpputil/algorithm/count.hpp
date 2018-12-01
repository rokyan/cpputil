#ifndef CPPUTIL_COUNT_HPP
#define CPPUTIL_COUNT_HPP

#include <iterator_traits.hpp>

namespace cpputil
{

template<typename InputIterator, typename T>
constexpr auto count(InputIterator first, InputIterator last, const T& value) -> difference_type_t<InputIterator>
{
    difference_type_t<InputIterator> total = 0;

    for (; first != last; ++first)
    {
        if (*first == value) { total++; }
    }

    return total;
}

template<typename InputIterator, typename Pred>
constexpr auto count_if(InputIterator first, InputIterator last, Pred predicate) -> difference_type_t<InputIterator>
{
    difference_type_t<InputIterator> total = 0;

    for (; first != last; ++first)
    {
        if (predicate(*first)) { total++; }
    }

    return total;
}

} // namespace cpputil

#endif // CPPUTIL_COUNT_HPP
