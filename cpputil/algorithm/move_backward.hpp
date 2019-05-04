#pragma once

#include <utility.hpp>

namespace cpputil
{

template<typename BidirectionalIterator1, typename BidirectionalIterator2>
constexpr BidirectionalIterator2 move_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 dest)
{
    while (first != last)
    {
        *(--dest) = cpputil::move(*(--last));
    }

    return dest;
}

} // namespace cpputil