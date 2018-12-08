#include <gtest.hpp>
#include <thread.hpp>

namespace test
{

TEST(AsyncTest, TestAlwaysAsync)
{
    auto sum = [](int x, int y) { return x + y; };

    const auto sum_1 = cpputil::always_async(sum, 1, 2);
    const auto sum_2 = cpputil::always_async(sum, 3, 4);

    EXPECT_EQ(sum_1.get() + sum_2.get(), 10);
}

} // namespace test
