#include <gtest.hpp>
#include <traits.hpp>
#include <declval.hpp>
#include <as_const.hpp>

namespace test
{
    using test_types = make_test_types<T0, const T0, volatile T0, const volatile T0>;

    DECLARE_TYPED_TEST_NAME(AsConstTypedTest);
    TYPED_TEST_CASE(AsConstTypedTest, test_types);

    TYPED_TEST(AsConstTypedTest, TestAsConstRetValueType)
    {
        EXPECT_SAME_TYPES(const TypeParam&,
            decltype(cpputil::as_const(cpputil::declval<TypeParam&>())));
        EXPECT_SAME_TYPES(const TypeParam&,
            decltype(cpputil::as_const(cpputil::declval<const TypeParam&>())));
    }

    TYPED_TEST(AsConstTypedTest, TestAsConstRetValue)
    {
        TypeParam value{};
        EXPECT_EQ(std::addressof(value), std::addressof(cpputil::as_const(value)));
    }

    TYPED_TEST(AsConstTypedTest, TestAsConstNoexcept)
    {
        EXPECT_TRUE(noexcept(cpputil::as_const(cpputil::declval<TypeParam&>())));
        EXPECT_TRUE(noexcept(cpputil::as_const(cpputil::declval<const TypeParam&>())));
    }
}