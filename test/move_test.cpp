#include <gtest\gtest.h>
#include <move.h>
#include <type_traits>

namespace test
{
    // Setup typed tests

    template<typename T>
    class move_typed_test : public testing::Test
    {
    public:
        using value_type = T;
    };

    TYPED_TEST_CASE(move_typed_test, testing::Types<int>);

    // Tests

    TYPED_TEST(move_typed_test, test_move_ret_value_type)
    {
        // Test lvalue case.
        EXPECT_TRUE((std::is_same_v<value_type&&, decltype(cpputil::move(std::declval<value_type&>()))>));
        // Test rvalue case.
        EXPECT_TRUE((std::is_same_v<value_type&&, decltype(cpputil::move(std::declval<value_type>()))>));
    }

    TYPED_TEST(move_typed_test, test_move_noexcept)
    {
        // Test lvalue case.
        EXPECT_TRUE(noexcept(cpputil::move(std::declval<value_type&>())));
        // Test rvalue case.
        EXPECT_TRUE(noexcept(cpputil::move(std::declval<value_type>())));
    }
}