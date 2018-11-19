#ifndef CPPUTIL_ADVANCE_HPP
#define CPPUTIL_ADVANCE_HPP

#include "iterator_traits.hpp"

namespace cpputil
{

template<typename InputIterator>
constexpr auto advance_impl(InputIterator& it, difference_type_t<InputIterator> n, input_iterator_tag)
{
    while (n--) { ++it; }
}

template<typename InputIterator>
constexpr auto advance_impl(InputIterator& it, difference_type_t<InputIterator> n, bidirectional_iterator_tag)
{
    if (n > 0)
    {
        while (n--) { ++it; }
    }
    else
    {
        while (n++) { --it; }
    }
}

template<typename InputIterator>
constexpr auto advance_impl(InputIterator& it, difference_type_t<InputIterator> n, random_access_iterator_tag)
{
    it += n;
}

template<typename InputIterator>
constexpr auto advance(InputIterator& it, difference_type_t<InputIterator> n)
{
    advance_impl(it, n, iterator_category_t<InputIterator>{});
}

} // namespace cpputil

#endif // CPPUTIL_ADVANCE_HPP
