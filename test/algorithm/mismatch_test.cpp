#include <gtest.hpp>
#include <mismatch.hpp>
#include <range_access.hpp>
#include <iterator_operations.hpp>
#include <vector>

namespace test
{

TEST(MismatchTest, TestEmptyRanges)
{
    std::vector<int> data1;
    std::vector<int> data2;

    auto predicate = [](int x, int y) { return 2 * x == y; };

    const auto result1 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2));

    EXPECT_EQ(result1.first, cpputil::end(data1));
    EXPECT_EQ(result1.second, cpputil::end(data2));

    const auto result2 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), predicate);

    EXPECT_EQ(result2.first, cpputil::end(data1));
    EXPECT_EQ(result2.second, cpputil::end(data2));

    const auto result3 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), cpputil::end(data2));

    EXPECT_EQ(result3.first, cpputil::end(data1));
    EXPECT_EQ(result3.second, cpputil::end(data2));

    const auto result4 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), cpputil::end(data2), predicate);

    EXPECT_EQ(result4.first, cpputil::end(data1));
    EXPECT_EQ(result4.second, cpputil::end(data2));
}

TEST(MismatchTest, TestFirstEmptyRange)
{
    std::vector<int> data1;
    std::vector<int> data2{ 1 };

    auto predicate = [](int x, int y) { return 2 * x == y; };

    const auto result1 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2));

    EXPECT_EQ(result1.first, cpputil::end(data1));
    EXPECT_EQ(result1.second, cpputil::begin(data2));

    const auto result2 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), predicate);

    EXPECT_EQ(result2.first, cpputil::end(data1));
    EXPECT_EQ(result2.second, cpputil::begin(data2));

    const auto result3 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), cpputil::end(data2));

    EXPECT_EQ(result3.first, cpputil::end(data1));
    EXPECT_EQ(result3.second, cpputil::begin(data2));

    const auto result4 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), cpputil::end(data2), predicate);

    EXPECT_EQ(result4.first, cpputil::end(data1));
    EXPECT_EQ(result4.second, cpputil::begin(data2));
}

TEST(MismatchTest, TestLastEmptyRange)
{
    std::vector<int> data1{ 1 };
    std::vector<int> data2;

    auto predicate = [](int x, int y) { return 2 * x == y; };

    const auto result1 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), cpputil::end(data2));

    EXPECT_EQ(result1.first, cpputil::begin(data1));
    EXPECT_EQ(result1.second, cpputil::end(data2));

    const auto result2 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), cpputil::end(data2), predicate);

    EXPECT_EQ(result2.first, cpputil::begin(data1));
    EXPECT_EQ(result2.second, cpputil::end(data2));
}

TEST(MismatchTest, TestMismatch)
{
    std::vector<int> data1{ 0, 1, 2 };
    std::vector<int> data2{ 0, 1, 3 };

    const auto result1 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2));

    EXPECT_EQ(result1.first, cpputil::prev(cpputil::end(data1)));
    EXPECT_EQ(result1.second, cpputil::prev(cpputil::end(data2)));

    const auto result2 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), cpputil::end(data2));

    EXPECT_EQ(result2.first, cpputil::prev(cpputil::end(data1)));
    EXPECT_EQ(result2.second, cpputil::prev(cpputil::end(data2)));
}

TEST(MismatchTest, TestMismatchWithPredicate)
{
    std::vector<int> data1{ 0, 1, 2 };
    std::vector<int> data2{ 0, 2, 3 };

    auto predicate = [](int x, int y) { return 2 * x == y; };

    const auto result1 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), predicate);

    EXPECT_EQ(result1.first, cpputil::prev(cpputil::end(data1)));
    EXPECT_EQ(result1.second, cpputil::prev(cpputil::end(data2)));

    const auto result2 = cpputil::mismatch(cpputil::begin(data1), cpputil::end(data1), cpputil::begin(data2), cpputil::end(data2), predicate);

    EXPECT_EQ(result2.first, cpputil::prev(cpputil::end(data1)));
    EXPECT_EQ(result2.second, cpputil::prev(cpputil::end(data2)));
}

} // namespace test
