#pragma once

/**
 * Wrapper for gtest\gtest.h
 */

#include <gtest\gtest.h>

#define SAME_TYPES(TYPE_X, TYPE_Y) EXPECT_TRUE((traits::is_same_v<TYPE_X, TYPE_Y>))
#define NOT_SAME_TYPES(TYPE_X, TYPE_Y) EXPECT_FALSE((traits::is_same_v<TYPE_X, TYPE_Y>))
