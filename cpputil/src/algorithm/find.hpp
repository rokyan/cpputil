#ifndef CPPUTIL_FIND_HPP
#define CPPUTIL_FIND_HPP

namespace cpputil
{

template<typename InputIterator, typename T>
constexpr auto find(InputIterator first, InputIterator last, const T& value) -> InputIterator
{
    for (; first != last; ++first)
    {
        if (*first == value)
        {
            return first;
        }
    }

    return first;
}

template<typename InputIterator, typename UnaryPredicate>
constexpr auto find_if(InputIterator first, InputIterator last, UnaryPredicate predicate) -> InputIterator
{
    for (; first != last; ++first)
    {
        if (predicate(*first))
        {
            return first;
        }
    }

    return first;
}

template<typename InputIterator, typename UnaryPredicate>
constexpr auto find_if_not(InputIterator first, InputIterator last, UnaryPredicate predicate) -> InputIterator
{
    for (; first != last; ++first)
    {
        if (!predicate(*first))
        {
            return first;
        }
    }

    return first;
}

template<typename InputIterator, typename ForwardIterator>
constexpr auto find_first_of(InputIterator first1, InputIterator last1,
    ForwardIterator first2, ForwardIterator last2) -> InputIterator
{
    for (; first1 != last1; ++first1)
    {
        for (ForwardIterator iter = first2; iter != last2; ++iter)
        {
            if (*iter == *first1)
            {
                return first1;
            }
        }
    }

    return first1;
}

template<typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
constexpr auto find_first_of(InputIterator first1, InputIterator last1,
    ForwardIterator first2, ForwardIterator last2, BinaryPredicate predicate) -> InputIterator
{
    for (; first1 != last1; ++first1)
    {
        for (ForwardIterator iter = first2; iter != last2; ++iter)
        {
            if (predicate(*iter, *first1))
            {
                return first1;
            }
        }
    }

    return first1;
}

} // namespace cpputil

#endif // CPPUTIL_FIND_HPP
