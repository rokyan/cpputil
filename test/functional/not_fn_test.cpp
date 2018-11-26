#include <gtest.hpp>
#include <functional.hpp>
#include <not_fn_types.hpp>

namespace test
{

using not_fn_typed_test_types = make_test_types<
    bool(),
    bool() noexcept,
    bool(*)(),
    bool(*)() noexcept,
    std::function<bool()>
>;

DECLARE_TYPED_TEST_NAME(NotFnTypedTest);
TYPED_TEST_CASE(NotFnTypedTest, not_fn_typed_test_types);

using not_fn_call_operator_typed_test_types = make_test_types<
    callable_invocation_may_throw,
    callable_negation_may_throw,
    callable_all_may_throw,
    callable_noexcept
>;

DECLARE_TYPED_TEST_NAME(NotFnCallOperatorTypedTest);
TYPED_TEST_CASE(NotFnCallOperatorTypedTest, not_fn_call_operator_typed_test_types);

// Test not_fn_wrapper.

TYPED_TEST(NotFnTypedTest, TestNotFnWrapperConstructibility)
{
    using not_fn_wrapper_type = cpputil::not_fn_wrapper<traits::decay_t<TypeParam>>;

    // Test not_fn_wrapper constructibility both from lvalue and rvalue callable objects.

    EXPECT_TRUE((std::is_constructible_v<not_fn_wrapper_type, TypeParam&, cpputil::not_fn_tag>)) <<
        "not_fn_wrapper must be constructible from callable lvalue";
    EXPECT_EQ(noexcept(traits::declval<not_fn_wrapper_type&>()()),
        noexcept(!std::invoke(traits::declval<TypeParam&>()))) <<
        "Incorrect result for not_fn_wrapper call operator noexcept check";
    EXPECT_TRUE((std::is_constructible_v<not_fn_wrapper_type, TypeParam, cpputil::not_fn_tag>)) <<
        "not_fn_wrapper must be constructible from callable rvalue";

    // Test default copy and move constructors.

    EXPECT_TRUE(std::is_copy_constructible_v<not_fn_wrapper_type>) <<
        "not_fn_wrapper must be copy constructible";
    EXPECT_TRUE(std::is_move_constructible_v<not_fn_wrapper_type>) <<
        "not_fn_wrapper must be move constructible";
}

TYPED_TEST(NotFnTypedTest, TestNotFnWrapperAssignability)
{
    using not_fn_wrapper_type = cpputil::not_fn_wrapper<traits::decay_t<TypeParam>>;

    // Test implicitly deleted copy and move assignment operators.

    EXPECT_FALSE(std::is_copy_assignable_v<not_fn_wrapper_type>) <<
        "not_fn_wrapper must not be copy assignable";
    EXPECT_FALSE(std::is_move_assignable_v<not_fn_wrapper_type>) <<
        "not_fn_wrapper must not be move assignable";
}

TYPED_TEST(NotFnCallOperatorTypedTest, TestNotFnWrapperFunctionCallOperator)
{
    using not_fn_wrapper_type = cpputil::not_fn_wrapper<traits::decay_t<TypeParam>>;

    constexpr auto ret_type_noexcept =
        traits::is_contained_in_v<TypeParam, callable_invocation_may_throw, callable_noexcept>;

    EXPECT_TRUE(std::is_invocable_v<not_fn_wrapper_type&>) <<
        "not_fn_wrapper must be invocable as lvalue";
    using invoke_result_lvalue_case = traits::conditional_t<ret_type_noexcept,
        ret_type_lvalue_case_noexcept, ret_type_lvalue_case>;
    EXPECT_SAME_TYPES(std::invoke_result_t<not_fn_wrapper_type&>, invoke_result_lvalue_case) <<
        "Incorrect return value from not_fn_wrapper call";

    EXPECT_TRUE(std::is_invocable_v<const not_fn_wrapper_type&>) <<
        "not_fn_wrapper must be invocable as const lvalue";
    using invoke_result_const_lvalue_case = traits::conditional_t<ret_type_noexcept,
        ret_type_const_lvalue_case_noexcept, ret_type_const_lvalue_case>;
    EXPECT_SAME_TYPES(std::invoke_result_t<const not_fn_wrapper_type&>, invoke_result_const_lvalue_case) <<
        "Incorrect return value from not_fn_wrapper call";

    EXPECT_TRUE(std::is_invocable_v<not_fn_wrapper_type>) <<
        "not_fn_wrapper must be invocable as rvalue";
    using invoke_result_rvalue_case = traits::conditional_t<ret_type_noexcept,
        ret_type_rvalue_case_noexcept, ret_type_rvalue_case>;
    EXPECT_SAME_TYPES(std::invoke_result_t<not_fn_wrapper_type>, invoke_result_rvalue_case) <<
        "Incorrect return value from not_fn_wrapper call";

    EXPECT_TRUE(std::is_invocable_v<const not_fn_wrapper_type>) <<
        "not_fn_wrapper must be invocable as const rvalue";
    using invoke_result_const_rvalue_case = traits::conditional_t<ret_type_noexcept,
        ret_type_const_rvalue_case_noexcept, ret_type_const_rvalue_case>;
    EXPECT_SAME_TYPES(std::invoke_result_t<const not_fn_wrapper_type>, invoke_result_const_rvalue_case) <<
        "Incorrect return value from not_fn_wrapper call";
}

// Test not_fn.

TYPED_TEST(NotFnTypedTest, TestNotFnRetValue)
{
    using not_fn_wrapper_type = cpputil::not_fn_wrapper<traits::decay_t<TypeParam>>;

    EXPECT_SAME_TYPES(not_fn_wrapper_type, decltype(cpputil::not_fn(traits::declval<TypeParam&>()))) <<
        "not_fn return value is incorrect";
    EXPECT_SAME_TYPES(not_fn_wrapper_type, decltype(cpputil::not_fn(traits::declval<TypeParam>()))) <<
        "not_fn return value is incorrect";
}

TYPED_TEST(NotFnTypedTest, TestNotFnNoexcept)
{
    using not_fn_wrapper_type = cpputil::not_fn_wrapper<traits::decay_t<TypeParam>>;

    EXPECT_EQ((std::is_nothrow_constructible_v<traits::decay_t<TypeParam&>, TypeParam&>),
        noexcept(cpputil::not_fn(traits::declval<TypeParam&>()))) <<
        "not_fn invalid noexcept";
    EXPECT_EQ((std::is_nothrow_constructible_v<traits::decay_t<TypeParam>, TypeParam>),
        noexcept(cpputil::not_fn(traits::declval<TypeParam>()))) <<
        "not_fn invalid noexcept";
}

} // namespace test
