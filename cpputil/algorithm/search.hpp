#ifndef CPPUTIL_SEARCH_HPP
#define CPPUTIL_SEARCH_HPP

#include "predicates.hpp"

namespace cpputil
{

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto search_impl(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate predicate) -> ForwardIterator1
{
    if (first2 == last2 || first1 == last1)
    {
        return first1;
    }

    for (; first1 != last1; ++first1)
    {
        ForwardIterator1 it1 = first1;
        ForwardIterator2 it2 = first2;

        while (it2 != last2)
        {
            if (it1 == last1)
            {
                return last1;
            }

            if (!predicate(*it1, *it2))
            {
                break;
            }

            ++it1; ++it2;
        }

        if (it2 == last2) { break; }
    }

    return first1;
}

template<typename ForwardIterator1, typename ForwardIterator2>
constexpr auto search(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2) -> ForwardIterator1
{
    return search_impl(first1, last1, first2, last2, eq_predicate{});
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto search(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate predicate) -> ForwardIterator1
{
    return search_impl(first1, last1, first2, last2, predicate);
}

} // namespace cpputil

#endif // CPPUTIL_SEARCH_HPP
