#pragma once

#include "integral_constant.hpp"

namespace cpputil
{

template<typename>
struct is_function :
    false_type {};

template<typename R, typename... Args>
struct is_function<R(Args...)> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) volatile> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const volatile> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) &> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const &> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) volatile &> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const volatile &> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) && > : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const &&> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) volatile &&> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const volatile &&> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) volatile noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const volatile noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) & noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const & noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) volatile & noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const volatile & noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) && noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const && noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) volatile && noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args...) const volatile && noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...)> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) volatile> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const volatile> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) &> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const &> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) volatile &> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const volatile &> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) && > : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const &&> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) volatile &&> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const volatile &&> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) volatile noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const volatile noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) & noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const & noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) volatile & noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const volatile & noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) && noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const && noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) volatile && noexcept> : true_type {};

template<typename R, typename... Args>
struct is_function<R(Args..., ...) const volatile && noexcept> : true_type {};

template<typename T>
inline constexpr auto is_function_v = is_function<T>::value;

} // namespace cpputil
