#include <gtest\gtest.h>
#include <operator_functors.h>
#include <type_traits>

namespace test
{
    // Test traits.

    namespace
    {
        // Type trait to check is_transparent tag presence.

        template<typename T, typename = std::void_t<>>
        struct is_transparent :
            std::false_type {};

        template<typename T>
        struct is_transparent<T, std::void_t<typename T::is_transparent>> :
            std::true_type {};

        template<typename T>
        inline constexpr auto is_transparent_v = is_transparent<T>::value;
    }

    // Setup typed tests.

    template<typename T>
    class transparent_functor_typed_test : public testing::Test
    {
    public:
        using value_type = T;
    };

    using transparent_functor_types = testing::Types<
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

    TYPED_TEST_CASE(transparent_functor_typed_test, transparent_functor_types);

    TYPED_TEST(transparent_functor_typed_test, test_transparent_tag_presence)
    {
        EXPECT_TRUE(is_transparent_v<value_type>);
    }

    // Arithmetic operations tests.

    TEST(operator_functors_test, test_plus)
    {
        EXPECT_EQ(cpputil::plus<int>{}(1, 2), 3);
        EXPECT_EQ(cpputil::plus<>{}(1, 2), 3);
    }

    TEST(operator_functors_test, test_minus)
    {
        EXPECT_EQ(cpputil::minus<int>{}(3, 2), 1);
        EXPECT_EQ(cpputil::minus<>{}(3, 2), 1);
    }

    TEST(operator_functors_test, test_multiplies)
    {
        EXPECT_EQ(cpputil::multiplies<int>{}(3, 2), 6);
        EXPECT_EQ(cpputil::multiplies<>{}(3, 2), 6);
    }

    TEST(operator_functors_test, test_divides)
    {
        EXPECT_EQ(cpputil::divides<int>{}(4, 2), 2);
        EXPECT_EQ(cpputil::divides<>{}(4, 2), 2);
    }

    TEST(operator_functors_test, test_modulus)
    {
        EXPECT_EQ(cpputil::modulus<int>{}(3, 2), 1);
        EXPECT_EQ(cpputil::modulus<>{}(3, 2), 1);
    }

    // Comparison operations tests.

    TEST(operator_functors_test, test_equal_to)
    {
        EXPECT_TRUE(cpputil::equal_to<int>{}(1, 1));
        EXPECT_TRUE(cpputil::equal_to<>{}(1, 1));
    }

    TEST(operator_functors_test, test_not_equal_to)
    {
        EXPECT_TRUE(cpputil::not_equal_to<int>{}(0, 1));
        EXPECT_TRUE(cpputil::not_equal_to<>{}(0, 1));
    }

    TEST(operator_functors_test, test_greater)
    {
        EXPECT_TRUE(cpputil::greater<int>{}(1, 0));
        EXPECT_TRUE(cpputil::greater<>{}(1, 0));
    }

    TEST(operator_functors_test, test_less)
    {
        EXPECT_TRUE(cpputil::less<int>{}(0, 1));
        EXPECT_TRUE(cpputil::less<>{}(0, 1));
    }

    TEST(operator_functors_test, test_greater_equal)
    {
        EXPECT_TRUE(cpputil::greater_equal<int>{}(1, 0));
        EXPECT_TRUE(cpputil::greater_equal<>{}(1, 0));
    }

    TEST(operator_functors_test, test_less_equal)
    {
        EXPECT_TRUE(cpputil::less_equal<int>{}(0, 1));
        EXPECT_TRUE(cpputil::less_equal<>{}(0, 1));
    }

    // Logical operations tests.

    TEST(operator_functors_test, test_logical_and)
    {
        EXPECT_TRUE(cpputil::logical_and<bool>{}(true, true));
        EXPECT_TRUE(cpputil::logical_and<>{}(true, true));
    }

    TEST(operator_functors_test, test_logical_or)
    {
        EXPECT_TRUE(cpputil::logical_or<bool>{}(true, false));
        EXPECT_TRUE(cpputil::logical_or<>{}(true, false));
    }

    TEST(operator_functors_test, test_logical_not)
    {
        EXPECT_TRUE(cpputil::logical_not<bool>{}(false));
        EXPECT_TRUE(cpputil::logical_not<>{}(false));
    }

    // Bitwise operations tests.

    TEST(operator_functors_test, test_bit_and)
    {
        EXPECT_EQ(cpputil::bit_and<std::byte>{}(std::byte{3}, std::byte{2}), std::byte{2});
        EXPECT_EQ(cpputil::bit_and<>{}(std::byte{3}, std::byte{2}), std::byte{2});
    }

    TEST(operator_functors_test, test_bit_or)
    {
        EXPECT_EQ(cpputil::bit_or<std::byte>{}(std::byte{1}, std::byte{2}), std::byte{3});
        EXPECT_EQ(cpputil::bit_or<>{}(std::byte{1}, std::byte{2}), std::byte{3});
    }

    TEST(operator_functors_test, test_bit_xor)
    {
        EXPECT_EQ(cpputil::bit_xor<std::byte>{}(std::byte{3}, std::byte{7}), std::byte{4});
        EXPECT_EQ(cpputil::bit_xor<>{}(std::byte{3}, std::byte{7}), std::byte{4});
    }

    TEST(operator_functors_test, test_bit_not)
    {
        EXPECT_EQ(cpputil::bit_not<std::byte>{}(std::byte{0}), std::byte{255});
        EXPECT_EQ(cpputil::bit_not<>{}(std::byte{0}), std::byte{255});
    }
}