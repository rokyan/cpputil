#ifndef CPPUTIL_ALGORITHM_RANGE_CHECK_HPP
#define CPPUTIL_ALGORITHM_RANGE_CHECK_HPP

#include <find.hpp>

namespace cpputil
{

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

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_RANGE_CHECK_HPP
