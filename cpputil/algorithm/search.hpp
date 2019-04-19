#pragma once

#include "predicates.hpp"

namespace cpputil
{

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr ForwardIterator1 search_impl(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred)
{
    for (; first1 != last1; ++first1)
    {
        ForwardIterator1 first_range_it = first1;

        for (ForwardIterator2 second_range_it = first2; ; ++first_range_it, static_cast<void>(++second_range_it))
        {
            if (second_range_it == last2)
            {
                return first1;
            }

            if (first_range_it == last1)
            {
                return last1;
            }

            if (!pred(first_range_it, second_range_it))
            {
                break;
            }
        }

    }

    return first1;
}

template<typename ForwardIterator1, typename ForwardIterator2>
constexpr ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
    return cpputil::search_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred)
{
    return cpputil::search_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

} // namespace cpputil
