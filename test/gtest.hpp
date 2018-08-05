/**
 * Wrapper for gtest\gtest.h
 */

#pragma once

#include <gtest\gtest.h>

template<typename T>
class test_base : public testing::Test
{
public:
    using value_type = T;
};

template<typename... Ts>
using make_types = testing::Types<Ts...>;

// implement basic is_same type trait to avoid
// dependencies on any type trait headers.

namespace detail
{
    template<typename, typename>
    struct same_types
    {
        constexpr static auto value = false;
    };

    template<typename T>
    struct same_types<T, T>
    {
        constexpr static auto value = true;
    };

    template<typename T, typename U>
    inline constexpr auto same_types_v = same_types<T, U>::value;
}

#define EXPECT_SAME_TYPES(TYPE_X, TYPE_Y) \
    EXPECT_TRUE((detail::same_types_v<TYPE_X, TYPE_Y>))
#define EXPECT_DIFFERENT_TYPES(TYPE_X, TYPE_Y) \
    EXPECT_FALSE((detail::same_types_v<TYPE_X, TYPE_Y>))
#define ASSERT_SAME_TYPES(TYPE_X, TYPE_Y) \
    ASSERT_TRUE((detail::same_types_v<TYPE_X, TYPE_Y>))
#define ASSERT_DIFFERENT_TYPES(TYPE_X, TYPE_Y) \
    ASSERT_FALSE((detail::same_types_v<TYPE_X, TYPE_Y>))
