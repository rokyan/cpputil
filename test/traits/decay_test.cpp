#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

using traits::decay_t;

TEST(TraitsTest, TestReferenceDecay)
{
    EXPECT_SAME_TYPES(T0, decay_t<T0>);
    EXPECT_SAME_TYPES(T0, decay_t<T0&>);
    EXPECT_SAME_TYPES(T0, decay_t<T0&&>);
}

TEST(TraitsTest, TestConstVolatileDecay)
{
    EXPECT_SAME_TYPES(T0, decay_t<T0>);
    EXPECT_SAME_TYPES(T0, decay_t<const T0>);
    EXPECT_SAME_TYPES(T0, decay_t<volatile T0>);
    EXPECT_SAME_TYPES(T0, decay_t<const volatile T0>);
}

TEST(TraitsTest, TestConstVolatileReferenceDecay)
{
    EXPECT_SAME_TYPES(T0, decay_t<T0&>);
    EXPECT_SAME_TYPES(T0, decay_t<const T0&>);
    EXPECT_SAME_TYPES(T0, decay_t<volatile T0&>);
    EXPECT_SAME_TYPES(T0, decay_t<const volatile T0&>);

    EXPECT_SAME_TYPES(T0, decay_t<T0&&>);
    EXPECT_SAME_TYPES(T0, decay_t<const T0&&>);
    EXPECT_SAME_TYPES(T0, decay_t<volatile T0&&>);
    EXPECT_SAME_TYPES(T0, decay_t<const volatile T0&&>);
}

TEST(TraitsTest, TestFunctionDecay)
{
    EXPECT_SAME_TYPES(T0(*)(), decay_t<T0()>);
    EXPECT_SAME_TYPES(T0(*)(T1), decay_t<T0(T1)>);
}

TEST(TraitsTest, TestArrayDecay)
{
    EXPECT_SAME_TYPES(T0*, decay_t<T0[]>);
    EXPECT_SAME_TYPES(T0*, decay_t<T0[1]>);
    EXPECT_SAME_TYPES(T0(*)[1], decay_t<T0[][1]>);
    EXPECT_SAME_TYPES(T0(*)[1], decay_t<T0[1][1]>);
}

} // namespace test
