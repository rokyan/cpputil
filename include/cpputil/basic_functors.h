#pragma once

#include "forward.h"

namespace cpputil
{

    struct transparent_tag {};

    struct transparent_functor
    {
        using is_transparent = transparent_tag;
    };

    // Arithmetic operations

    template<typename T = void>
    struct plus
    {
        constexpr T operator()(const T& x, const T& y) const
        {
            return x + y;
        }
    };

    template<>
    struct plus<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) + cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) + cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) + cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct minus
    {
        constexpr T operator()(const T& x, const T& y) const
        {
            return x - y;
        }
    };

    template<>
    struct minus<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) - cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) - cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) - cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct multiplies
    {
        constexpr T operator()(const T& x, const T& y) const
        {
            return x * y;
        }
    };

    template<>
    struct multiplies<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) * cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) * cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) * cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct divides
    {
        constexpr T operator()(const T& x, const T& y) const
        {
            return x / y;
        }
    };

    template<>
    struct divides<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) / cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) / cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) / cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct modulus
    {
        constexpr T operator()(const T& x, const T& y) const
        {
            return x % y;
        }
    };

    template<>
    struct modulus<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) % cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) % cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) % cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct negate
    {
        constexpr T operator()(const T& x) const
        {
            return -x;
        }
    };

    template<>
    struct negate<void> : transparent_functor
    {
        template<typename T>
        constexpr auto operator()(T&& x) const
            noexcept(noexcept(-cpputil::forward<T>(x)))
            -> decltype(-cpputil::forward<T>(x))
        {
            return -cpputil::forward<T>(x);
        }
    };

    // Comparison operations

    template<typename T = void>
    struct equal_to
    {
        constexpr bool operator()(const T& x, const T& y) const
        {
            return (x == y);
        }
     };

    template<>
    struct equal_to<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) == cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) == cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) == cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct not_equal_to
    {
        constexpr bool operator()(const T& x, const T& y) const
        {
            return (x != y);
        }
    };

    template<>
    struct not_equal_to<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) != cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) != cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) != cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct greater
    {
        constexpr bool operator()(const T& x, const T& y) const
        {
            return (x > y);
        }
    };

    template<>
    struct greater<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) > cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) > cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) > cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct less
    {
        constexpr bool operator()(const T& x, const T& y) const
        {
            return (x < y);
        }
    };

    template<>
    struct less<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) < cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) < cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) < cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct greater_equal
    {
        constexpr bool operator()(const T& x, const T& y) const
        {
            return (x >= y);
        }
    };

    template<>
    struct greater_equal<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) >= cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) >= cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) >= cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct less_equal
    {
        constexpr bool operator()(const T& x, const T& y) const
        {
            return (x <= y);
        }
    };

    template<>
    struct less_equal<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) <= cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) <= cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) <= cpputil::forward<U>(y));
        }
    };

    // Logical operations

    template<typename T = void>
    struct logical_and
    {
        constexpr bool operator()(const T& x, const T& y) const
        {
            return (x && y);
        }
    };

    template<>
    struct logical_and<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) && cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) && cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) && cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct logical_or
    {
        constexpr bool operator()(const T& x, const T& y) const
        {
            return (x || y);
        }
    };

    template<>
    struct logical_or<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) || cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) || cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) || cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct logical_not
    {
        constexpr bool operator()(const T& x) const
        {
            return !x;
        }
    };

    template<>
    struct logical_not<void> : transparent_functor
    {
        template<typename T>
        constexpr auto operator()(T&& x) const
            noexcept(noexcept(!cpputil::forward<T>(x)))
            -> decltype(!cpputil::forward<T>(x))
        {
            return !cpputil::forward<T>(x);
        }
    };

    // Bitwise operations

    template<typename T = void>
    struct bit_and
    {
        constexpr T operator()(const T& x, const T& y) const
        {
            return (x & y);
        }
    };

    template<>
    struct bit_and<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) & cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) & cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) & cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct bit_or
    {
        constexpr T operator()(const T& x, const T& y) const
        {
            return (x | y);
        }
    };

    template<>
    struct bit_or<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) | cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) | cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) | cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct bit_xor
    {
        constexpr T operator()(const T& x, const T& y) const
        {
            return (x ^ y);
        }
    };

    template<>
    struct bit_xor<void> : transparent_functor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& x, U&& y) const
            noexcept(noexcept(cpputil::forward<T>(x) ^ cpputil::forward<U>(y)))
            -> decltype(cpputil::forward<T>(x) ^ cpputil::forward<U>(y))
        {
            return (cpputil::forward<T>(x) ^ cpputil::forward<U>(y));
        }
    };

    template<typename T = void>
    struct bit_not
    {
        constexpr T operator()(const T& x) const
        {
            return ~x;
        }
    };

    template<>
    struct bit_not<void> : transparent_functor
    {
        template<typename T>
        constexpr auto operator()(T&& x) const
            noexcept(noexcept(~cpputil::forward<T>(x)))
            -> decltype(~cpputil::forward<T>(x))
        {
            return ~cpputil::forward<T>(x);
        }
    };
}