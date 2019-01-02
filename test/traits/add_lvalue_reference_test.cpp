#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::add_lvalue_reference_t;

TEST(TraitsTest, TestGeneralCase)
{
    EXPECT_SAME_TYPES(T0&, add_lvalue_reference_t<T0>);
}

TEST(TraitsTest, TestNonReferenceable)
{
    EXPECT_SAME_TYPES(void, add_lvalue_reference_t<void>);
}

} // namespace test
