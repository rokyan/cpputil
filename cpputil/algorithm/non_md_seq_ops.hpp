#pragma once

#include "predicates.hpp"
#include <iterator.hpp>

#include <utility> // for std::pair and std::make_pair

namespace cpputil
{

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr ForwardIterator1 search_impl(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred)
{
    for (; first1 != last1; ++first1)
    {
        ForwardIterator1 first_range_it = first1;

        for (ForwardIterator2 second_range_it = first2; ; ++first_range_it, static_cast<void>(++second_range_it))
        {
            if (second_range_it == last2)
            {
                return first1;
            }

            if (first_range_it == last1)
            {
                return last1;
            }

            if (!pred(first_range_it, second_range_it))
            {
                break;
            }
        }

    }

    return first1;
}

template<typename ForwardIterator1, typename ForwardIterator2>
constexpr ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
    return cpputil::search_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred)
{
    return cpputil::search_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

template<typename InputIterator, typename Predicate>
constexpr InputIterator find_impl(InputIterator first, InputIterator last, Predicate pred)
{
    for (; first != last; ++first)
    {
        if (pred(first))
        {
            return first;
        }
    }

    return last;
}

template<typename InputIterator, typename T>
constexpr InputIterator find(InputIterator first, InputIterator last, const T& value)
{
    return cpputil::find_impl(first, last, make_iter_eq_to_val(value));
}

template<typename InputIterator, typename UnaryPredicate>
constexpr InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    return cpputil::find_impl(first, last, make_iter_pred(pred));
}

template<typename InputIterator, typename UnaryPredicate>
constexpr InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    return cpputil::find_impl(first, last, make_iter_neg_pred(pred));
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr ForwardIterator1 find_end_impl(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred)
{
    if (first2 == last2)
    {
        return last1;
    }

    ForwardIterator1 result = last1;

    for (; first1 != last1; ++first1)
    {
        ForwardIterator1 found_pos = cpputil::search_impl(first1, last1, first2, last2, pred);

        if (found_pos != last1)
        {
            result = found_pos;
        }
        else
        {
            break;
        }

        first1 = found_pos;
    }

    return result;
}

template<typename ForwardIterator1, typename ForwardIterator2>
constexpr ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
    return cpputil::find_end_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr ForwardIterator2 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred)
{
    return cpputil::find_end_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

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

template<typename ForwardIterator, typename Predicate>
constexpr ForwardIterator adjacent_find_impl(ForwardIterator first, ForwardIterator last, Predicate pred)
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

template<typename ForwardIterator>
constexpr ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
{
    return cpputil::adjacent_find_impl(first, last, make_iter_eq_to_iter());
}

template<typename ForwardIterator, typename Predicate>
constexpr ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    return cpputil::adjacent_find_impl(first, last, make_iter_comp_to_iter(pred));
}

template<typename InputIterator, typename Predicate>
constexpr bool all_of(InputIterator first, InputIterator last, Predicate predicate)
{
    return cpputil::find_if_not(first, last, predicate) == last;
}

template<typename InputIterator, typename Predicate>
constexpr bool any_of(InputIterator first, InputIterator last, Predicate predicate)
{
    return cpputil::find_if(first, last, predicate) != last;
}

template<typename InputIterator, typename Predicate>
constexpr bool none_of(InputIterator first, InputIterator last, Predicate predicate)
{
    return cpputil::find_if(first, last, predicate) == last;
}

template<typename InputIterator, typename Function>
constexpr Function for_each(InputIterator first, InputIterator last, Function func)
{
    for (; first < last; ++first)
    {
        func(*first);
    }

    return func;
}

template<typename InputIterator, typename T, typename Function>
constexpr Function for_each_n(InputIterator first, T n, Function func)
{
    for (T i = 0; i < n; ++first, static_cast<void>(++i))
    {
        func(*first);
    }

    return func;
}

template<typename InputIterator, typename Predicate>
constexpr cpputil::difference_type_t<InputIterator>count_impl(InputIterator first, InputIterator last, Predicate pred)
{
    cpputil::difference_type_t<InputIterator> total = 0;

    for (; first != last; ++first)
    {
        if (pred(first)) { total++; }
    }

    return total;
}

template<typename InputIterator, typename T>
constexpr cpputil::difference_type_t<InputIterator> count(InputIterator first, InputIterator last, const T& value)
{
    return cpputil::count_impl(first, last, make_iter_eq_to_val(value));
}

template<typename InputIterator, typename Predicate>
constexpr cpputil::difference_type_t<InputIterator> count_if(InputIterator first, InputIterator last, Predicate pred)
{
    return cpputil::count_impl(first, last, make_iter_pred(pred));
}

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
