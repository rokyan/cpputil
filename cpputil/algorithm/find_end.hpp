#pragma once

#include "predicates.hpp"
#include "search.hpp"

namespace cpputil
{

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr ForwardIterator1 find_end_impl(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred)
{
    if (first2 == last2)
    {
        return last1;
    }

    ForwardIterator1 result = last1;

    for (; first1 != last1; ++first1)
    {
        ForwardIterator1 found_pos = cpputil::search_impl(first1, last1, first2, last2, pred);

        if (found_pos != last1)
        {
            result = found_pos;
        }
        else
        {
            break;
        }

        first1 = found_pos;
    }

    return result;
}

template<typename ForwardIterator1, typename ForwardIterator2>
constexpr ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
    return cpputil::find_end_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr ForwardIterator2 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred)
{
    return cpputil::find_end_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

} // namespace cpputil