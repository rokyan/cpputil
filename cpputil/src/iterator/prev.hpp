#ifndef CPPUTIL_PREV_HPP
#define CPPUTIL_PREV_HPP

#include "advance.hpp"
#include "iterator_traits.hpp"

namespace cpputil
{

    template<typename BidirectionalIterator>
    constexpr auto prev(BidirectionalIterator it, difference_type_t<BidirectionalIterator> n = 1) -> BidirectionalIterator
    {
        cpputil::advance(it, -n);
        return it;
    }

} // namespace cpputil

#endif // CPPUTIL_PREV_HPP