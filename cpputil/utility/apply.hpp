#pragma once

#include <integer_sequence.hpp>
#include <forward.hpp>
#include <traits.hpp>

#include <utility> // for std::tuple.
#include <functional> // for std::invoke.

namespace cpputil
{

template<typename Func, typename Tuple, std::size_t... Is>
decltype(auto) apply_impl(Func&& func, Tuple&& tuple_of_args, cpputil::index_sequence<Is...>)
{
    return std::invoke(cpputil::forward<Func>(func), std::get<Is>(tuple_of_args)...);
}

template<typename Func, typename Tuple>
decltype(auto) apply(Func&& func, Tuple&& tuple_of_args)
{
    using index_sequence_type = cpputil::make_index_sequence<std::tuple_size_v<traits::decay_t<Tuple>>>;

    return cpputil::apply_impl(cpputil::forward<Func>(func), cpputil::forward<Tuple>(tuple_of_args), index_sequence_type{});
}

} // namespace cpputil
