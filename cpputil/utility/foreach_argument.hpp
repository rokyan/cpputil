#pragma once

#include <forward.hpp>
#include <integer_sequence.hpp>

#include <type_traits>
#include <utility>
#include <tuple>

namespace cpputil
{

template<typename Func, typename... Args>
void foreach_argument(Func&& func, Args&&... args)
{
    (static_cast<void>(std::invoke(cpputil::forward<Func>(func), cpputil::forward<Args>(args))), ...);
}

template<typename Func, typename Tuple, std::size_t... Is>
void foreach_tuple_argument_impl(Func&& func, Tuple&& tuple_of_args, cpputil::index_sequence<Is...>)
{
    foreach_argument(
        [&func](auto&&... elems) {
            std::invoke(cpputil::forward<Func>(func), cpputil::forward<decltype(elems)>(elems)...);
        },
        std::get<Is>(tuple_of_args)...);
}

template<typename Func, typename Tuple>
void foreach_tuple_argument(Func&& func, Tuple&& tuple_of_args)
{
    using index_sequence_type = cpputil::make_index_sequence<std::tuple_size_v<std::decay_t<Tuple>>>;

    cpputil::foreach_tuple_argument_impl(cpputil::forward<Func>(func),
        cpputil::forward<Tuple>(tuple_of_args), index_sequence_type{});
}

} // namespace cpputil
