#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(RankTest, TestRank)
{
    EXPECT_EQ(cpputil::rank_v<T0>, 0);

    EXPECT_EQ(cpputil::rank_v<T0[]>, 1);
    EXPECT_EQ(cpputil::rank_v<T0[1]>, 1);

    EXPECT_EQ(cpputil::rank_v<T0[][1]>, 2);
    EXPECT_EQ(cpputil::rank_v<T0[1][1]>, 2);
}

} // namespace test