#pragma once

namespace traits
{
    // integral_constant implementation.

    template<typename T, T v>
    struct integral_constant
    {
        static constexpr T value = v;

        using value_type = T;
        using type = integral_constant<T, v>;

        constexpr operator value_type() const noexcept {
            return value;
        }

        constexpr T operator()() const noexcept {
            return value;
        }
    };

    template<bool B>
    using bool_constant = integral_constant<bool, B>;

    using false_type = bool_constant<false>;
    using true_type = bool_constant<true>;

    // is_contained_in implementation.

    template<typename, typename...>
    struct is_contained_in :
        std::false_type {};

    template<typename T, typename... Ts>
    struct is_contained_in<T, T, Ts...> :
        std::true_type {};

    template<typename T, typename U, typename... Ts>
    struct is_contained_in<T, U, Ts...> :
        is_contained_in<T, Ts...> {};

    template<typename T, typename... Ts>
    inline constexpr auto is_contained_in_v = is_contained_in<T, Ts...>::value;
}