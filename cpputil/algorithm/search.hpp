#ifndef CPPUTIL_ALGORITHM_SEARCH_HPP
#define CPPUTIL_ALGORITHM_SEARCH_HPP

#include <predicates.hpp>

namespace cpputil
{

namespace impl_details
{

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto search(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
{
    for (; first1 != last1; ++first1)
    {
        ForwardIterator1 first_range_it = first1;

        for (ForwardIterator2 second_range_it = first2; ;
            ++first_range_it, static_cast<void>(++second_range_it))
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
