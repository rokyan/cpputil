#pragma once

#include <utility>

namespace cpputil
{

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

} // namespace cpputil