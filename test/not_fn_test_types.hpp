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

#define DEFINE_CALLABLE_STRUCT(STRUCT_NAME, RV1, RV2, RV3, RV4) \
    struct STRUCT_NAME \
    { \
        auto operator()() & -> RV1; \
        auto operator()() const & -> RV2; \
        auto operator()() && -> RV3; \
        auto operator()() const && -> RV4; \
    };

    DEFINE_CALLABLE_STRUCT(callable,
        ret_type_lvalue_case, ret_type_const_lvalue_case,
        ret_type_rvalue_case, ret_type_const_rvalue_case)
}