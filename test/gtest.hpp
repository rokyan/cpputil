/**
 * Wrapper for gtest\gtest.h
 */

#include <gtest\gtest.h>

template<typename T>
class test_base : public testing::Test {};

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
}

#define EXPECT_SAME_TYPES(TYPE_X, TYPE_Y) \
    EXPECT_TRUE((detail::same_types<TYPE_X, TYPE_Y>::value))
#define EXPECT_DIFFERENT_TYPES(TYPE_X, TYPE_Y) \
    EXPECT_FALSE((detail::same_types<TYPE_X, TYPE_Y>::value))
#define ASSERT_SAME_TYPES(TYPE_X, TYPE_Y) \
    ASSERT_TRUE((detail::same_types<TYPE_X, TYPE_Y>::value))
#define ASSERT_DIFFERENT_TYPES(TYPE_X, TYPE_Y) \
    ASSERT_FALSE((detail::same_types<TYPE_X, TYPE_Y::value>))
