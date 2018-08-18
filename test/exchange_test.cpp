#include <gtest.hpp>
#include <declval.hpp>
#include <exchange.hpp>

namespace test
{
    // Helper test types

    namespace
    {
        template<typename T>
        struct move_only
        {
            move_only(move_only&&) = default;
            move_only& operator=(move_only&&) = default;

            T data;
        };

        template<typename T>
        struct convertible_to
        {
            convertible_to& operator=(T&& other_data)
            {
                data = cpputil::move(other_data);
                return *this;
            }

            operator T() const { return data; }

            T data;
        };

        void overloaded(int) {}
        void overloaded(double) {}
    }

    // Setup typed tests

    template<typename T>
    class exchange_typed_test :
        public test_base<T> {};

    using test_types = make_test_types<int, double>;

    TYPED_TEST_CASE(exchange_typed_test, test_types);

    // Typed tests

    TYPED_TEST(exchange_typed_test, test_exchange_return_type)
    {
        EXPECT_TRUE((std::is_same_v<value_type,
            decltype(cpputil::exchange(cpputil::declval<value_type&>(), cpputil::declval<value_type>()))>));
    }

    // Tests

    TEST(exchange_test, exchange_lvalue_case)
    {
        auto value = 0;
        const auto new_value = 1;
        const auto old_value = cpputil::exchange(value, new_value);

        EXPECT_EQ(value, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(exchange_test, exchange_rvalue_case)
    {
        auto value = 0;
        const auto old_value = cpputil::exchange(value, 1);

        EXPECT_EQ(value, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(exchange_test, test_move_only)
    {
        using move_only_t = move_only<int>;

        move_only_t value{0};
        const auto old_value = std::exchange(value, move_only_t{1});

        EXPECT_EQ(value.data, 1) <<
            "Incorrect value is assigned by exchange function";
        EXPECT_EQ(old_value.data, 0) <<
            "Incorrect value is returned by exchange function";
    }

    TEST(exchange_test, test_convertible_to)
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

    TEST(exchange_test, test_default_template_param)
    {
        auto value = 1;
        cpputil::exchange(value, {});

        EXPECT_EQ(value, 0) <<
            "Incorrect value is assigned by exchange function";

        void (*ptr_to_overloaded)(int) = nullptr;
        cpputil::exchange(ptr_to_overloaded, &overloaded);

        EXPECT_EQ(static_cast<void*>(ptr_to_overloaded),
            static_cast<void*>(static_cast<void(*)(int)>(overloaded))) <<
            "Incorrect value is assigned by exchange function";
    }
}