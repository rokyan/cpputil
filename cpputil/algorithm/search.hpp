#ifndef CPPUTIL_ALGORITHM_SEARCH_HPP
#define CPPUTIL_ALGORITHM_SEARCH_HPP

#include <predicates.hpp>

namespace cpputil
{

namespace impl_details
{

// TODO: clean up the implementation
template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto search(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
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

            if (!pred(it1, it2))
            {
                break;
            }

            ++it1; ++it2;
        }

        if (it2 == last2) { break; }
    }

    return first1;
}

} // namespace impl_details

template<typename ForwardIterator1, typename ForwardIterator2>
constexpr auto search(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2) -> ForwardIterator1
{
    return impl_details::search(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto search(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
{
    return impl_details::search(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_SEARCH_HPP
