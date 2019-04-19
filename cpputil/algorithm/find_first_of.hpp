#pragma once

#include "predicates.hpp"

namespace cpputil
{

template<typename InputIterator, typename ForwardIterator, typename Predicate>
constexpr InputIterator find_first_of_impl(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2, Predicate pred)
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

template<typename InputIterator, typename ForwardIterator>
constexpr InputIterator find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2)
{
    return cpputil::find_first_of_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
constexpr InputIterator find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2, BinaryPredicate pred)
{
    return cpputil::find_first_of_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

} // namespace cpputil