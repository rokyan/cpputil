#ifndef CPPUTIL_MISMATCH_HPP
#define CPPUTIL_MISMATCH_HPP

#include <utility>

namespace cpputil
{

template<typename InputIterator1, typename InputIterator2>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2) -> std::pair<InputIterator1, InputIterator2>
{
    while (first1 != last1 && *first1 == *first2)
    {
        ++first1; ++first2;
    }

    return std::pair{ first1, first2 };
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, BinaryPredicate predicate) -> std::pair<InputIterator1, InputIterator2>
{
    while (first1 != last1 && predicate(*first1 ,*first2))
    {
        ++first1; ++first2;
    }

    return std::pair{ first1, first2 };
}

template<typename InputIterator1, typename InputIterator2>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2) -> std::pair<InputIterator1, InputIterator2>
{
    while (first1 != last1 && first2 != last2 && *first1 == *first2)
    {
        ++first1; ++first2;
    }

    return std::pair{ first1, first2 };
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, BinaryPredicate predicate) -> std::pair<InputIterator1, InputIterator2>
{
    while (first1 != last1 && first2 != last2 && predicate(*first1 ,*first2))
    {
        ++first1; ++first2;
    }

    return std::pair{ first1, first2 };
}

} // namespace cpputil

#endif // CPPUTIL_MISMATCH_HPP
