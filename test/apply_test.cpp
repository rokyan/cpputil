#include <gtest\gtest.h>
#include <apply.h>

namespace test
{
    TEST(apply_test, test_apply)
    {
        const auto callable = [](int x, int y) { return x + y; };

        EXPECT_EQ(cpputil::apply(callable, std::make_tuple(1, 2)), 3);
    }
}