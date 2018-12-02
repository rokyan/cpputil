#ifndef CPPUTIL_ALGORITHM_FIND_HPP
#define CPPUTIL_ALGORITHM_FIND_HPP

#include <predicates.hpp>

namespace cpputil
{

namespace impl_details
{

template<typename InputIterator, typename Predicate>
constexpr auto find(InputIterator first, InputIterator last, Predicate pred) -> InputIterator
{
    for (; first != last; ++first)
    {
        if (pred(first)) { return first; }
    }

    return last;
}

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

template<typename InputIterator, typename T>
constexpr auto find(InputIterator first, InputIterator last, const T& value) -> InputIterator
{
    return impl_details::find(first, last, make_iter_eq_to_val(value));
}

template<typename InputIterator, typename UnaryPredicate>
constexpr auto find_if(InputIterator first, InputIterator last, UnaryPredicate pred) -> InputIterator
{
    return impl_details::find(first, last, make_iter_pred(pred));
}

template<typename InputIterator, typename UnaryPredicate>
constexpr auto find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred) -> InputIterator
{
    return impl_details::find(first, last, make_iter_neg_pred(pred));
}

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

#endif // CPPUTIL_ALGORITHM_FIND_HPP
