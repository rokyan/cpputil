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
        EXPECT_EQ(1, from_int);
    }
}