#include <gtest.hpp>
#include <utility.hpp>
#include <traits.hpp>

namespace test
{

using test_types = make_test_types<int, double>;

DECLARE_TYPED_TEST_NAME(ForwardTypedTest);
TYPED_TEST_CASE(ForwardTypedTest, test_types);

TYPED_TEST(ForwardTypedTest, TestForwardReturnValueType)
{
    // Test lvalue case. Emulate type deduction for forwarding references.
    EXPECT_SAME_TYPES(TypeParam&,
        decltype(cpputil::forward<TypeParam&>(cpputil::declval<TypeParam&>())));
    // Test rvalue case. Emulate type deduction for forwarding references.
    EXPECT_SAME_TYPES(TypeParam&&,
        decltype(cpputil::forward<TypeParam>(cpputil::declval<TypeParam>())));
}

TYPED_TEST(ForwardTypedTest, TestForwardNoexcept)
{
    // Test lvalue case. Emulate type deduction for forwarding references.
    EXPECT_TRUE(noexcept(cpputil::forward<TypeParam&>(cpputil::declval<TypeParam&>())));
    // Test rvalue case. Emulate type deduction for forwarding references.
    EXPECT_TRUE(noexcept(cpputil::forward<TypeParam>(cpputil::declval<TypeParam>())));
}

} // namespace test