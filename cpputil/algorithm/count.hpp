#pragma once

#include <iterator.hpp>

namespace cpputil
{

template<typename InputIterator, typename Predicate>
constexpr cpputil::difference_type_t<InputIterator>count_impl(InputIterator first, InputIterator last, Predicate pred)
{
    cpputil::difference_type_t<InputIterator> total = 0;

    for (; first != last; ++first)
    {
        if (pred(first)) { total++; }
    }

    return total;
}

template<typename InputIterator, typename T>
constexpr cpputil::difference_type_t<InputIterator> count(InputIterator first, InputIterator last, const T& value)
{
    return cpputil::count_impl(first, last, make_iter_eq_to_val(value));
}

template<typename InputIterator, typename Predicate>
constexpr cpputil::difference_type_t<InputIterator> count_if(InputIterator first, InputIterator last, Predicate pred)
{
    return cpputil::count_impl(first, last, make_iter_pred(pred));
}

} // namespace cpputil