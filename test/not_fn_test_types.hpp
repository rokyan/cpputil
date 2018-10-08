#pragma once

namespace test
{
    template<typename Derived>
    struct base_negator
    {
        Derived operator!() const noexcept;
    };

#define DEFINE_RET_TYPE_STRUCT(STRUCT_NAME) \
    struct STRUCT_NAME : \
        base_negator<STRUCT_NAME> {};

    DEFINE_RET_TYPE_STRUCT(ret_type_lvalue_case)
    DEFINE_RET_TYPE_STRUCT(ret_type_const_lvalue_case)
    DEFINE_RET_TYPE_STRUCT(ret_type_rvalue_case)
    DEFINE_RET_TYPE_STRUCT(ret_type_const_rvalue_case)

    struct callable
    {
        auto operator()() & -> ret_type_lvalue_case;
        auto operator()() const & ->ret_type_const_lvalue_case;
        auto operator()() && ->ret_type_rvalue_case;
        auto operator()() const && ->ret_type_const_rvalue_case;
    };
}