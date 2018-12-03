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

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_FIND_HPP
