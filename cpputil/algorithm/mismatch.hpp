#pragma once

#include <utility>

namespace cpputil
{

template<typename InputIterator1, typename InputIterator2, typename Predicate>
constexpr std::pair<InputIterator1, InputIterator2> mismatch_impl(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, Predicate pred)
{
    while (first1 != last1 && pred(first1 ,first2))
    {
        ++first1; ++first2;
    }

    return std::make_pair(first1, first2);
}

template<typename InputIterator1, typename InputIterator2, typename Predicate>
constexpr std::pair<InputIterator1, InputIterator2>mismatch_impl(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Predicate pred)
{
    while (first1 != last1 && first2 != last2 && pred(first1 ,first2))
    {
        ++first1; ++first2;
    }

    return std::make_pair(first1, first2);
}

template<typename InputIterator1, typename InputIterator2>
constexpr std::pair<InputIterator1, InputIterator2>mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    return cpputil::mismatch_impl(first1, last1, first2, make_iter_eq_to_iter());
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
constexpr std::pair<InputIterator1, InputIterator2>mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
    return cpputil::mismatch_impl(first1, last1, first2, make_iter_comp_to_iter(pred));
}

template<typename InputIterator1, typename InputIterator2>
constexpr std::pair<InputIterator1, InputIterator2>mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
    return cpputil::mismatch_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
constexpr std::pair<InputIterator1, InputIterator2>mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, BinaryPredicate pred)
{
    return cpputil::mismatch_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

} // namespace cpputil