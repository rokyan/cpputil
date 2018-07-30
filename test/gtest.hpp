/**
 * Wrapper for gtest\gtest.h
 */

#include <gtest\gtest.h>

#define EXPECT_SAME_TYPES(TYPE_X, TYPE_Y) \
    EXPECT_TRUE((traits::is_same_v<TYPE_X, TYPE_Y>))
#define EXPECT_DIFFERENT_TYPES(TYPE_X, TYPE_Y) \
    EXPECT_FALSE((traits::is_same_v<TYPE_X, TYPE_Y>))
#define ASSERT_SAME_TYPES(TYPE_X, TYPE_Y) \
    ASSERT_TRUE((traits::is_same_v<TYPE_X, TYPE_Y>))
#define ASSERT_DIFFERENT_TYPES(TYPE_X, TYPE_Y) \
    ASSERT_FALSE((traits::is_same_v<TYPE_X, TYPE_Y>))
