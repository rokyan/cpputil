#include <gtest.hpp>
#include <utility.hpp>
#include <traits.hpp>
#include <move_test_types.hpp>

namespace test
{
    using move_if_noexcept_test_types = make_test_types<
        movable_noexcept_non_copyable,
        movable_non_copyable,
        copyable_noexcept_non_movable,
        copyable_non_movable,
        movable_noexcept_copyable_noexcept,
        movable_copyable
    >;

    DECLARE_TYPED_TEST_NAME(MoveIfNoexceptTypedTest);
    TYPED_TEST_CASE(MoveIfNoexceptTypedTest, move_if_noexcept_test_types);

    TEST(MoveTest, TestMoveRetValueType)
    {
        EXPECT_TRUE((std::is_same_v<T0&&, decltype(cpputil::move(cpputil::declval<T0&>()))>));
        EXPECT_TRUE((std::is_same_v<T0&&, decltype(cpputil::move(cpputil::declval<T0>()))>));
    }

    TEST(MoveIfNoexceptTypedTest, TestMoveNoexcept)
    {
        EXPECT_TRUE(noexcept(cpputil::move(cpputil::declval<T0&>())));
        EXPECT_TRUE(noexcept(cpputil::move(cpputil::declval<T0>())));
    }

    TYPED_TEST(MoveIfNoexceptTypedTest, TestMoveIfNoexceptRetValueType)
    {
        using expected_type = cpputil::conditional_t<cpputil::detail::move_if_noexcept_condition_v<TypeParam>, const TypeParam&, TypeParam&&>;
        using actual_type = decltype(cpputil::move_if_noexcept(cpputil::declval<TypeParam&>()));

        EXPECT_SAME_TYPES(expected_type, actual_type);
    }

    TYPED_TEST(MoveIfNoexceptTypedTest, TestMoveIfNoexceptNoexcept)
    {
        EXPECT_TRUE(noexcept(cpputil::move_if_noexcept(cpputil::declval<TypeParam&>())));
    }
}