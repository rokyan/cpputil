#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

struct empty {};
struct alignas(32) empty_32 {};
struct alignas(64) empty_64 {};

TEST(AlignmentOfTest, TestAlignmentOf)
{
    // Default alignment.
    EXPECT_EQ(cpputil::alignment_of_v<empty>, alignof(empty));

    // Custom alignment.
    EXPECT_EQ(cpputil::alignment_of_v<empty_32>, 32);
    EXPECT_EQ(cpputil::alignment_of_v<empty_64>, 64);
}

} // namespace test