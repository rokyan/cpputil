#include <gtest.hpp>
#include <literals.hpp>

namespace test
{
    TEST(LiteralsTest, TestZULiteral)
    {
        using namespace cpputil::literals;

        auto from_int = 1_zu;

        EXPECT_SAME_TYPES(std::size_t, decltype(from_int));
        EXPECT_EQ(std::size_t{ 1 }, from_int);

        auto from_double = 1.1_zu;

        EXPECT_SAME_TYPES(std::size_t, decltype(from_double));
        EXPECT_EQ(std::size_t{ 1 }, from_double);
    }
}