#include <gtest\gtest.h>
#include <argument_count.hpp>
#include <argument_count_test_types.hpp>

namespace test
{
    using cpputil::argument_count_v;

    TEST(argument_count_test, test_function_types)
    {
        EXPECT_EQ(argument_count_v<void()>, 0);
        EXPECT_EQ(argument_count_v<void() noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0)>, 1);
        EXPECT_EQ(argument_count_v<void(T0) noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() const>, 0);
        EXPECT_EQ(argument_count_v<void() const noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) const>, 1);
        EXPECT_EQ(argument_count_v<void(T0) const noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() volatile>, 0);
        EXPECT_EQ(argument_count_v<void() volatile noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) volatile>, 1);
        EXPECT_EQ(argument_count_v<void(T0) volatile noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() const volatile>, 0);
        EXPECT_EQ(argument_count_v<void() const volatile noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) const volatile>, 1);
        EXPECT_EQ(argument_count_v<void(T0) const volatile noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() &>, 0);
        EXPECT_EQ(argument_count_v<void() & noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) &>, 1);
        EXPECT_EQ(argument_count_v<void(T0) & noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() const &>, 0);
        EXPECT_EQ(argument_count_v<void() const & noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) const &>, 1);
        EXPECT_EQ(argument_count_v<void(T0) const & noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() volatile &>, 0);
        EXPECT_EQ(argument_count_v<void() volatile & noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) volatile &>, 1);
        EXPECT_EQ(argument_count_v<void(T0) volatile & noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() const volatile &>, 0);
        EXPECT_EQ(argument_count_v<void() const volatile & noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) const volatile &>, 1);
        EXPECT_EQ(argument_count_v<void(T0) const volatile & noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() &&>, 0);
        EXPECT_EQ(argument_count_v<void() && noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) &&>, 1);
        EXPECT_EQ(argument_count_v<void(T0) && noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() const &&>, 0);
        EXPECT_EQ(argument_count_v<void() const && noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) const &&>, 1);
        EXPECT_EQ(argument_count_v<void(T0) const && noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() volatile &&>, 0);
        EXPECT_EQ(argument_count_v<void() volatile && noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) volatile &&>, 1);
        EXPECT_EQ(argument_count_v<void(T0) volatile && noexcept>, 1);

        EXPECT_EQ(argument_count_v<void() const volatile &&>, 0);
        EXPECT_EQ(argument_count_v<void() const volatile && noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(T0) const volatile &&>, 1);
        EXPECT_EQ(argument_count_v<void(T0) const volatile && noexcept>, 1);
    }

    TEST(argument_count_test, test_member_function_types)
    {
        EXPECT_EQ(argument_count_v<void(some_class::*)()>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0)>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() const>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() const noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() volatile>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() volatile noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) volatile>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) volatile noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() const volatile>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() const volatile noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const volatile>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const volatile noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() &>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() & noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) &>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) & noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() const &>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() const & noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const &>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const & noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() volatile &>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() volatile & noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) volatile &>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) volatile & noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() const volatile &>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() const volatile & noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const volatile &>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const volatile & noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() && >, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() && noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) && >, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) && noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() const &&>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() const && noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const &&>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const && noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() volatile &&>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() volatile && noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) volatile &&>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) volatile && noexcept>, 1);

        EXPECT_EQ(argument_count_v<void(some_class::*)() const volatile &&>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)() const volatile && noexcept>, 0);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const volatile &&>, 1);
        EXPECT_EQ(argument_count_v<void(some_class::*)(T0) const volatile && noexcept>, 1);
    }

    TEST(argument_count_test, test_lambdas)
    {
        EXPECT_EQ(argument_count_v<decltype(&lambda_type::operator())>, 2);
        EXPECT_EQ(argument_count_v<decltype(&mutable_lambda_type::operator())>, 2);
    }
}