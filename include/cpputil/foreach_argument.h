#pragma once

#include <type_traits>
#include <utility>
#include <tuple>
#include <forward.h>

namespace cpputil
{
    // foreach_argument implementation

    template<typename Func, typename... Args>
    void foreach_argument(Func&& f, Args&&... args)
    {
        (static_cast<void>(cpputil::forward<Func>(f)(cpputil::forward<Args>(args))), ...);
    }

    // foreach_tuple_argument implementation

    template<typename Func, typename Tuple, std::size_t... Is>
    void foreach_tuple_argument_impl(Func&& f, Tuple&& t, std::index_sequence<Is...>)
    {
        foreach_argument(
            [&f](auto&&... elems) {
                cpputil::forward<Func>(f)(cpputil::forward<decltype(elems)>(elems)...);
            },
            std::get<Is>(t)...);
    }

    template<typename Func, typename Tuple>
    void foreach_tuple_argument(Func&& f, Tuple&& t)
    {
        using index_sequence_type = std::make_index_sequence<std::tuple_size_v<std::decay_t<Tuple>>>;

        foreach_tuple_argument_impl(cpputil::forward<Func>(f), cpputil::forward<Tuple>(t), index_sequence_type{});
    }
}