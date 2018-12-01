#ifndef CPPUTIL_ALGORITHM_PREDICATES_HPP
#define CPPUTIL_ALGORITHM_PREDICATES_HPP

#include <utility.hpp>

namespace cpputil
{

struct eq_predicate
{
    template<typename T1, typename T2>
    constexpr auto operator()(T1&& left, T2&& right) const -> bool
    {
        return cpputil::forward<T1>(left) == cpputil::forward<T2>(right);
    }
};

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_PREDICATES_HPP
