#include <gtest\gtest.h>
#include <type_traits>
#include <forward.h>

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
    class forward_typed_test : public testing::Test {
    public:
        T value{};
    };

    TYPED_TEST_CASE(forward_typed_test, testing::Types<int>);

    // Tests

    TYPED_TEST(forward_typed_test, test_forward_ret_value_category) {
        // Test lvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE(is_lvalue(this->value)());
        EXPECT_TRUE(is_lvalue(cpputil::forward<TypeParam&>(this->value))());
        // Test rvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE(is_rvalue(TypeParam{})());
        EXPECT_TRUE(is_rvalue(cpputil::forward<TypeParam>(TypeParam{}))());
    }

    TYPED_TEST(forward_typed_test, test_forward_ret_value_type) {
        // Test lvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE((std::is_same_v<TypeParam, decltype(this->value)>));
        EXPECT_TRUE((std::is_same_v<TypeParam&, decltype(cpputil::forward<TypeParam&>(this->value))>));
        // Test rvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE((std::is_same_v<TypeParam, decltype(TypeParam{})>));
        EXPECT_TRUE((std::is_same_v<TypeParam&&, decltype(cpputil::forward<TypeParam>(TypeParam{}))>));
    }

    TYPED_TEST(forward_typed_test, test_forward_noexcept) {
        // Test lvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE(noexcept(cpputil::forward<TypeParam&>(std::declval<TypeParam&>())));
        // Test rvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE(noexcept(cpputil::forward<TypeParam>(std::declval<TypeParam>())));
    }
}