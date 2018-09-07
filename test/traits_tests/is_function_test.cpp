#include <gtest.hpp>
#include <traits.hpp>

namespace test
{
    using traits::is_function_v;

    TEST(TraitsTest, TestIsFunction)
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

    TEST(TraitsTest, TestIsFunctionRefQualified)
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

    TEST(TraitsTest, TestIsFunctionNoexcept)
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

    TEST(TraitsTest, TestIsFunctionRefQualifiedNoexcept)
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

    TEST(TraitsTest, TestIsFunctionVariadic)
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

    TEST(TraitsTest, TestIsFunctionVariadicRefQualified)
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

    TEST(TraitsTest, TestIsFunctionVariadicNoexcept)
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

    TEST(TraitsTest, TestIsFunctionVariadicRefQualifiedNoexcept)
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