#pragma once

#include <utility>

namespace cpputil {

    struct transparent_tag {};

    // Arithmetic operations

    template<typename T = void>
    struct plus {
        constexpr T operator()(const T& x, const T& y) const {
            return x + y;
        }
    };

    template<>
    struct plus<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) + std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct minus {
        constexpr T operator()(const T& x, const T& y) const {
            return x - y;
        }
    };

    template<>
    struct minus<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) - std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct multiplies {
        constexpr T operator()(const T& x, const T& y) const {
            return x * y;
        }
    };

    template<>
    struct multiplies<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) * std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct divides {
        constexpr T operator()(const T& x, const T& y) const {
            return x / y;
        }
    };

    template<>
    struct divides<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) / std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct modulus {
        constexpr T operator()(const T& x, const T& y) const {
            return x % y;
        }
    };

    template<>
    struct modulus<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) % std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct negate {
        constexpr T operator()(const T& x) const {
            return -x;
        }
    };

    template<>
    struct negate<void> {
        using is_transparent = transparent_tag;

        template<typename T>
        constexpr decltype(auto) operator()(T&& x) const {
            return -std::forward<T>(x);
        }
    };

    // Comparison operations

    template<typename T = void>
    struct equal_to {
        constexpr bool operator()(const T& x, const T& y) const {
            return (x == y);
        }
     };

    template<>
    struct equal_to<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) == std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct not_equal_to {
        constexpr bool operator()(const T& x, const T& y) const {
            return (x != y);
        }
    };

    template<>
    struct not_equal_to<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) != std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct greater {
        constexpr bool operator()(const T& x, const T& y) const {
            return (x > y);
        }
    };

    template<>
    struct greater<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) > std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct less {
        constexpr bool operator()(const T& x, const T& y) const {
            return (x < y);
        }
    };

    template<>
    struct less<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) < std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct greater_equal {
        constexpr bool operator()(const T& x, const T& y) const {
            return (x >= y);
        }
    };

    template<>
    struct greater_equal<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) >= std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct less_equal {
        constexpr bool operator()(const T& x, const T& y) const {
            return (x <= y);
        }
    };

    template<>
    struct less_equal<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) <= std::forward<U>(y));
        }
    };

    // Logical operations

    template<typename T = void>
    struct logical_and {
        constexpr bool operator()(const T& x, const T& y) const {
            return (x && y);
        }
    };

    template<>
    struct logical_and<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) && std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct logical_or {
        constexpr bool operator()(const T& x, const T& y) const {
            return (x || y);
        }
    };

    template<>
    struct logical_or<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) || std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct logical_not {
        constexpr bool operator()(const T& x) const {
            return !x;
        }
    };

    template<>
    struct logical_not<void> {
        using is_transparent = transparent_tag;

        template<typename T>
        constexpr decltype(auto) operator()(T&& x) const {
            return !std::forward<T>(x);
        }
    };

    // Bitwise operations

    template<typename T = void>
    struct bit_and {
        constexpr T operator()(const T& x, const T& y) const {
            return (x & y);
        }
    };

    template<>
    struct bit_and<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) & std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct bit_or {
        constexpr T operator()(const T& x, const T& y) const {
            return (x | y);
        }
    };

    template<>
    struct bit_or<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) | std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct bit_xor {
        constexpr T operator()(const T& x, const T& y) const {
            return (x ^ y);
        }
    };

    template<>
    struct bit_xor<void> {
        using is_transparent = transparent_tag;

        template<typename T, typename U>
        constexpr decltype(auto) operator()(T&& x, U&& y) const {
            return (std::forward<T>(x) ^ std::forward<U>(y));
        }
    };

    template<typename T = void>
    struct bit_not {
        constexpr T operator()(const T& x) const {
            return ~x;
        }
    };

    template<>
    struct bit_not<void> {
        using is_transparent = transparent_tag;

        template<typename T>
        constexpr decltype(auto) operator()(T&& x) const {
            return ~std::forward<T>(x);
        }
    };
}