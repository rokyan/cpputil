#include <gtest.hpp>
#include <as_const.hpp>
#include <traits.hpp>
#include <declval.hpp>

namespace test
{
    template<typename T>
    class as_const_typed_test : public test_base<T> {};

    using test_types = make_types<int>;

    TYPED_TEST_CASE(as_const_typed_test, test_types);

    TYPED_TEST(as_const_typed_test, test_as_const_ret_value_type)
    {
        EXPECT_SAME_TYPES(const value_type&, decltype(cpputil::as_const(cpputil::declval<value_type&>())));
        EXPECT_SAME_TYPES(const value_type&, decltype(cpputil::as_const(cpputil::declval<const value_type&>())));
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