#ifndef CPPUTIL_ALGORITHM_ADJANCENT_FIND_HPP
#define CPPUTIL_ALGORITHM_ADJANCENT_FIND_HPP

#include <predicates.hpp>

namespace cpputil
{

namespace impl_details
{

template<typename ForwardIterator, typename Predicate>
constexpr auto adjacent_find(ForwardIterator first, ForwardIterator last, Predicate pred) -> ForwardIterator
{
    if (first == last)
    {
        return last;
    }

    ForwardIterator next = first;

    while (++next != last)
    {
        if (pred(first, next))
        {
            return first;
        }

        first = next;
    }

    return last;
}

} // namespace impl_details

template<typename ForwardIterator>
constexpr auto adjacent_find(ForwardIterator first, ForwardIterator last) -> ForwardIterator
{
    return impl_details::adjacent_find(first, last, make_iter_eq_to_iter());
}

template<typename ForwardIterator, typename Predicate>
constexpr auto adjacent_find(ForwardIterator first, ForwardIterator last, Predicate pred) -> ForwardIterator
{
    return impl_details::adjacent_find(first, last, make_iter_comp_to_iter(pred));
}

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_ADJANCENT_FIND_HPP
