#include <gtest\gtest.h>
#include <declval.h>
#include <move.h>
#include <type_traits>

namespace test
{
    // Setup typed tests.

    template<typename T>
    class typed_test_base : public testing::Test
    {
    public:
        using value_type = T;
    };

    template<typename T>
    class move_typed_test: public typed_test_base<T>{};

    TYPED_TEST_CASE(move_typed_test, testing::Types<int>);

    template<typename T>
    class move_if_noexcept_typed_test : public typed_test_base<T> {};

    struct movable_noexcept_non_copyable
    {
        movable_noexcept_non_copyable(movable_noexcept_non_copyable&&) = delete;
        movable_noexcept_non_copyable(const movable_noexcept_non_copyable&) = default;
    };

    static_assert(!std::is_move_constructible_v<movable_noexcept_non_copyable>);
    static_assert(!std::is_nothrow_move_constructible_v<movable_noexcept_non_copyable>);
    static_assert(std::is_copy_constructible_v<movable_noexcept_non_copyable>);
    static_assert(std::is_nothrow_copy_constructible_v<movable_noexcept_non_copyable>);

    struct movable_non_copyable
    {
        movable_non_copyable(movable_non_copyable&&) {};
        movable_non_copyable(const movable_non_copyable&) = delete;
    };

    static_assert(std::is_move_constructible_v<movable_non_copyable>);
    static_assert(!std::is_nothrow_move_constructible_v<movable_non_copyable>);
    static_assert(!std::is_copy_constructible_v<movable_non_copyable>);
    static_assert(!std::is_nothrow_copy_constructible_v<movable_non_copyable>);

    struct copyable_noexcept_non_movable
    {
        copyable_noexcept_non_movable(copyable_noexcept_non_movable&&) = delete;
        copyable_noexcept_non_movable(const copyable_noexcept_non_movable&) = default;
    };

    static_assert(!std::is_move_constructible_v<copyable_noexcept_non_movable>);
    static_assert(!std::is_nothrow_move_constructible_v<copyable_noexcept_non_movable>);
    static_assert(std::is_copy_constructible_v<copyable_noexcept_non_movable>);
    static_assert(std::is_nothrow_copy_constructible_v<copyable_noexcept_non_movable>);

    struct copyable_non_movable
    {
        copyable_non_movable(copyable_non_movable&&) = delete;
        copyable_non_movable(const copyable_non_movable&) {};
    };

    static_assert(!std::is_move_constructible_v<copyable_non_movable>);
    static_assert(!std::is_nothrow_move_constructible_v<copyable_non_movable>);
    static_assert(std::is_copy_constructible_v<copyable_non_movable>);
    static_assert(!std::is_nothrow_copy_constructible_v<copyable_non_movable>);

    struct movable_noexcept_copyable_noexcept
    {
        movable_noexcept_copyable_noexcept(movable_noexcept_copyable_noexcept&&) = default;
        movable_noexcept_copyable_noexcept(const movable_noexcept_copyable_noexcept&) = default;
    };

    static_assert(std::is_move_constructible_v<movable_noexcept_copyable_noexcept>);
    static_assert(std::is_nothrow_move_constructible_v<movable_noexcept_copyable_noexcept>);
    static_assert(std::is_copy_constructible_v<movable_noexcept_copyable_noexcept>);
    static_assert(std::is_nothrow_copy_constructible_v<movable_noexcept_copyable_noexcept>);

    struct movable_copyable
    {
        movable_copyable(movable_copyable&&) {};
        movable_copyable(const movable_copyable&) {};
    };

    static_assert(std::is_move_constructible_v<movable_copyable>);
    static_assert(!std::is_nothrow_move_constructible_v<movable_copyable>);
    static_assert(std::is_copy_constructible_v<movable_copyable>);
    static_assert(!std::is_nothrow_copy_constructible_v<movable_copyable>);

    using move_if_noexcept_test_types = testing::Types<
        movable_noexcept_non_copyable,
        movable_non_copyable,
        copyable_noexcept_non_movable,
        copyable_non_movable,
        movable_noexcept_copyable_noexcept,
        movable_copyable
    >;

    TYPED_TEST_CASE(move_if_noexcept_typed_test, move_if_noexcept_test_types);

    // Tests.

    TYPED_TEST(move_typed_test, test_move_ret_value_type)
    {
        EXPECT_TRUE((std::is_same_v<value_type&&, decltype(cpputil::move(cpputil::declval<value_type&>()))>));
        EXPECT_TRUE((std::is_same_v<value_type&&, decltype(cpputil::move(cpputil::declval<value_type>()))>));
    }

    TYPED_TEST(move_typed_test, test_move_noexcept)
    {
        EXPECT_TRUE(noexcept(cpputil::move(cpputil::declval<value_type&>())));
        EXPECT_TRUE(noexcept(cpputil::move(cpputil::declval<value_type>())));
    }

    TYPED_TEST(move_if_noexcept_typed_test, test_move_if_noexcept_ret_value_type)
    {
        EXPECT_TRUE((
            std::is_same_v<
                std::conditional_t<cpputil::detail::move_if_noexcept_condition_v<value_type>, const value_type&, value_type&&>,
                decltype(cpputil::move_if_noexcept(cpputil::declval<value_type&>()))
            >
        ));
    }

    TYPED_TEST(move_if_noexcept_typed_test, test_move_if_noexcept_noexcept)
    {
        EXPECT_TRUE(noexcept(cpputil::move_if_noexcept(cpputil::declval<value_type&>())));
    }
}