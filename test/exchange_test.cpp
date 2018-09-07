#include <gtest.hpp>
#include <declval.hpp>
#include <exchange.hpp>
#include <exchange_test_types.hpp>

namespace test
{
    using test_types = make_test_types<int, double>;

    DECLARE_TYPED_TEST_NAME(ExchangeTypedTest);
    TYPED_TEST_CASE(ExchangeTypedTest, test_types);

    TYPED_TEST(ExchangeTypedTest, TestExchangeReturnType)
    {
        EXPECT_TRUE((std::is_same_v<TypeParam,
            decltype(cpputil::exchange(cpputil::declval<TypeParam&>(), cpputil::declval<TypeParam>()))>));
    }

    TEST(ExchangeTypedTest, TestLvalueParamCase)
    {
        auto value = 0;
        const auto new_value = 1;
        const auto old_value = cpputil::exchange(value, new_value);

        EXPECT_EQ(value, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(ExchangeTypedTest, TestRvalueParamCase)
    {
        auto value = 0;
        const auto old_value = cpputil::exchange(value, 1);

        EXPECT_EQ(value, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(ExchangeTypedTest, TestMoveOnlyParamCase)
    {
        using move_only_t = move_only<int>;

        move_only_t value{0};
        const auto old_value = std::exchange(value, move_only_t{1});

        EXPECT_EQ(value.data, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value.data, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(ExchangeTypedTest, TestConvertibleToParamCase)
    {
        using convertible_to_t = convertible_to<int>;

        convertible_to_t value_1{0};
        const auto old_value_1 = std::exchange(value_1, 1);

        EXPECT_EQ(value_1.data, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value_1.data, 0) <<
            "Incorrect value is returned by exchange function";

        auto value_2{0};
        const auto old_value_2 = std::exchange(value_2, convertible_to_t{1});

        EXPECT_EQ(value_2, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value_2, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(ExchangeTypedTest, TestExchangeDefaultTemplateParam)
    {
        auto value = 1;
        cpputil::exchange(value, {});

        EXPECT_EQ(value, 0) <<
            "Incorrect value is assigned by exchange function";
    }
}