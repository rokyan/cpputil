#pragma once

#include "predicates.hpp"

namespace cpputil
{

template<typename ForwardIterator, typename Predicate>
constexpr ForwardIterator adjacent_find_impl(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    if (first == last)
    {
        return last;
    }

    ForwardIterator next = first;

    while (++next != last)
    {
        if (pred(first, next))
        {
            return first;
        }

        first = next;
    }

    return last;
}

template<typename ForwardIterator>
constexpr ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
{
    return cpputil::adjacent_find_impl(first, last, make_iter_eq_to_iter());
}

template<typename ForwardIterator, typename Predicate>
constexpr ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    return cpputil::adjacent_find_impl(first, last, make_iter_comp_to_iter(pred));
}

} // namespace cpputil