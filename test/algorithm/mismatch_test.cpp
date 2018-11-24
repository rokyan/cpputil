#include <gtest.hpp>
#include <mismatch.hpp>
#include <prev.hpp>
#include <vector>

namespace test
{

TEST(MismatchTest, TestEmptyRanges)
{
    using std::end;

    std::vector<int> data1;
    std::vector<int> data2;

    auto predicate = [](int x, int y) { return 2 * x == y; };

    const auto result1 = cpputil::mismatch(begin(data1), end(data1), begin(data2));

    EXPECT_EQ(result1.first, end(data1));
    EXPECT_EQ(result1.second, end(data2));

    const auto result2 = cpputil::mismatch(begin(data1), end(data1), begin(data2), predicate);

    EXPECT_EQ(result2.first, end(data1));
    EXPECT_EQ(result2.second, end(data2));

    const auto result3 = cpputil::mismatch(begin(data1), end(data1), begin(data2), end(data2));

    EXPECT_EQ(result3.first, end(data1));
    EXPECT_EQ(result3.second, end(data2));

    const auto result4 = cpputil::mismatch(begin(data1), end(data1), begin(data2), end(data2), predicate);

    EXPECT_EQ(result4.first, end(data1));
    EXPECT_EQ(result4.second, end(data2));
}

TEST(MismatchTest, TestFirstEmptyRange)
{
    using std::begin;
    using std::end;

    std::vector<int> data1;
    std::vector<int> data2{ 1 };

    auto predicate = [](int x, int y) { return 2 * x == y; };

    const auto result1 = cpputil::mismatch(begin(data1), end(data1), begin(data2));

    EXPECT_EQ(result1.first, end(data1));
    EXPECT_EQ(result1.second, begin(data2));

    const auto result2 = cpputil::mismatch(begin(data1), end(data1), begin(data2), predicate);

    EXPECT_EQ(result2.first, end(data1));
    EXPECT_EQ(result2.second, begin(data2));

    const auto result3 = cpputil::mismatch(begin(data1), end(data1), begin(data2), end(data2));

    EXPECT_EQ(result3.first, end(data1));
    EXPECT_EQ(result3.second, begin(data2));

    const auto result4 = cpputil::mismatch(begin(data1), end(data1), begin(data2), end(data2), predicate);

    EXPECT_EQ(result4.first, end(data1));
    EXPECT_EQ(result4.second, begin(data2));
}

TEST(MismatchTest, TestLastEmptyRange)
{
    using std::begin;
    using std::end;

    std::vector<int> data1{ 1 };
    std::vector<int> data2;

    auto predicate = [](int x, int y) { return 2 * x == y; };

    const auto result1 = cpputil::mismatch(begin(data1), end(data1), begin(data2), end(data2));

    EXPECT_EQ(result1.first, begin(data1));
    EXPECT_EQ(result1.second, end(data2));

    const auto result2 = cpputil::mismatch(begin(data1), end(data1), begin(data2), end(data2), predicate);

    EXPECT_EQ(result2.first, begin(data1));
    EXPECT_EQ(result2.second, end(data2));
}

TEST(MismatchTest, TestMismatch)
{
    using std::begin;
    using std::end;

    std::vector<int> data1{ 0, 1, 2 };
    std::vector<int> data2{ 0, 1, 3 };

    const auto result1 = cpputil::mismatch(begin(data1), end(data1), begin(data2));

    EXPECT_EQ(result1.first, cpputil::prev(end(data1)));
    EXPECT_EQ(result1.second, cpputil::prev(end(data2)));

    const auto result2 = cpputil::mismatch(begin(data1), end(data1), begin(data2), end(data2));

    EXPECT_EQ(result2.first, cpputil::prev(end(data1)));
    EXPECT_EQ(result2.second, cpputil::prev(end(data2)));
}

TEST(MismatchTest, TestMismatchWithPredicate)
{
    using std::begin;
    using std::end;

    std::vector<int> data1{ 0, 1, 2 };
    std::vector<int> data2{ 0, 2, 3 };

    auto predicate = [](int x, int y) { return 2 * x == y; };

    const auto result1 = cpputil::mismatch(begin(data1), end(data1), begin(data2), predicate);

    EXPECT_EQ(result1.first, cpputil::prev(end(data1)));
    EXPECT_EQ(result1.second, cpputil::prev(end(data2)));

    const auto result2 = cpputil::mismatch(begin(data1), end(data1), begin(data2), end(data2), predicate);

    EXPECT_EQ(result2.first, cpputil::prev(end(data1)));
    EXPECT_EQ(result2.second, cpputil::prev(end(data2)));
}

} // namespace test
