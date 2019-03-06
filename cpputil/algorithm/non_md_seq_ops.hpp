#ifndef CPPUTIL_ALGORITHM_NON_MD_SEQ_OPS_HPP
#define CPPUTIL_ALGORITHM_NON_MD_SEQ_OPS_HPP

#include "predicates.hpp"
#include <iterator.hpp>

namespace cpputil
{

template<typename InputIterator, typename Predicate>
constexpr auto find_impl(InputIterator first, InputIterator last, Predicate pred) -> InputIterator
{
    for (; first != last; ++first)
    {
        if (pred(first)) { return first; }
    }

    return last;
}

template<typename InputIterator, typename T>
constexpr auto find(InputIterator first, InputIterator last, const T& value) -> InputIterator
{
    return cpputil::find_impl(first, last, make_iter_eq_to_val(value));
}

template<typename InputIterator, typename UnaryPredicate>
constexpr auto find_if(InputIterator first, InputIterator last, UnaryPredicate pred) -> InputIterator
{
    return cpputil::find_impl(first, last, make_iter_pred(pred));
}

template<typename InputIterator, typename UnaryPredicate>
constexpr auto find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred) -> InputIterator
{
    return cpputil::find_impl(first, last, make_iter_neg_pred(pred));
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto find_end_impl(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
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
constexpr auto find_end(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2) -> ForwardIterator1
{
    return cpputil::find_end_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto find_end(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
{
    return cpputil::find_end_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

template<typename InputIterator, typename ForwardIterator, typename Predicate>
constexpr auto find_first_of_impl(InputIterator first1, InputIterator last1,
    ForwardIterator first2, ForwardIterator last2, Predicate pred) -> InputIterator
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
constexpr auto find_first_of(InputIterator first1, InputIterator last1,
    ForwardIterator first2, ForwardIterator last2) -> InputIterator
{
    return cpputil::find_first_of_impl(first1, last1, first2, last2,
        make_iter_eq_to_iter());
}

template<typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
constexpr auto find_first_of(InputIterator first1, InputIterator last1,
    ForwardIterator first2, ForwardIterator last2, BinaryPredicate pred) -> InputIterator
{
    return cpputil::find_first_of_impl(first1, last1, first2, last2,
        make_iter_comp_to_iter(pred));
}

template<typename ForwardIterator, typename Predicate>
constexpr auto adjacent_find_impl(ForwardIterator first, ForwardIterator last, Predicate pred) -> ForwardIterator
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
constexpr auto adjacent_find(ForwardIterator first, ForwardIterator last) -> ForwardIterator
{
    return cpputil::adjacent_find_impl(first, last, make_iter_eq_to_iter());
}

template<typename ForwardIterator, typename Predicate>
constexpr auto adjacent_find(ForwardIterator first, ForwardIterator last, Predicate pred) -> ForwardIterator
{
    return cpputil::adjacent_find_impl(first, last, make_iter_comp_to_iter(pred));
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto search_impl(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
{
    for (; first1 != last1; ++first1)
    {
        ForwardIterator1 first_range_it = first1;

        for (ForwardIterator2 second_range_it = first2; ;
            ++first_range_it, static_cast<void>(++second_range_it))
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
constexpr auto search(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2) -> ForwardIterator1
{
    return cpputil::search_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename ForwardIterator1, typename ForwardIterator2, typename Predicate>
constexpr auto search(ForwardIterator1 first1, ForwardIterator1 last1,
    ForwardIterator2 first2, ForwardIterator2 last2, Predicate pred) -> ForwardIterator1
{
    return cpputil::search_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

template<typename InputIterator, typename Predicate>
constexpr auto all_of(InputIterator first, InputIterator last, Predicate predicate) -> bool
{
    return cpputil::find_if_not(first, last, predicate) == last;
}

template<typename InputIterator, typename Predicate>
constexpr auto any_of(InputIterator first, InputIterator last, Predicate predicate) -> bool
{
    return cpputil::find_if(first, last, predicate) != last;
}

template<typename InputIterator, typename Predicate>
constexpr auto none_of(InputIterator first, InputIterator last, Predicate predicate) -> bool
{
    return cpputil::find_if(first, last, predicate) == last;
}

template<typename InputIterator, typename Function>
constexpr auto for_each(InputIterator first, InputIterator last, Function func) -> Function
{
    for (; first < last; ++first)
    {
        func(*first);
    }

    return func;
}

template<typename InputIterator, typename T, typename Function>
constexpr auto for_each_n(InputIterator first, T n, Function func) -> Function
{
    for (T i = 0; i < n; ++first, static_cast<void>(++i))
    {
        func(*first);
    }

    return func;
}

template<typename InputIterator, typename Predicate>
constexpr auto count_impl(InputIterator first, InputIterator last, Predicate pred)
    -> cpputil::difference_type_t<InputIterator>
{
    cpputil::difference_type_t<InputIterator> total = 0;

    for (; first != last; ++first)
    {
        if (pred(first)) { total++; }
    }

    return total;
}

template<typename InputIterator, typename T>
constexpr auto count(InputIterator first, InputIterator last, const T& value)
    -> cpputil::difference_type_t<InputIterator>
{
    return cpputil::count_impl(first, last, make_iter_eq_to_val(value));
}

template<typename InputIterator, typename Predicate>
constexpr auto count_if(InputIterator first, InputIterator last, Predicate pred)
    -> cpputil::difference_type_t<InputIterator>
{
    return cpputil::count_impl(first, last, make_iter_pred(pred));
}

template<typename InputIterator1, typename InputIterator2, typename Predicate>
constexpr auto mismatch_impl(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, Predicate pred) -> std::pair<InputIterator1, InputIterator2>
{
    while (first1 != last1 && pred(first1 ,first2))
    {
        ++first1; ++first2;
    }

    return std::pair{ first1, first2 };
}

template<typename InputIterator1, typename InputIterator2, typename Predicate>
constexpr auto mismatch_impl(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Predicate pred) -> std::pair<InputIterator1, InputIterator2>
{
    while (first1 != last1 && first2 != last2 && pred(first1 ,first2))
    {
        ++first1; ++first2;
    }

    return std::pair{ first1, first2 };
}

template<typename InputIterator1, typename InputIterator2>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2) -> std::pair<InputIterator1, InputIterator2>
{
    return cpputil::mismatch_impl(first1, last1, first2, make_iter_eq_to_iter());
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, BinaryPredicate pred) -> std::pair<InputIterator1, InputIterator2>
{
    return cpputil::mismatch_impl(first1, last1, first2, make_iter_comp_to_iter(pred));
}

template<typename InputIterator1, typename InputIterator2>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2) -> std::pair<InputIterator1, InputIterator2>
{
    return cpputil::mismatch_impl(first1, last1, first2, last2, make_iter_eq_to_iter());
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
constexpr auto mismatch(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, BinaryPredicate pred) -> std::pair<InputIterator1, InputIterator2>
{
    return cpputil::mismatch_impl(first1, last1, first2, last2, make_iter_comp_to_iter(pred));
}

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_NON_MD_SEQ_OPS_HPP
