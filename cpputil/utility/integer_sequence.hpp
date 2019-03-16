#pragma once

#include <traits.hpp>

#include <cstddef> // for std::size_t.

namespace cpputil
{

template<typename T, T... Ints>
struct integer_sequence
{
    using value_type = T;

    static constexpr std::size_t size() noexcept { return sizeof...(Ints); }
};

template<std::size_t... Ints>
using index_sequence = integer_sequence<std::size_t, Ints...>;

template<typename, typename>
struct merger;

template<typename T, T... Ints1, T... Ints2>
struct merger<integer_sequence<T, Ints1...>, integer_sequence<T, Ints2...>>
{
    using type = integer_sequence<T, Ints1..., (sizeof...(Ints1) + Ints2)...>;
};

template<typename T, typename N>
struct builder
{
    using left_merged = typename builder<T, traits::integral_constant<T, N::value / 2>>::type;
    using right_merged = typename builder<T, traits::integral_constant<T, N::value - N::value / 2>>::type;

    using type = typename merger<left_merged, right_merged>::type;
};

template<typename T>
struct builder<T, traits::integral_constant<T, 0>>
{
    using type = integer_sequence<T>;
};

template<typename T>
struct builder<T, traits::integral_constant<T, 1>>
{
    using type = integer_sequence<T, 0>;
};

template<typename T, T N>
using make_integer_sequence = typename builder<T, traits::integral_constant<T, N>>::type;

template<std::size_t N>
using make_index_sequence = make_integer_sequence<std::size_t, N>;

template<class... Ts>
using index_sequence_for = make_index_sequence<sizeof...(Ts)>;

} // namespace cpputil
