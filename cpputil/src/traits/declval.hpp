#ifndef CPPUTIL_DECLVAL_HPP
#define CPPUTIL_DECLVAL_HPP

#include "add_rvalue_reference.hpp"

namespace traits
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
}

#endif // CPPUTIL_DECLVAL_HPP
