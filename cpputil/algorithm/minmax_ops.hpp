#pragma once

#include <predicates.hpp>

#include <initializer_list> // for std::initializer_list
#include <utility> // for std::pair and std::make_pair

namespace cpputil
{

// Max element.

template<typename ForwardIt, typename Comp>
constexpr ForwardIt max_element_impl(ForwardIt first, ForwardIt last, Comp comp)
{
    // Optimize for empty ranges.

    if (first == last)
    {
        return last;
    }

    // Do not use post-increment to avoid unnecessary copying.

    ForwardIt it = first;

    while (++first != last)
    {
        if (comp(it, first))
        {
            it = first;
        }
    }

    return it;
}

template<typename ForwardIt>
constexpr ForwardIt max_element(ForwardIt first, ForwardIt last)
{
    return cpputil::max_element_impl(first, last, make_iter_less_then_iter());
}

template<typename ForwardIt, typename Comp>
constexpr ForwardIt max_element(ForwardIt first, ForwardIt last, Comp comp)
{
    return cpputil::max_element_impl(first, last, make_iter_comp_to_iter(comp));
}


// Min element.

template<typename ForwardIt, typename Comp>
constexpr ForwardIt min_element_impl(ForwardIt first, ForwardIt last, Comp comp)
{
    // Optimize for empty ranges.

    if (first == last)
    {
        return last;
    }

    // Do not use post-increment to avoid unnecessary copying.

    ForwardIt it = first;

    while (++first != last)
    {
        if (comp(first, it))
        {
            it = first;
        }
    }

    return it;
}

template<typename ForwardIt>
constexpr ForwardIt min_element(ForwardIt first, ForwardIt last)
{
    return cpputil::min_element_impl(first, last, make_iter_less_then_iter());
}

template<typename ForwardIt, typename Comp>
constexpr ForwardIt min_element(ForwardIt first, ForwardIt last, Comp comp)
{
    return cpputil::min_element_impl(first, last, make_iter_comp_to_iter(comp));
}

// Minmax element.

template<typename ForwardIt, typename Comp>
constexpr std::pair<ForwardIt, ForwardIt> minmax_element_impl(ForwardIt first, ForwardIt last, Comp comp)
{
    ForwardIt next = first;

    // Optimize for empty ranges and ranges which consist of a single element.

    if (first == last || ++next == last)
    {
        return std::make_pair(first, first);
    }

    // The range consists of at least two elements.

    ForwardIt min, max;

    if (comp(first, next))
    {
        min = first;
        max = next;
    }
    else
    {
        min = next;
        max = first;
    }

    first = next;

    while (++first != last)
    {
        next = first;

        // Only a single element left.

        if (++next == last)
        {
            if (comp(first, min))
            {
                min = first;
            }
            else if (!comp(first, max))
            {
                max = first;
            }

            break;
        }

        // Update min and max doing 3 comparisons in total. Very neat!

        if (comp(first, next))
        {
            if (comp(first, min))
            {
                min = first;
            }

            if (!comp(next, max))
            {
                max = next;
            }
        }
        else
        {
            if (comp(next, min))
            {
                min = next;
            }

            if (!comp(first, max))
            {
                max = first;
            }
        }

        // Update first.

        first = next;
    }

    return std::make_pair(min, max);
}

template<typename ForwardIt>
constexpr std::pair<ForwardIt, ForwardIt> minmax_element(ForwardIt first, ForwardIt last)
{
    return cpputil::minmax_element_impl(first, last, make_iter_less_then_iter());
}

template<typename ForwardIt, typename Comp>
constexpr std::pair<ForwardIt, ForwardIt> minmax_element(ForwardIt first, ForwardIt last, Comp comp)
{
    return cpputil::minmax_element_impl(first, last, make_iter_comp_to_iter(comp));
}

// Max.

template<typename T>
constexpr const T& max(const T& x, const T& y)
{
    return (y < x) ? x : y;
}

template<typename T, typename Comp>
constexpr const T& max(const T& x, const T& y, Comp comp)
{
    return comp(y, x) ? x : y;
}

template<typename T>
constexpr const T& max(std::initializer_list<T> list)
{
    return *cpputil::max_element(list.begin(), list.end());
}

template<typename T, typename Comp>
constexpr const T& max(std::initializer_list<T> list, Comp comp)
{
    return *cpputil::max_element(list.begin(), list.end(), comp);
}

// Min.

template<typename T>
constexpr const T& min(const T& x, const T& y)
{
    return (x < y) ? x : y;
}

template<typename T, typename Comp>
constexpr const T& min(const T& x, const T& y, Comp comp)
{
    return comp(x, y) ? x : y;
}

template<typename T>
constexpr const T& min(std::initializer_list<T> list)
{
    return *cpputil::min_element(list.begin(), list.end());
}

template<typename T, typename Comp>
constexpr const T& min(std::initializer_list<T> list, Comp comp)
{
    return *cpputil::min_element(list.begin(), list.end(), comp);
}

// Minmax.

template<typename T>
constexpr std::pair<const T&, const T&> minmax(const T& x, const T& y)
{
    using ret_type = std::pair<const T&, const T&>;
    return (x < y) ? ret_type(x, y) : ret_type(y, x);
}

template<typename T, typename Comp>
constexpr std::pair<const T&, const T&> minmax(const T& x, const T& y, Comp comp)
{
    using ret_type = std::pair<const T&, const T&>;
    return comp(x, y) ? ret_type(x, y) : ret_type(y, x);
}

template<typename T>
constexpr std::pair<T, T> minmax(std::initializer_list<T> list)
{
    const auto it_pr = cpputil::minmax_element(list.begin(), list.end());
    return std::make_pair(*it_pr.first, *it_pr.second);
}

template<typename T, typename Comp>
constexpr std::pair<T, T> minmax(std::initializer_list<T> list, Comp comp)
{
    const auto it_pr = cpputil::minmax_element(list.begin(), list.end(), comp);
    return std::make_pair(*it_pr.first, *it_pr.second);
}

// Clamp.

template<typename T>
constexpr const T& clamp(const T& value, const T& lo, const T& hi)
{
    if (value < lo)
    {
        return lo;
    }

    if (hi < value)
    {
        return hi;
    }

    return value;
}

template<typename T, typename Comp>
constexpr const T& clamp(const T& value, const T& lo, const T& hi, Comp comp)
{
    if (comp(value, lo))
    {
        return lo;
    }

    if (comp(hi, value))
    {
        return hi;
    }

    return value;
}

} // namespace cpputi
