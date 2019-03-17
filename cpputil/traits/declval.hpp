#pragma once

#include "add_rvalue_reference.hpp"

namespace cpputil
{

namespace declval_impl
{
    template<typename T>
    struct declval_protector
    {
        static constexpr auto always_false = false;
        static add_rvalue_reference_t<T> call();
    };
}

template<typename T>
add_rvalue_reference_t<T> declval() noexcept
{
    using declval_protector = declval_impl::declval_protector<T>;

    static_assert(declval_protector::always_false, "declval() must not be called!");
    return declval_protector::call();
}

} // namespace cpputil
