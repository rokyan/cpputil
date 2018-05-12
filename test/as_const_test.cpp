#include <gtest\gtest.h>
#include <type_traits>
#include <as_const.h>

namespace test {

    // Setup typed tests

    template<typename T>
    class as_const_typed_test : public testing::Test {
    public:
        T value{};
    };

    TYPED_TEST_CASE(as_const_typed_test, testing::Types<int>);

    // Tests

    TYPED_TEST(as_const_typed_test, test_as_const_ret_value) {
        EXPECT_EQ(&this->value, &cpputil::as_const(this->value));
    }

    TYPED_TEST(as_const_typed_test, test_as_const_ret_value_type) {
        EXPECT_TRUE((std::is_same_v<const TypeParam&,
            decltype(cpputil::as_const(std::declval<TypeParam&>()))>));
        EXPECT_TRUE((std::is_same_v<const TypeParam&,
            decltype(cpputil::as_const(std::declval<const TypeParam&>()))>));
    }
}