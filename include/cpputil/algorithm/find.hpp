#ifndef CPPUTIL_FIND_HPP
#define CPPUTIL_FIND_HPP

namespace cpputil
{
    template<typename InputIterator, typename T>
    constexpr InputIterator find(InputIterator first, InputIterator last, const T& value)
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
    constexpr InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate predicate)
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
    constexpr InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate predicate)
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