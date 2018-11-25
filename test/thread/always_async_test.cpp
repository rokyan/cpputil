#include <gtest.hpp>
#include <thread.hpp>

namespace test
{

TEST(AlwaysAsyncTest, TestAlwaysAsync)
{
    auto sum = [](int x, int y) { return x + y; };
    auto result = cpputil::always_async(sum, 1, 2);

    EXPECT_EQ(result.get(), 3);
}

} // namespace test
