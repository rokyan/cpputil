#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    using traits::is_function_v;

    TEST(traits_test, test_is_function)
    {
        ASSERT_TRUE(is_function_v<void()>);
        ASSERT_TRUE(is_function_v<void(int)>);
        ASSERT_TRUE(is_function_v<void() const>);
        ASSERT_TRUE(is_function_v<void(int) const>);
        ASSERT_TRUE(is_function_v<void() volatile>);
        ASSERT_TRUE(is_function_v<void(int) volatile>);
        ASSERT_TRUE(is_function_v<void() const volatile>);
        ASSERT_TRUE(is_function_v<void(int) const volatile>);
    }

    TEST(traits_test, test_is_function_ref_qualified)
    {
        ASSERT_TRUE(is_function_v<void() &>);
        ASSERT_TRUE(is_function_v<void(int) &>);
        ASSERT_TRUE(is_function_v<void() const &>);
        ASSERT_TRUE(is_function_v<void(int) const &>);
        ASSERT_TRUE(is_function_v<void() volatile &>);
        ASSERT_TRUE(is_function_v<void(int) volatile &>);
        ASSERT_TRUE(is_function_v<void() const volatile &>);
        ASSERT_TRUE(is_function_v<void(int) const volatile &>);

        ASSERT_TRUE(is_function_v<void() &&>);
        ASSERT_TRUE(is_function_v<void(int) &&>);
        ASSERT_TRUE(is_function_v<void() const &&>);
        ASSERT_TRUE(is_function_v<void(int) const &&>);
        ASSERT_TRUE(is_function_v<void() volatile &&>);
        ASSERT_TRUE(is_function_v<void(int) volatile &&>);
        ASSERT_TRUE(is_function_v<void() const volatile &&>);
        ASSERT_TRUE(is_function_v<void(int) const volatile &&>);
    }

    TEST(traits_test, test_is_function_noexcept)
    {
        ASSERT_TRUE(is_function_v<void() noexcept>);
        ASSERT_TRUE(is_function_v<void(int) noexcept>);
        ASSERT_TRUE(is_function_v<void() const noexcept>);
        ASSERT_TRUE(is_function_v<void(int) const noexcept>);
        ASSERT_TRUE(is_function_v<void() volatile noexcept>);
        ASSERT_TRUE(is_function_v<void(int) volatile noexcept>);
        ASSERT_TRUE(is_function_v<void() const volatile noexcept>);
        ASSERT_TRUE(is_function_v<void(int) const volatile noexcept>);
    }

    TEST(traits_test, test_is_function_ref_qualified_noexcept)
    {
        ASSERT_TRUE(is_function_v<void() & noexcept>);
        ASSERT_TRUE(is_function_v<void(int) & noexcept>);
        ASSERT_TRUE(is_function_v<void() const & noexcept>);
        ASSERT_TRUE(is_function_v<void(int) const & noexcept>);
        ASSERT_TRUE(is_function_v<void() volatile & noexcept>);
        ASSERT_TRUE(is_function_v<void(int) volatile & noexcept>);
        ASSERT_TRUE(is_function_v<void() const volatile & noexcept>);
        ASSERT_TRUE(is_function_v<void(int) const volatile & noexcept>);

        ASSERT_TRUE(is_function_v<void() && noexcept>);
        ASSERT_TRUE(is_function_v<void(int) && noexcept>);
        ASSERT_TRUE(is_function_v<void() const && noexcept>);
        ASSERT_TRUE(is_function_v<void(int) const && noexcept>);
        ASSERT_TRUE(is_function_v<void() volatile && noexcept>);
        ASSERT_TRUE(is_function_v<void(int) volatile && noexcept>);
        ASSERT_TRUE(is_function_v<void() const volatile && noexcept>);
        ASSERT_TRUE(is_function_v<void(int) const volatile && noexcept>);
    }

    TEST(traits_test, test_is_function_variadic)
    {
        ASSERT_TRUE(is_function_v<void(...)>);
        ASSERT_TRUE(is_function_v<void(int, ...)>);
        ASSERT_TRUE(is_function_v<void(...) const>);
        ASSERT_TRUE(is_function_v<void(int, ...) const>);
        ASSERT_TRUE(is_function_v<void(...) volatile>);
        ASSERT_TRUE(is_function_v<void(int, ...) volatile>);
        ASSERT_TRUE(is_function_v<void(...) const volatile>);
        ASSERT_TRUE(is_function_v<void(int, ...) const volatile>);
    }

    TEST(traits_test, test_is_function_variadic_ref_qualified)
    {
        ASSERT_TRUE(is_function_v<void(...) &>);
        ASSERT_TRUE(is_function_v<void(int, ...) &>);
        ASSERT_TRUE(is_function_v<void(...) const &>);
        ASSERT_TRUE(is_function_v<void(int, ...) const &>);
        ASSERT_TRUE(is_function_v<void(...) volatile &>);
        ASSERT_TRUE(is_function_v<void(int, ...) volatile &>);
        ASSERT_TRUE(is_function_v<void(...) const volatile &>);
        ASSERT_TRUE(is_function_v<void(int, ...) const volatile &>);

        ASSERT_TRUE(is_function_v<void(...) &&>);
        ASSERT_TRUE(is_function_v<void(int, ...) &&>);
        ASSERT_TRUE(is_function_v<void(...) const &&>);
        ASSERT_TRUE(is_function_v<void(int, ...) const &&>);
        ASSERT_TRUE(is_function_v<void(...) volatile &&>);
        ASSERT_TRUE(is_function_v<void(int, ...) volatile &&>);
        ASSERT_TRUE(is_function_v<void(...) const volatile &&>);
        ASSERT_TRUE(is_function_v<void(int, ...) const volatile &&>);
    }

    TEST(traits_test, test_is_function_variadic_noexcept)
    {
        ASSERT_TRUE(is_function_v<void(...) noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) noexcept>);
        ASSERT_TRUE(is_function_v<void(...) const noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) const noexcept>);
        ASSERT_TRUE(is_function_v<void(...) volatile noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) volatile noexcept>);
        ASSERT_TRUE(is_function_v<void(...) const volatile noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) const volatile noexcept>);
    }

    TEST(traits_test, test_is_function_variadic_ref_qualified_noexcept)
    {
        ASSERT_TRUE(is_function_v<void(...) & noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) & noexcept>);
        ASSERT_TRUE(is_function_v<void(...) const & noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) const & noexcept>);
        ASSERT_TRUE(is_function_v<void(...) volatile & noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) volatile & noexcept>);
        ASSERT_TRUE(is_function_v<void(...) const volatile & noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) const volatile & noexcept>);

        ASSERT_TRUE(is_function_v<void(...) && noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) && noexcept>);
        ASSERT_TRUE(is_function_v<void(...) const && noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) const && noexcept>);
        ASSERT_TRUE(is_function_v<void(...) volatile && noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) volatile && noexcept>);
        ASSERT_TRUE(is_function_v<void(...) const volatile && noexcept>);
        ASSERT_TRUE(is_function_v<void(int, ...) const volatile && noexcept>);
    }
}