#ifndef CPPUTIL_REFERENCE_WRAPPER_HPP
#define CPPUTIL_REFERENCE_WRAPPER_HPP

#include <type_traits>
#include "forward.hpp"

namespace cpputil
{
    // reference_wrapper implementation

    template<typename T>
    class reference_wrapper
    {
    public:
        using type = T;

        reference_wrapper(T&) noexcept;
        reference_wrapper(T&&) = delete;
        reference_wrapper(const reference_wrapper&) noexcept = default;

        reference_wrapper& operator=(const reference_wrapper&) noexcept = default;

        operator T&() const noexcept;
        T& get() const noexcept;

        template<typename... ArgTypes>
        std::invoke_result_t<T&, ArgTypes...> operator()(ArgTypes&&...) const;

    private:
        T* referenced;
    };

    template<typename T>
    reference_wrapper<T>::reference_wrapper(T& t) noexcept
        : referenced(std::addressof(t))
    {}

    template<typename T>
    reference_wrapper<T>::operator T&() const noexcept
    {
        return get();
    }

    template<typename T>
    T& reference_wrapper<T>::get() const noexcept
    {
        return *referenced;
    }

    template<typename T>
    template<typename... ArgTypes>
    std::invoke_result_t<T&, ArgTypes...> reference_wrapper<T>:: operator()(ArgTypes&&... args) const
    {
        return std::invoke(get(), cpputil::forward<ArgTypes>(args)...);
    }

    // ref/cref functions implementation

    template<typename T>
    reference_wrapper<T> ref(T& t) noexcept
    {
        return reference_wrapper<T>(t);
    }

    template<typename T>
    reference_wrapper<T> ref(reference_wrapper<T>& t) noexcept
    {
        return ref(t.get());
    }

    template<typename T>
    void ref(const T&&) = delete;

    template<typename T>
    reference_wrapper<const T> cref(const T& t) noexcept
    {
        return reference_wrapper<const T>(t);
    }

    template<typename T>
    reference_wrapper<const T> cref(const reference_wrapper<T>& t) noexcept
    {
        return cref(t.get());
    }

    template<typename T>
    void cref(const T&&) = delete;
}

#endif // CPPUTIL_REFERENCE_WRAPPER_HPP