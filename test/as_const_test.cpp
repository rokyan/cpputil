#include <gtest\gtest.h>
#include <declval.h>
#include <as_const.h>
#include <type_traits>

namespace test
{
    // Setup typed tests

    template<typename T>
    class as_const_typed_test : public testing::Test
    {
    public:
        using value_type = T;
    };

    using test_types = testing::Types<int>;

    TYPED_TEST_CASE(as_const_typed_test, test_types);

    // Tests

    TYPED_TEST(as_const_typed_test, test_as_const_ret_value_type)
    {
        EXPECT_TRUE((std::is_same_v<const value_type&, decltype(cpputil::as_const(cpputil::declval<value_type&>()))>));
        EXPECT_TRUE((std::is_same_v<const value_type&, decltype(cpputil::as_const(cpputil::declval<const value_type&>()))>));
    }

    TYPED_TEST(as_const_typed_test, test_as_const_noexcept)
    {
        EXPECT_TRUE(noexcept(cpputil::as_const(cpputil::declval<value_type&>())));
        EXPECT_TRUE(noexcept(cpputil::as_const(cpputil::declval<const value_type&>())));
    }

    TYPED_TEST(as_const_typed_test, test_as_const_ret_value)
    {
        value_type value{};

        EXPECT_EQ(std::addressof(value), std::addressof(cpputil::as_const(value)));
    }
}