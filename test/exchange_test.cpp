#include <gtest\gtest.h>
#include <exchange.h>

namespace test {

    namespace {

        template<typename T>
        struct move_only {
            move_only(move_only&&) = default;
            move_only& operator=(move_only&&) = default;

            T data;
        };

        template<typename T>
        struct convertible {
            convertible& operator=(const T& data) {
                this->data = data;
                return *this;
            }

            operator T() const { return data; }

            T data;
        };
    }

    TEST(test_exchange, exchange_lvalue_case) {
        auto value = 0;
        const auto new_value = 1;
        const auto old_value = cpputil::exchange(value, new_value);

        EXPECT_EQ(value, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(test_exchange, exchange_rvalue_case) {
        auto value = 0;
        const auto old_value = cpputil::exchange(value, 1);

        EXPECT_EQ(value, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(test_exchange, test_move_only) {
        move_only<int> value{0};
        const auto old_value = std::exchange(value, move_only<int>{1});

        EXPECT_EQ(value.data, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value.data, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(test_exchange, test_convertible_support) {
        convertible<int> value_1{0};
        const auto old_value_1 = std::exchange(value_1, 1);

        EXPECT_EQ(value_1.data, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value_1.data, 0) <<
            "Incorrect value is returned by exchange function";

        auto value_2{0};
        const auto old_value_2 = std::exchange(value_2, convertible<int>{1});

        EXPECT_EQ(value_2, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value_2, 0) <<
            "Incorrect value is returned by exchange function";
    }
}