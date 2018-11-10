#ifndef CPPUTIL_FIND_HPP
#define CPPUTIL_FIND_HPP

namespace cpputil
{
    template<typename InputIterator, typename T>
    constexpr auto find(InputIterator first, InputIterator last, const T& value) ->
        InputIterator
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
    constexpr auto find_if(InputIterator first, InputIterator last, UnaryPredicate predicate) ->
        InputIterator
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
    constexpr auto find_if_not(InputIterator first, InputIterator last, UnaryPredicate predicate) ->
        InputIterator
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
}

#endif // CPPUTIL_FIND_HPP