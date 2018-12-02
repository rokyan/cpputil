#ifndef CPPUTIL_ALGORITHM_MISMATCH_HPP
#define CPPUTIL_ALGORITHM_MISMATCH_HPP

#include <predicates.hpp>
#include <utility> // For std::pair. Remove in the future.

namespace cpputil
{

namespace impl_details
{

template<typename InputIterator1, typename InputIterator2, typename Predicate>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, Predicate pred) -> std::pair<InputIterator1, InputIterator2>
{
    while (first1 != last1 && pred(first1 ,first2))
    {
        ++first1; ++first2;
    }

    return std::pair{ first1, first2 };
}

template<typename InputIterator1, typename InputIterator2, typename Predicate>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Predicate pred) -> std::pair<InputIterator1, InputIterator2>
{
    while (first1 != last1 && first2 != last2 && pred(first1 ,first2))
    {
        ++first1; ++first2;
    }

    return std::pair{ first1, first2 };
}

} // namespace impl_details

template<typename InputIterator1, typename InputIterator2>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2) -> std::pair<InputIterator1, InputIterator2>
{
    return impl_details::mismatch(first1, last1, first2, make_iter_eq_to_iter());
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, BinaryPredicate pred) -> std::pair<InputIterator1, InputIterator2>
{
    return impl_details::mismatch(first1, last1, first2, make_iter_comp_to_iter(pred));
}

template<typename InputIterator1, typename InputIterator2>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2) -> std::pair<InputIterator1, InputIterator2>
{
    return impl_details::mismatch(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, BinaryPredicate pred) -> std::pair<InputIterator1, InputIterator2>
{
    return impl_details::mismatch(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_MISMATCH_HPP
