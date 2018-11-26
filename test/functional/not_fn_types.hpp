#ifndef CPPUTIL_NOT_FN_TYPES_HPP
#define CPPUTIL_NOT_FN_TYPES_HPP

namespace test
{

template<typename Derived>
struct base_negator
{
    Derived operator!() const;
};

template<typename Derived>
struct base_negator_noexcept
{
    Derived operator!() const noexcept;
};

#define DEFINE_RET_TYPE_STRUCT(NAME, BASE) \
struct NAME : \
    BASE<NAME> {};

DEFINE_RET_TYPE_STRUCT(ret_type_lvalue_case, base_negator)
DEFINE_RET_TYPE_STRUCT(ret_type_const_lvalue_case, base_negator)
DEFINE_RET_TYPE_STRUCT(ret_type_rvalue_case, base_negator)
DEFINE_RET_TYPE_STRUCT(ret_type_const_rvalue_case, base_negator)

DEFINE_RET_TYPE_STRUCT(ret_type_lvalue_case_noexcept, base_negator_noexcept)
DEFINE_RET_TYPE_STRUCT(ret_type_const_lvalue_case_noexcept, base_negator_noexcept)
DEFINE_RET_TYPE_STRUCT(ret_type_rvalue_case_noexcept, base_negator_noexcept)
DEFINE_RET_TYPE_STRUCT(ret_type_const_rvalue_case_noexcept, base_negator_noexcept)

#define DEFINE_CALLABLE_STRUCT(STRUCT_NAME, RV1, RV2, RV3, RV4, NOEXCEPT) \
struct STRUCT_NAME \
{ \
    auto operator()() & -> RV1; \
    auto operator()() const & -> RV2; \
    auto operator()() && -> RV3; \
    auto operator()() const && -> RV4; \
};

DEFINE_CALLABLE_STRUCT(callable_invocation_may_throw,
    ret_type_lvalue_case_noexcept, ret_type_const_lvalue_case_noexcept,
    ret_type_rvalue_case_noexcept, ret_type_const_rvalue_case_noexcept, )
DEFINE_CALLABLE_STRUCT(callable_negation_may_throw,
    ret_type_lvalue_case, ret_type_const_lvalue_case,
    ret_type_rvalue_case, ret_type_const_rvalue_case, noexcept)
DEFINE_CALLABLE_STRUCT(callable_all_may_throw,
    ret_type_lvalue_case, ret_type_const_lvalue_case,
    ret_type_rvalue_case, ret_type_const_rvalue_case, )
DEFINE_CALLABLE_STRUCT(callable_noexcept,
    ret_type_lvalue_case_noexcept, ret_type_const_lvalue_case_noexcept,
    ret_type_rvalue_case_noexcept, ret_type_const_rvalue_case_noexcept, noexcept)

} // namespace test

#endif // CPPUTIL_NOT_FN_TYPES_HPP

