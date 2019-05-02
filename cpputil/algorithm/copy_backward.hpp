#pragma once

namespace cpputil
{

template<typename BidirectionalIterator1, typename BidirectionalIterator2>
constexpr BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 dest)
{
    while (first != last)
    {
        *(--dest) = *(--last);
    }

    return dest;
}

} // namespace cpputil