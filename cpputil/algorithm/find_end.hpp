#ifndef CPPUTIL_ALGORITHM_FIND_END_HPP
#define CPPUTIL_ALGORITHM_FIND_END_HPP

#include <predicates.hpp>
#include <search.hpp>

namespace cpputil
{

namespace impl_details
{

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto find_end(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
{
    if (first2 == last2)
    {
        return last1;
    }

    ForwardIterator1 result = last1;

    for (; first1 != last1; ++first1)
    {
        ForwardIterator1 found_pos = cpputil::impl_details::search(first1, last1, first2, last2, pred);

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

} // namespace impl_details

template<typename ForwardIterator1, typename ForwardIterator2>
constexpr auto find_end(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2) -> ForwardIterator1
{
    return impl_details::find_end(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto find_end(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
{
    return impl_details::find_end(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_FIND_END_HPP
