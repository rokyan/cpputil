#ifndef CPPUTIL_APPLY_HPP
#define CPPUTIL_APPLY_HPP

#include <utility> // for std::tuple and std::index_sequence.
#include <forward.hpp>

namespace cpputil
{
    namespace detail
    {
        template<typename Func, typename Tuple, std::size_t... Is>
        decltype(auto) apply(Func&& f, Tuple&& t, std::index_sequence<Is...>)
        {
            return std::invoke(cpputil::forward<Func>(f), std::get<Is>(t)...);
        }
    }

    template<typename Func, typename Tuple>
    decltype(auto) apply(Func&& f, Tuple&& t)
    {
        using index_sequence_type = std::make_index_sequence<std::tuple_size_v<std::decay_t<Tuple>>>;

        return detail::apply(cpputil::forward<Func>(f), cpputil::forward<Tuple>(t), index_sequence_type{});
    }
}

#endif // CPPUTIL_APPLY_HPP
