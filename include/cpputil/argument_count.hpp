#pragma once

#include <traits.hpp>
#include <cstdlib> // for std::size_t

namespace cpputil
{
    template<typename>
    struct argument_count;

    template<typename... Ts>
    using argument_count_base = traits::integral_constant<std::size_t, sizeof...(Ts)>;

    // function types.

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...)> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) volatile> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) volatile noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const volatile> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const volatile noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) &> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) & noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const &> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const & noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) volatile &> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) volatile & noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const volatile &> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const volatile & noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) &&> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) && noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const &&> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const && noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) volatile &&> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) volatile && noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const volatile &&> :
        argument_count_base<Ts...> {};

    template<typename R, typename...Ts>
    struct argument_count<R(Ts...) const volatile && noexcept> :
        argument_count_base<Ts...> {};

    // member function types.

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...)> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) volatile> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) volatile noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const volatile> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const volatile noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) &> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) & noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const &> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const & noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) volatile &> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) volatile & noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const volatile &> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const volatile & noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) &&> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) && noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const &&> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const && noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) volatile &&> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) volatile && noexcept> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const volatile &&> :
        argument_count_base<Ts...> {};

    template<typename R, typename C, typename...Ts>
    struct argument_count<R(C::*)(Ts...) const volatile && noexcept> :
        argument_count_base<Ts...> {};

    template<typename T>
    inline constexpr auto argument_count_v = argument_count<T>::value;
}