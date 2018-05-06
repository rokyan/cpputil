#include <gtest\gtest.h>
#include <basic_functors.h>
#include <type_traits>

namespace test {

    // Test traits

    namespace {

        // Type trait to check is_transparent presence

        template<typename T, typename = std::void_t<>>
        struct is_transparent :
            std::false_type {};

        template<typename T>
        struct is_transparent<T, std::void_t<typename T::is_transparent>> :
            std::true_type {};

        template<typename T>
        inline constexpr auto is_transparent_v = is_transparent<T>::value;
    }

    // Test arithmetic operations

    TEST(functor_test, test_plus) {
        using cpputil::plus;

        EXPECT_TRUE(is_transparent_v<plus<>>);

        EXPECT_EQ(plus<int>{}(4, 2), 6);
        EXPECT_EQ(plus<>{}(4, 2), 6);
    }

    TEST(functor_test, test_minus) {
        using cpputil::minus;

        EXPECT_TRUE(is_transparent_v<minus<>>);

        EXPECT_EQ(minus<int>{}(4, 2), 2);
        EXPECT_EQ(minus<>{}(4, 2), 2);
    }

    TEST(functor_test, test_multiplies) {
        using cpputil::multiplies;

        EXPECT_TRUE(is_transparent_v<multiplies<>>);

        EXPECT_EQ(multiplies<int>{}(4, 2), 8);
        EXPECT_EQ(multiplies<>{}(4, 2), 8);
    }

    TEST(functor_test, test_divides) {
        using cpputil::divides;

        EXPECT_TRUE(is_transparent_v<divides<>>);

        EXPECT_EQ(divides<int>{}(4, 2), 2);
        EXPECT_EQ(divides<>{}(4, 2), 2);
    }

    TEST(functor_test, test_modulus) {
        using cpputil::modulus;

        EXPECT_TRUE(is_transparent_v<modulus<>>);

        EXPECT_EQ(modulus<int>{}(4, 3), 1);
        EXPECT_EQ(modulus<>{}(4, 3), 1);
    }

    // Comparison operations

    TEST(functor_test, test_equal_to) {
        using cpputil::equal_to;

        EXPECT_TRUE(is_transparent_v<equal_to<>>);

        EXPECT_TRUE(equal_to<int>{}(2, 2));
        EXPECT_TRUE(equal_to<>{}(2, 2));
    }

    TEST(functor_test, test_not_equal_to) {
        using cpputil::not_equal_to;

        EXPECT_TRUE(is_transparent_v<not_equal_to<>>);

        EXPECT_FALSE(not_equal_to<int>{}(2, 2));
        EXPECT_FALSE(not_equal_to<>{}(2, 2));
    }

    TEST(functor_test, test_greater) {
        using cpputil::greater;

        EXPECT_TRUE(is_transparent_v<greater<>>);

        EXPECT_TRUE(greater<int>{}(4, 2));
        EXPECT_TRUE(greater<>{}(4, 2));
    }

    TEST(functor_test, test_less) {
        using cpputil::less;

        EXPECT_TRUE(is_transparent_v<less<>>);

        EXPECT_TRUE(less<int>{}(2, 4));
        EXPECT_TRUE(less<>{}(2, 4));
    }

    TEST(functor_test, test_greater_equal) {
        using cpputil::greater_equal;

        EXPECT_TRUE(is_transparent_v<greater_equal<>>);

        EXPECT_TRUE(greater_equal<int>{}(2, 2));
        EXPECT_TRUE(greater_equal<>{}(2, 2));
    }

    TEST(functor_test, test_less_equal) {
        using cpputil::less_equal;

        EXPECT_TRUE(is_transparent_v<less_equal<>>);

        EXPECT_TRUE(less_equal<int>{}(2, 2));
        EXPECT_TRUE(less_equal<>{}(2, 2));
    }

    // Logical operations

    TEST(functor_test, test_logical_and) {
        using cpputil::logical_and;

        EXPECT_TRUE(is_transparent_v<logical_and<>>);

        EXPECT_TRUE(logical_and<int>{}(true, true));
        EXPECT_TRUE(logical_and<>{}(true, true));
    }

    TEST(functor_test, test_logical_or) {
        using cpputil::logical_or;

        EXPECT_TRUE(is_transparent_v<logical_or<>>);

        EXPECT_TRUE(logical_or<int>{}(true, false));
        EXPECT_TRUE(logical_or<>{}(true, false));
    }

    TEST(functor_test, test_logical_not) {
        using cpputil::logical_not;

        EXPECT_TRUE(is_transparent_v<logical_not<>>);

        EXPECT_TRUE(logical_not<int>{}(false));
        EXPECT_TRUE(logical_not<>{}(false));
    }

    // Bitwise operations

    TEST(functor_test, test_bit_and) {
        using cpputil::bit_and;

        EXPECT_TRUE(is_transparent_v<bit_and<>>);

        EXPECT_EQ(bit_and<std::byte>{}(std::byte{3}, std::byte{2}), std::byte{2});
        EXPECT_EQ(bit_and<>{}(std::byte{3}, std::byte{2}), std::byte{2});
    }

    TEST(functor_test, test_bit_or) {
        using cpputil::bit_or;

        EXPECT_TRUE(is_transparent_v<bit_or<>>);

        EXPECT_EQ(bit_or<std::byte>{}(std::byte{1}, std::byte{2}), std::byte{3});
        EXPECT_EQ(bit_or<>{}(std::byte{1}, std::byte{2}), std::byte{3});
    }

    TEST(functor_test, test_bit_xor) {
        using cpputil::bit_xor;

        EXPECT_TRUE(is_transparent_v<bit_xor<>>);

        EXPECT_EQ(bit_xor<std::byte>{}(std::byte{3}, std::byte{7}), std::byte{4});
        EXPECT_EQ(bit_xor<>{}(std::byte{3}, std::byte{7}), std::byte{4});
    }

    TEST(functor_test, test_bit_not) {
        using cpputil::bit_not;

        EXPECT_TRUE(is_transparent_v<bit_not<>>);

        EXPECT_EQ(bit_not<std::byte>{}(std::byte{0}), std::byte{255});
        EXPECT_EQ(bit_not<>{}(std::byte{0}), std::byte{255});
    }
}