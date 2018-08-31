#include <gtest.hpp>
#include <declval.hpp>
#include <not_fn.hpp>
#include <not_fn_test_helper.hpp>

namespace test
{
    template<typename F>
    class not_fn_typed_test_base : public test_base<F>
    {
    public:
        using not_fn_wrapper_type = cpputil::not_fn_wrapper<std::decay_t<F>>;
    };

    template<typename F>
    class not_fn_typed_test : public not_fn_typed_test_base<F> {};

    using not_fn_typed_test_types = make_test_types<
        bool(),
        bool() noexcept,
        bool(*)(),
        bool(*)() noexcept,
        std::function<bool()>
    >;

    TYPED_TEST_CASE(not_fn_typed_test, not_fn_typed_test_types);

    template<typename F>
    class not_fn_call_operator_typed_test : public not_fn_typed_test_base<F> {};

    using not_fn_call_operator_typed_test_types = make_test_types<
        callable,
        callable_noexcept
    >;

    TYPED_TEST_CASE(not_fn_call_operator_typed_test, not_fn_call_operator_typed_test_types);

    // Test not_fn_wrapper.

    TYPED_TEST(not_fn_typed_test, test_not_fn_wrapper_constructibility)
    {
        // Test not_fn_wrapper constructibility both from lvalue and rvalue callable objects.

        EXPECT_TRUE((std::is_constructible_v<not_fn_wrapper_type, value_type&, cpputil::not_fn_tag>)) <<
            "not_fn_wrapper must be constructible from callable lvalue";
        EXPECT_TRUE((std::is_constructible_v<not_fn_wrapper_type, value_type, cpputil::not_fn_tag>)) <<
            "not_fn_wrapper must be constructible from callable rvalue";

        // Test default copy and move constructors.

        EXPECT_TRUE(std::is_copy_constructible_v<not_fn_wrapper_type>) <<
            "not_fn_wrapper must be copy constructible";
        EXPECT_TRUE(std::is_move_constructible_v<not_fn_wrapper_type>) <<
            "not_fn_wrapper must be move constructible";
    }

    TYPED_TEST(not_fn_typed_test, test_not_fn_wrapper_assignability)
    {
        // Test implicitly deleted copy and move assignment operators.

        EXPECT_FALSE(std::is_copy_assignable_v<not_fn_wrapper_type>) <<
            "not_fn_wrapper must not be copy assignable";
        EXPECT_FALSE(std::is_move_assignable_v<not_fn_wrapper_type>) <<
            "not_fn_wrapper must not be move assignable";
    }

    TYPED_TEST(not_fn_call_operator_typed_test, test_not_fn_wrapper_function_call_operator)
    {
        EXPECT_TRUE(std::is_invocable_v<not_fn_wrapper_type&>) <<
            "not_fn_wrapper must be invocable as lvalue";
        EXPECT_EQ(noexcept(cpputil::declval<not_fn_wrapper_type&>()()), 
            noexcept(!std::invoke(cpputil::declval<value_type&>()))) <<
            "Incorrect result for not_fn_wrapper call operator noexcept check";
        EXPECT_TRUE((std::is_same_v<std::invoke_result_t<not_fn_wrapper_type&>, ret_type_lvalue_case>)) <<
            "Incorrect return value from not_fn_wrapper call";

        EXPECT_TRUE(std::is_invocable_v<const not_fn_wrapper_type&>) <<
            "not_fn_wrapper must be invocable as const lvalue";
        EXPECT_EQ(noexcept(cpputil::declval<const not_fn_wrapper_type&>()()),
            noexcept(!std::invoke(cpputil::declval<value_type&>()))) <<
            "Incorrect result for not_fn_wrapper call operator noexcept check";;
        EXPECT_TRUE((std::is_same_v<std::invoke_result_t<const not_fn_wrapper_type&>, ret_type_const_lvalue_case>)) <<
            "Incorrect return value from not_fn_wrapper call";

        EXPECT_TRUE(std::is_invocable_v<not_fn_wrapper_type>) <<
            "not_fn_wrapper must be invocable as rvalue";
        EXPECT_EQ(noexcept(cpputil::declval<not_fn_wrapper_type>()()),
            noexcept(!std::invoke(cpputil::declval<value_type>()))) <<
            "Incorrect result for not_fn_wrapper call operator noexcept check";;
        EXPECT_TRUE((std::is_same_v<std::invoke_result_t<not_fn_wrapper_type>, ret_type_rvalue_case>)) <<
            "Incorrect return value from not_fn_wrapper call";

        EXPECT_TRUE(std::is_invocable_v<const not_fn_wrapper_type>) <<
            "not_fn_wrapper must be invocable as const rvalue";
        EXPECT_EQ(noexcept(cpputil::declval<const not_fn_wrapper_type>()()),
            noexcept(!std::invoke(cpputil::declval<value_type>()))) <<
            "Incorrect result for not_fn_wrapper call operator noexcept check";;
        EXPECT_TRUE((std::is_same_v<std::invoke_result_t<const not_fn_wrapper_type>, ret_type_const_rvalue_case>)) <<
            "Incorrect return value from not_fn_wrapper call";
    }

    // Test not_fn.

    TYPED_TEST(not_fn_typed_test, test_not_fn_ret_value)
    {
        EXPECT_TRUE((std::is_same_v<not_fn_wrapper_type,
            decltype(cpputil::not_fn(cpputil::declval<value_type&>()))>)) <<
            "not_fn return value is incorrect";
        EXPECT_TRUE((std::is_same_v<not_fn_wrapper_type,
            decltype(cpputil::not_fn(cpputil::declval<value_type>()))>)) <<
            "not_fn return value is incorrect";
    }

    TYPED_TEST(not_fn_typed_test, test_not_fn_noexcept)
    {
        EXPECT_EQ((std::is_nothrow_constructible_v<std::decay_t<value_type&>, value_type&>),
            noexcept(cpputil::not_fn(cpputil::declval<value_type&>()))) <<
            "not_fn invalid noexcept";
        EXPECT_EQ((std::is_nothrow_constructible_v<std::decay_t<value_type>, value_type>),
            noexcept(cpputil::not_fn(cpputil::declval<value_type>()))) <<
            "not_fn invalid noexcept";
    }
}