#include <gtest.hpp>
#include <algorithm.hpp>
#include <vector>

namespace test
{

TEST(FindTest, TestEmptyRange)
{
    using std::begin;
    using std::end;

    const auto predicate = [](int value) { return value == 1; };

    std::vector<int> empty;

    EXPECT_EQ(cpputil::find(begin(empty), end(empty), 1), std::end(empty));
    EXPECT_EQ(cpputil::find_if(begin(empty), end(empty), predicate), std::end(empty));
    EXPECT_EQ(cpputil::find_if_not(begin(empty), end(empty), predicate), std::end(empty));
}

TEST(FindTest, TestLookingForExistingElement)
{
    using std::begin;
    using std::end;

    const auto predicate = [](int value) { return value == 1; };
    const auto negative_predicate = [](int value) { return value != 1; };

    std::vector<int> data{ 2, 4, 1, 2, 1 };

    const auto expected = std::next(std::begin(data), 2);

    EXPECT_EQ(cpputil::find(begin(data), end(data), 1), expected);
    EXPECT_EQ(cpputil::find_if(begin(data), end(data), predicate), expected);
    EXPECT_EQ(cpputil::find_if_not(begin(data), end(data), negative_predicate), expected);
}

TEST(FindTest, TestLookingForNonExistingElement)
{
    using std::begin;
    using std::end;

    const auto predicate = [](int value) { return value == 1; };
    const auto negative_predicate = [](int value) { return value != 1; };

    std::vector<int> data{ 2, 4, 2 };

    EXPECT_EQ(cpputil::find(begin(data), end(data), 1), end(data));
    EXPECT_EQ(cpputil::find_if(begin(data), end(data), predicate), end(data));
    EXPECT_EQ(cpputil::find_if_not(begin(data), end(data), negative_predicate), end(data));
}

TEST(FindFirstOfTest, TestEmptyRange)
{
    using std::begin;
    using std::end;

    const auto pred = [](int x, int y) { return x == y; };

    std::vector<int> empty;
    std::vector<int> data{ 0, 1, 2 };

    EXPECT_EQ(cpputil::find_first_of(begin(empty), end(empty), begin(data), end(data)), end(empty));
    EXPECT_EQ(cpputil::find_first_of(begin(data), end(data), begin(empty), end(empty)), end(data));
    EXPECT_EQ(cpputil::find_first_of(begin(empty), begin(empty), begin(empty), end(empty)), end(empty));

    EXPECT_EQ(cpputil::find_first_of(begin(empty), end(empty), begin(data), end(data), pred), end(empty));
    EXPECT_EQ(cpputil::find_first_of(begin(data), end(data), begin(empty), end(empty), pred), end(data));
    EXPECT_EQ(cpputil::find_first_of(begin(empty), begin(empty), begin(empty), end(empty), pred), end(empty));
}

TEST(FindFirstOfTest, TestOverlappingRanges)
{
    using std::begin;
    using std::end;

    const auto pred = [](int x, int y) { return x == y; };

    std::vector<int> data_1{ 0, 1 };
    std::vector<int> data_2{ 2, 0, 2 };

    EXPECT_EQ(cpputil::find_first_of(begin(data_1), end(data_1), begin(data_2), end(data_2)), begin(data_1));
    EXPECT_EQ(cpputil::find_first_of(begin(data_1), end(data_1), begin(data_2), end(data_2), pred), begin(data_1));

    std::vector<int> data_3{ 0, 1 };
    std::vector<int> data_4{ 2, 1, 2 };

    EXPECT_EQ(cpputil::find_first_of(begin(data_3), end(data_3), begin(data_4), end(data_4)), --end(data_3));
    EXPECT_EQ(cpputil::find_first_of(begin(data_3), end(data_3), begin(data_4), end(data_4), pred), --end(data_3));
}

TEST(FindFirstOfTest, TestNonOverlappingRanges)
{
    using std::begin;
    using std::end;

    const auto pred = [](int x, int y) { return x == y; };

    std::vector<int> data_1{ 0, 1 };
    std::vector<int> data_2{ 2, 3 };

    EXPECT_EQ(cpputil::find_first_of(begin(data_1), end(data_1), begin(data_2), end(data_2)), end(data_1));
    EXPECT_EQ(cpputil::find_first_of(begin(data_1), end(data_1), begin(data_2), end(data_2), pred), end(data_1));
}

} // namespace test
