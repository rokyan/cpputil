#pragma once

#include "predicates.hpp"

namespace cpputil
{

template<typename InputIterator, typename Predicate>
constexpr InputIterator find_impl(InputIterator first, InputIterator last, Predicate pred)
{
    for (; first != last; ++first)
    {
        if (pred(first))
        {
            return first;
        }
    }

    return last;
}

template<typename InputIterator, typename T>
constexpr InputIterator find(InputIterator first, InputIterator last, const T& value)
{
    return cpputil::find_impl(first, last, make_iter_eq_to_val(value));
}

template<typename InputIterator, typename UnaryPredicate>
constexpr InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    return cpputil::find_impl(first, last, make_iter_pred(pred));
}

template<typename InputIterator, typename UnaryPredicate>
constexpr InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    return cpputil::find_impl(first, last, make_iter_neg_pred(pred));
}

} // namespace cpputil