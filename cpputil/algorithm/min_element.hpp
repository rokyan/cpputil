#pragma once

namespace cpputil
{

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

} // namespace cpputil