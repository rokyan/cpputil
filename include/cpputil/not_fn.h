#pragma once

#include <type_traits>
#include <functional>
#include <forward.h>

namespace cpputil
{
    struct not_fn_tag {};

    template<typename FD>
    class not_fn_wrapper
    {
    public:
        template<typename F>
        not_fn_wrapper(F&& fn, not_fn_tag)
            : fn(cpputil::forward<F>(fn))
        {}

        not_fn_wrapper(const not_fn_wrapper&) = default;
        not_fn_wrapper(not_fn_wrapper&&) = default;

        template<typename... Args>
        auto operator()(Args&&... args) &
            noexcept(noexcept(!std::invoke(cpputil::forward<FD&>(fn), cpputil::forward<Args>(args)...)))
            -> decltype(!cpputil::declval<std::invoke_result_t<FD&, Args...>>())
        {
            return !std::invoke(cpputil::forward<FD&>(fn), cpputil::forward<Args>(args)...);
        }

        template<typename... Args>
        auto operator()(Args&&... args) const &
            noexcept(noexcept(!std::invoke(cpputil::forward<const FD&>(fn), cpputil::forward<Args>(args)...)))
            -> decltype(!cpputil::declval<std::invoke_result_t<const FD&, Args...>>())
        {
            return !std::invoke(cpputil::forward<const FD&>(fn), cpputil::forward<Args>(args)...);
        }

        template<typename... Args>
        auto operator()(Args&&... args) &&
            noexcept(noexcept(!std::invoke(cpputil::forward<FD>(fn), cpputil::forward<Args>(args)...)))
            -> decltype(!cpputil::declval<std::invoke_result_t<FD, Args...>>())
        {
            return !std::invoke(cpputil::forward<FD>(fn), cpputil::forward<Args>(args)...);
        }

        template<typename... Args>
        auto operator()(Args&&... args) const &&
            noexcept(noexcept(!std::invoke(cpputil::forward<const FD>(fn), cpputil::forward<Args>(args)...)))
            -> decltype(!cpputil::declval<std::invoke_result_t<const FD, Args...>>())
        {
            return !std::invoke(cpputil::forward<const FD>(fn), cpputil::forward<Args>(args)...);
        }

    private:
        FD fn;
    };

    template<typename F>
    not_fn_wrapper<std::decay_t<F>> not_fn(F&& fn)
        noexcept(std::is_nothrow_constructible_v<std::decay_t<F>, F>)
    {
        return not_fn_wrapper<std::decay_t<F>>(cpputil::forward<F>(fn), not_fn_tag{});
    }
}