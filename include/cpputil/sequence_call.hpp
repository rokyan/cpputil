/**
 * Based on https://stackoverflow.com/a/38024297/5507349
 */

#pragma once

#include <forward.hpp>

namespace cpputil
{
    namespace detail
    {
        template<typename Callable, typename... Callables>
        struct sequence_call : Callable, sequence_call<Callables...>
        {
            constexpr sequence_call(Callable callable, Callables... callables)
                : Callable(callable)
                , sequence_call<Callables...>(callables...)
            {}

            template<typename... Args>
            constexpr auto operator()(Args&&... args) const
                noexcept(noexcept(sequence_call<Callables...>::operator()(Callable::operator()(cpputil::forward<Args>(args)...))))
                -> decltype(sequence_call<Callables...>::operator()(Callable::operator()(cpputil::forward<Args>(args)...)))
            {
                return sequence_call<Callables...>::operator()(Callable::operator()(cpputil::forward<Args>(args)...));
            }
        };

        template<typename Callable>
        struct sequence_call<Callable> : Callable
        {
            using Callable::operator();

            constexpr sequence_call(Callable callable)
                : Callable(callable)
            {}
        };
    }
    
    template<typename... Callables>
    constexpr auto make_sequence_call(Callables... callables)
        noexcept(noexcept(detail::sequence_call<Callables...>(callables...)))
        -> decltype(detail::sequence_call<Callables...>(callables...))
    {
        static_assert(sizeof...(Callables) > 0, "At least one callable object must be specified");
        return detail::sequence_call<Callables...>(callables...);
    }
}