#pragma once

#include <gtest\gtest.h>
#include <type_traits>
#include <move.h>

namespace test {

    // Test traits

    namespace {

        template<typename T>
        constexpr std::is_lvalue_reference<T&&> is_lvalue(T&&) {
            return {};
        }

        template<typename T>
        constexpr std::is_rvalue_reference<T&&> is_rvalue(T&&) {
            return {};
        }
    }

    // Setup typed tests

    template<typename T>
    class move_typed_test : public testing::Test {
    public:
        T value{};
    };

    TYPED_TEST_CASE(move_typed_test, testing::Types<int>);

    // Tests

    TYPED_TEST(move_typed_test, test_move_ret_value_category) {
        // Test lvalue case
        EXPECT_TRUE(is_lvalue(this->value)());
        EXPECT_TRUE(is_rvalue(cpputil::move(this->value))());
        // Test rvalue case
        EXPECT_TRUE(is_rvalue(TypeParam{})());
        EXPECT_TRUE(is_rvalue(cpputil::move(TypeParam{}))());
    }

    TYPED_TEST(move_typed_test, test_move_ret_value_type) {
        // Test lvalue case
        EXPECT_TRUE((std::is_same_v<TypeParam, decltype(this->value)>));
        EXPECT_TRUE((std::is_same_v<TypeParam&&, decltype(cpputil::move(this->value))>));
        // Test rvalue case
        EXPECT_TRUE((std::is_same_v<TypeParam, decltype(TypeParam{})>));
        EXPECT_TRUE((std::is_same_v<TypeParam&&, decltype(cpputil::move(TypeParam{}))>));
    }

    TYPED_TEST(move_typed_test, test_move_noexcept) {
        // Test lvalue case
        EXPECT_TRUE(noexcept(cpputil::move(std::declval<TypeParam&>())));
        // Test rvalue case
        EXPECT_TRUE(noexcept(cpputil::move(std::declval<TypeParam>())));
    }
}