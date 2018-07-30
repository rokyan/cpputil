#pragma once

namespace traits
{
    // templates below are used to implement other traits.

    template<typename T>
    struct identity
    {
        using type = T;
    };

    template<typename T>
    using identity_t = typename identity<T>::type;

    template<typename... Ts>
    using void_t = void;

    // helper class.

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

    // primary type categories.

    template<typename T>
    struct is_array :
        false_type {};

    template<typename T, std::size_t N>
    struct is_array<T[N]> :
        true_type {};

    template<typename T>
    struct is_array<T[]> :
        true_type {};

    template<typename T>
    inline constexpr auto is_array_v = is_array<T>::value;

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

    // type properties.

    template<typename T>
    struct is_const :
        false_type {};

    template<typename T>
    struct is_const<const T> :
        true_type {};

    template<typename T>
    inline constexpr auto is_const_v = is_const<T>::value;

    template<typename T>
    struct is_volatile :
        false_type {};

    template<typename T>
    struct is_volatile<volatile T> :
        true_type {};

    template<typename T>
    inline constexpr auto is_volatile_v = is_volatile<T>::value;

    // type relations.

    template<typename T, typename U>
    struct is_same :
        false_type {};

    template<typename T>
    struct is_same<T, T> :
        true_type {};

    template<typename T, typename U>
    inline constexpr auto is_same_v = is_same<T, U>::value;

    // const-volatile modifications.

    template<typename T>
    struct remove_const :
        identity<T> {};

    template<typename T>
    struct remove_const<const T> :
        identity<T> {};

    template<typename T>
    using remove_const_t = typename remove_const<T>::type;

    template<typename T>
    struct remove_volatile :
        identity<T> {};

    template<typename T>
    struct remove_volatile<volatile T> :
        identity<T> {};

    template<typename T>
    using remove_volatile_t = typename remove_volatile<T>::type;

    template<typename T>
    struct remove_cv :
        identity<remove_const_t<remove_volatile_t<T>>> {};

    template<typename T>
    using remove_cv_t = typename remove_cv<T>::type;

    template<typename T>
    struct add_const :
        identity<const T> {};

    template<typename T>
    using add_const_t = typename add_const<T>::type;

    template<typename T>
    struct add_volatile :
        identity<volatile T> {};

    template<typename T>
    using add_volatile_t = typename add_volatile<T>::type;

    template<typename T>
    struct add_cv :
        identity<const volatile T> {};

    template<typename T>
    using add_cv_t = typename add_cv<T>::type;

    // reference modifications.

    template<typename T>
    struct remove_reference :
        identity<T> {};

    template<typename T>
    struct remove_reference<T&> :
        identity<T> {};

    template<typename T>
    struct remove_reference<T&&> :
        identity<T> {};

    template<typename T>
    using remove_reference_t = typename remove_reference<T>::type;

    // array modifications.

    template<typename T>
    struct remove_extent :
        identity<T> {};

    template<typename T, std::size_t N>
    struct remove_extent<T[N]> :
        identity<T> {};

    template<typename T>
    struct remove_extent<T[]> :
        identity<T> {};

    template<typename T>
    using remove_extent_t = typename remove_extent<T>::type;

    // pointer modifications.

    template<typename T, typename U>
    struct remove_pointer_impl :
        identity<T> {};

    template<typename T, typename U>
    struct remove_pointer_impl<T, U*> :
        identity<U> {};

    template<typename T>
    struct remove_pointer :
        remove_pointer_impl<T, remove_cv_t<T>> {};

    template<typename T>
    using remove_pointer_t = typename remove_pointer<T>::type;

    template<typename T, typename = void>
    struct add_pointer :
        identity<T> {};

    template<typename T>
    struct add_pointer<T, void_t<remove_reference_t<T>*>> :
        identity<remove_reference_t<T>*> {};

    template<typename T>
    using add_pointer_t = typename add_pointer<T>::type;

    // other transformations.

    template<bool Condition, typename T, typename U>
    struct conditional :
        identity<T> {};

    template<typename T, typename U>
    struct conditional<false, T, U> :
        identity<U> {};

    template<bool Condition, typename T, typename U>
    using conditional_t = typename conditional<Condition, T, U>::type;

    // helper traits and traits which are not specified in the standard.

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