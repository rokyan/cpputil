#pragma once

#include <forward.hpp>
#include <traits.hpp>
#include <type_traits> // TODO: remove a dependecy on type_traits in the future

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

#define NOT_FN_WRAP_FUNCTION_CALL_OP(QUALIFIERS) \
        template<typename... Args> \
        auto operator()(Args&&... args) QUALIFIERS \
            noexcept(std::is_nothrow_invocable_v<FD QUALIFIERS, Args...> && noexcept(!traits::declval<std::invoke_result_t<FD QUALIFIERS, Args...>>())) \
            -> decltype(!traits::declval<std::invoke_result_t<FD QUALIFIERS, Args...>>()) \
        { \
            return !std::invoke(cpputil::forward<FD QUALIFIERS>(fn), cpputil::forward<Args>(args)...); \
        }

        NOT_FN_WRAP_FUNCTION_CALL_OP(&)
        NOT_FN_WRAP_FUNCTION_CALL_OP(const &)
        NOT_FN_WRAP_FUNCTION_CALL_OP(&&)
        NOT_FN_WRAP_FUNCTION_CALL_OP(const &&)

    private:
        FD fn;
    };

    template<typename F>
    not_fn_wrapper<traits::decay_t<F>> not_fn(F&& fn)
        noexcept(std::is_nothrow_constructible_v<traits::decay_t<F>, F>)
    {
        return not_fn_wrapper<traits::decay_t<F>>(cpputil::forward<F>(fn), not_fn_tag{});
    }
}