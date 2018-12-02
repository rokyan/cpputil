#ifndef CPPUTIL_ALGORITHM_COUNT_HPP
#define CPPUTIL_ALGORITHM_COUNT_HPP

#include <iterator_traits.hpp>
#include <predicates.hpp>

namespace cpputil
{

namespace impl_details
{

template<typename InputIterator, typename Predicate>
constexpr auto count(InputIterator first, InputIterator last, Predicate pred)
    -> difference_type_t<InputIterator>
{
    difference_type_t<InputIterator> total = 0;

    for (; first != last; ++first)
    {
        if (pred(first)) { total++; }
    }

    return total;
}

} // namespace impl_details

template<typename InputIterator, typename T>
constexpr auto count(InputIterator first, InputIterator last, const T& value)
    -> difference_type_t<InputIterator>
{
    return impl_details::count(first, last, make_iter_eq_to_val(value));
}

template<typename InputIterator, typename Predicate>
constexpr auto count_if(InputIterator first, InputIterator last, Predicate pred)
    -> difference_type_t<InputIterator>
{
    return impl_details::count(first, last, make_iter_pred(pred));
}

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_COUNT_HPP
