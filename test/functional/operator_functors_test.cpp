#include <gtest.hpp>
#include <functional.hpp>
#include <traits.hpp>

namespace test
{
    // Test traits.

    template<typename T, typename = traits::void_t<>>
    struct is_transparent :
        traits::false_type {};

    template<typename T>
    struct is_transparent<T, traits::void_t<typename T::is_transparent>> :
        traits::true_type {};

    template<typename T>
    inline constexpr auto is_transparent_v = is_transparent<T>::value;

    // Setup typed tests.

    using transparent_functor_types = make_test_types<
        cpputil::plus<>,
        cpputil::minus<>,
        cpputil::multiplies<>,
        cpputil::divides<>,
        cpputil::modulus<>,
        cpputil::equal_to<>,
        cpputil::not_equal_to<>,
        cpputil::greater<>,
        cpputil::less<>,
        cpputil::greater_equal<>,
        cpputil::less_equal<>,
        cpputil::logical_and<>,
        cpputil::logical_or<>,
        cpputil::logical_not<>,
        cpputil::bit_and<>,
        cpputil::bit_or<>,
        cpputil::bit_xor<>,
        cpputil::bit_not<>
    >;

    DECLARE_TYPED_TEST_NAME(TransparentFunctorTypedTest);
    TYPED_TEST_CASE(TransparentFunctorTypedTest, transparent_functor_types);

    TYPED_TEST(TransparentFunctorTypedTest, test_transparent_tag_presence)
    {
        EXPECT_TRUE(is_transparent_v<TypeParam>);
    }

    // Arithmetic operations tests.

    TEST(OperatorFunctorsTest, TestPlus)
    {
        EXPECT_EQ(cpputil::plus<int>{}(1, 2), 3);
        EXPECT_EQ(cpputil::plus<>{}(1, 2), 3);
    }

    TEST(OperatorFunctorsTest, TestMinus)
    {
        EXPECT_EQ(cpputil::minus<int>{}(3, 2), 1);
        EXPECT_EQ(cpputil::minus<>{}(3, 2), 1);
    }

    TEST(OperatorFunctorsTest, TestMultiplies)
    {
        EXPECT_EQ(cpputil::multiplies<int>{}(3, 2), 6);
        EXPECT_EQ(cpputil::multiplies<>{}(3, 2), 6);
    }

    TEST(OperatorFunctorsTest, TestDivides)
    {
        EXPECT_EQ(cpputil::divides<int>{}(4, 2), 2);
        EXPECT_EQ(cpputil::divides<>{}(4, 2), 2);
    }

    TEST(OperatorFunctorsTest, TestModulus)
    {
        EXPECT_EQ(cpputil::modulus<int>{}(3, 2), 1);
        EXPECT_EQ(cpputil::modulus<>{}(3, 2), 1);
    }

    // Comparison operations tests.

    TEST(OperatorFunctorsTest, TestEqualTo)
    {
        EXPECT_TRUE(cpputil::equal_to<int>{}(1, 1));
        EXPECT_TRUE(cpputil::equal_to<>{}(1, 1));
    }

    TEST(OperatorFunctorsTest, TestNotEqualTo)
    {
        EXPECT_TRUE(cpputil::not_equal_to<int>{}(0, 1));
        EXPECT_TRUE(cpputil::not_equal_to<>{}(0, 1));
    }

    TEST(OperatorFunctorsTest, TestGreater)
    {
        EXPECT_TRUE(cpputil::greater<int>{}(1, 0));
        EXPECT_TRUE(cpputil::greater<>{}(1, 0));
    }

    TEST(OperatorFunctorsTest, TestLess)
    {
        EXPECT_TRUE(cpputil::less<int>{}(0, 1));
        EXPECT_TRUE(cpputil::less<>{}(0, 1));
    }

    TEST(OperatorFunctorsTest, TestGreaterEqual)
    {
        EXPECT_TRUE(cpputil::greater_equal<int>{}(1, 0));
        EXPECT_TRUE(cpputil::greater_equal<>{}(1, 0));
    }

    TEST(OperatorFunctorsTest, TestLessEqual)
    {
        EXPECT_TRUE(cpputil::less_equal<int>{}(0, 1));
        EXPECT_TRUE(cpputil::less_equal<>{}(0, 1));
    }

    // Logical operations tests.

    TEST(OperatorFunctorsTest, TestLogicalAnd)
    {
        EXPECT_TRUE(cpputil::logical_and<bool>{}(true, true));
        EXPECT_TRUE(cpputil::logical_and<>{}(true, true));
    }

    TEST(OperatorFunctorsTest, TestLogicalOr)
    {
        EXPECT_TRUE(cpputil::logical_or<bool>{}(true, false));
        EXPECT_TRUE(cpputil::logical_or<>{}(true, false));
    }

    TEST(OperatorFunctorsTest, TestLogicalNot)
    {
        EXPECT_TRUE(cpputil::logical_not<bool>{}(false));
        EXPECT_TRUE(cpputil::logical_not<>{}(false));
    }

    // Bitwise operations tests.

    TEST(OperatorFunctorsTest, TestBitAnd)
    {
        EXPECT_EQ(cpputil::bit_and<std::byte>{}(std::byte{3}, std::byte{2}), std::byte{2});
        EXPECT_EQ(cpputil::bit_and<>{}(std::byte{3}, std::byte{2}), std::byte{2});
    }

    TEST(OperatorFunctorsTest, TestBitOr)
    {
        EXPECT_EQ(cpputil::bit_or<std::byte>{}(std::byte{1}, std::byte{2}), std::byte{3});
        EXPECT_EQ(cpputil::bit_or<>{}(std::byte{1}, std::byte{2}), std::byte{3});
    }

    TEST(OperatorFunctorsTest, TestBitXor)
    {
        EXPECT_EQ(cpputil::bit_xor<std::byte>{}(std::byte{3}, std::byte{7}), std::byte{4});
        EXPECT_EQ(cpputil::bit_xor<>{}(std::byte{3}, std::byte{7}), std::byte{4});
    }

    TEST(OperatorFunctorsTest, TestBitNot)
    {
        EXPECT_EQ(cpputil::bit_not<std::byte>{}(std::byte{0}), std::byte{255});
        EXPECT_EQ(cpputil::bit_not<>{}(std::byte{0}), std::byte{255});
    }
}