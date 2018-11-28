/**
 * Wrapper for Google Test gtest.h
 */

#pragma once

#include <gtest/gtest.h>

namespace test
{
    template<typename... Ts>
    using make_test_types = testing::Types<Ts...>;

    // Implement is_same type trait to avoid
    // dependencies on any type trait headers.

    namespace internal
    {
        template<typename, typename>
        struct is_same_type
        {
            constexpr static auto value = false;
        };

        template<typename T>
        struct is_same_type<T, T>
        {
            constexpr static auto value = true;
        };

        template<typename T, typename U>
        inline constexpr auto is_same_type_v = is_same_type<T, U>::value;
    }

    // Additional test macros.

#define DECLARE_TYPED_TEST_NAME(NAME) \
    template<typename> \
    class NAME : public testing::Test {};

#define EXPECT_SAME_TYPES(TYPE_X, TYPE_Y) \
    EXPECT_TRUE((internal::is_same_type_v<TYPE_X, TYPE_Y>))
#define EXPECT_DIFFERENT_TYPES(TYPE_X, TYPE_Y) \
    EXPECT_FALSE((internal::is_same_type_v<TYPE_X, TYPE_Y>))
#define ASSERT_SAME_TYPES(TYPE_X, TYPE_Y) \
    ASSERT_TRUE((internal::is_same_type_v<TYPE_X, TYPE_Y>))
#define ASSERT_DIFFERENT_TYPES(TYPE_X, TYPE_Y) \
    ASSERT_FALSE((internal::is_same_type_v<TYPE_X, TYPE_Y>))

    // Test types.

#define DECLARE_TEST_TYPE(TYPE_NAME) \
    struct TYPE_NAME {};

    DECLARE_TEST_TYPE(T0)
    DECLARE_TEST_TYPE(T1)
    DECLARE_TEST_TYPE(T2)
    DECLARE_TEST_TYPE(T3)
    DECLARE_TEST_TYPE(T4)
    DECLARE_TEST_TYPE(T5)
    DECLARE_TEST_TYPE(T6)
    DECLARE_TEST_TYPE(T7)
    DECLARE_TEST_TYPE(T8)
    DECLARE_TEST_TYPE(T9)
}
