#ifndef CPPUTIL_ALGORITHM_FIND_FIRST_OF_HPP
#define CPPUTIL_ALGORITHM_FIND_FIRST_OF_HPP

#include <predicates.hpp>

namespace cpputil
{

namespace impl_details
{

template<typename InputIterator, typename ForwardIterator, typename Predicate>
constexpr auto find_first_of(InputIterator first1, InputIterator last1,
    ForwardIterator first2, ForwardIterator last2, Predicate pred) -> InputIterator
{
    for (; first1 != last1; ++first1)
    {
        for (ForwardIterator iter = first2; iter != last2; ++iter)
        {
            if (pred(iter, first1))
            {
                return first1;
            }
        }
    }

    return first1;
}

} // namespace impl_details

template<typename InputIterator, typename ForwardIterator>
constexpr auto find_first_of(InputIterator first1, InputIterator last1,
    ForwardIterator first2, ForwardIterator last2) -> InputIterator
{
    return impl_details::find_first_of(first1, last1, first2, last2,
        make_iter_eq_to_iter());
}

template<typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
constexpr auto find_first_of(InputIterator first1, InputIterator last1,
    ForwardIterator first2, ForwardIterator last2, BinaryPredicate pred) -> InputIterator
{
    return impl_details::find_first_of(first1, last1, first2, last2,
        make_iter_comp_to_iter(pred));
}

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_FIND_FIRST_OF_HPP
