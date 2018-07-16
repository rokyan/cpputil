#include <gtest\gtest.h>
#include <literals.hpp>
#include <traits.hpp>

namespace test
{
    TEST(literals_test, test_zu_literal)
    {
        using namespace cpputil::literals;

        auto from_int = 1_zu;

        EXPECT_TRUE((traits::is_same_v<std::size_t, decltype(from_int)>));
        EXPECT_EQ(std::size_t{ 1 }, from_int);

        auto from_double = 1.1_zu;

        EXPECT_TRUE((traits::is_same_v<std::size_t, decltype(from_double)>));
        EXPECT_EQ(std::size_t{ 1 }, from_int);
    }
}