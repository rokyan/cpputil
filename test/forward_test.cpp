#include <gtest\gtest.h>
#include <declval.hpp>
#include <forward.hpp>
#include <type_traits>

namespace test
{
    // Setup typed tests

    template<typename T>
    class forward_typed_test : public testing::Test
    {
    public:
        using value_type = T;
    };

    TYPED_TEST_CASE(forward_typed_test, testing::Types<int>);

    // Tests

    TYPED_TEST(forward_typed_test, test_forward_ret_value_type)
    {
        // Test lvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE((std::is_same_v<value_type&, decltype(cpputil::forward<value_type&>(cpputil::declval<value_type&>()))>));
        // Test rvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE((std::is_same_v<value_type&&, decltype(cpputil::forward<value_type>(cpputil::declval<value_type>()))>));
    }

    TYPED_TEST(forward_typed_test, test_forward_noexcept)
    {
        // Test lvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE(noexcept(cpputil::forward<value_type&>(cpputil::declval<value_type&>())));
        // Test rvalue case. Emulate type deduction for forwarding references.
        EXPECT_TRUE(noexcept(cpputil::forward<value_type>(cpputil::declval<value_type>())));
    }
}