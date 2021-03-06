#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using cpputil::integral_constant;
using cpputil::bool_constant;

TEST(TraitsTest, TestIntegralConstant)
{
    using T = int;
    using integral_constant_t = integral_constant<T, T{}>;

    EXPECT_EQ(integral_constant_t::value, T{});

    EXPECT_SAME_TYPES(integral_constant_t::value_type, T);
    EXPECT_SAME_TYPES(integral_constant_t::type, integral_constant_t);

    EXPECT_EQ(integral_constant_t{}(), T{});
    EXPECT_EQ(static_cast<T>(integral_constant_t{}), T{});
}

TEST(TraitsTest, TestBoolConstant)
{
    using integral_constant_false_t = integral_constant<bool, false>;
    EXPECT_SAME_TYPES(integral_constant_false_t, bool_constant<false>);

    using integral_constant_true_t = integral_constant<bool, true>;
    EXPECT_SAME_TYPES(integral_constant_true_t, bool_constant<true>);
}

} // namespace test
