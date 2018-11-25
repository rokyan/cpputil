#include <gtest.hpp>
#include <common.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>

namespace test
{

struct accumulator
{
    void operator()(int value) noexcept { acc += value; }

    int acc = 0;
};

TEST(ForEachTest, TestForEach)
{
    std::vector<int> empty;
    std::vector<int> data{ 1, 2, 3, 4, 5 };

    auto func = [](int& elem) { elem *= elem; };

    cpputil::for_each(cpputil::begin(empty), cpputil::end(empty), func);
    EXPECT_EQ(empty, std::vector<int>{});

    const std::vector<int> expected{ 1, 4, 9, 16, 25 };
    cpputil::for_each(cpputil::begin(data), cpputil::end(data), func);
    EXPECT_EQ(data, expected);
}

TEST(ForEachTest, TestForEachN)
{
    std::vector<int> data{ 0, 0, 0, 0, 0 };

    auto func = [](int& elem) { ++elem; };

    for (auto i = std::size_t{ 0 }; i <= data.size(); ++i)
    {
        cpputil::for_each_n(cpputil::begin(data), i, func);
    }

    const std::vector<int> expected{ 5, 4, 3, 2, 1 };
    EXPECT_EQ(data, expected);
}

TEST(ForEachTest, TestReturnValue)
{
    std::vector<int> data{ 1, 2, 3, 4, 5 };

    accumulator acc1;
    accumulator ret1 = cpputil::for_each(cpputil::begin(data), cpputil::end(data), acc1);

    EXPECT_EQ(ret1.acc, 15);

    accumulator acc2;
    accumulator ret2 = cpputil::for_each_n(cpputil::begin(data), data.size(), acc2);

    EXPECT_EQ(ret2.acc, 15);
}

} // namespace test
