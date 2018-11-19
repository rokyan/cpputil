#ifndef CPPUTIL_NEXT_HPP
#define CPPUTIL_NEXT_HPP

#include "advance.hpp"
#include "iterator_traits.hpp"

namespace cpputil
{

template<typename InputIterator>
constexpr auto next(InputIterator it, difference_type_t<InputIterator> n = 1) -> InputIterator
{
    cpputil::advance(it, n);
    return it;
}

} // namespace cpputil

#endif // CPPUTIL_NEXT_HPP
