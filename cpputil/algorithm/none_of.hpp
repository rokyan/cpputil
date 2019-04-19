#pragma once

#include "find.hpp"

namespace cpputil
{

template<typename InputIterator, typename Predicate>
constexpr bool none_of(InputIterator first, InputIterator last, Predicate predicate)
{
    return cpputil::find_if(first, last, predicate) == last;
}

} // namespace cpputil