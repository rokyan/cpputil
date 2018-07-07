#pragma once

#include <utility>
#include <forward.h>

namespace cpputil
{
    template<typename Func, typename Tuple, std::size_t... Is>
    decltype(auto) apply(Func&& f, Tuple&& t, std::index_sequence<Is...>)
    {
        return std::invoke(cpputil::forward<Func>(f), std::get<Is>(t)...);
    }

    template<typename Func, typename Tuple>
    decltype(auto) apply(Func&& f, Tuple&& t)
    {
        using index_sequence_type = std::make_index_sequence<std::tuple_size_v<std::decay_t<Tuple>>>;

        return cpputil::apply(cpputil::forward<Func>(f), cpputil::forward<Tuple>(t), index_sequence_type{});
    }
}