#include <gtest.hpp>
#include <algorithm.hpp>
#include <range_access.hpp>
#include <iterator_operations.hpp>
#include <vector>

namespace test
{

TEST(FindTest, TestEmptyRange)
{
    const auto predicate = [](int value) { return value == 1; };

    std::vector<int> empty;

    EXPECT_EQ(cpputil::find(cpputil::begin(empty), cpputil::end(empty), 1),
        cpputil::end(empty));
    EXPECT_EQ(cpputil::find_if(cpputil::begin(empty), cpputil::end(empty), predicate),
        cpputil::end(empty));
    EXPECT_EQ(cpputil::find_if_not(cpputil::begin(empty), cpputil::end(empty), predicate),
        cpputil::end(empty));
}

TEST(FindTest, TestLookingForExistingElement)
{
    const auto predicate = [](int value) { return value == 1; };
    const auto negative_predicate = [](int value) { return value != 1; };

    std::vector<int> data{ 2, 4, 1, 2, 1 };

    EXPECT_EQ(cpputil::find(cpputil::begin(data), cpputil::end(data), 1),
        cpputil::next(cpputil::begin(data), 2));
    EXPECT_EQ(cpputil::find_if(cpputil::begin(data), cpputil::end(data), predicate),
        cpputil::next(cpputil::begin(data), 2));
    EXPECT_EQ(cpputil::find_if_not(cpputil::begin(data), cpputil::end(data), negative_predicate),
        cpputil::next(cpputil::begin(data), 2));
}

TEST(FindTest, TestLookingForNonExistingElement)
{
    const auto predicate = [](int value) { return value == 1; };
    const auto negative_predicate = [](int value) { return value != 1; };

    std::vector<int> data{ 2, 4, 2 };

    EXPECT_EQ(cpputil::find(cpputil::begin(data), cpputil::end(data), 1),
        cpputil::end(data));
    EXPECT_EQ(cpputil::find_if(cpputil::begin(data), cpputil::end(data), predicate),
        cpputil::end(data));
    EXPECT_EQ(cpputil::find_if_not(cpputil::begin(data), cpputil::end(data), negative_predicate),
        cpputil::end(data));
}

TEST(FindFirstOfTest, TestEmptyRange)
{
    const auto pred = [](int x, int y) { return x == y; };

    std::vector<int> empty;
    std::vector<int> data{ 0, 1, 2 };

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(empty), cpputil::end(empty),
        cpputil::begin(data), cpputil::end(data)), cpputil::end(empty));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data), cpputil::end(data),
        cpputil::begin(empty), cpputil::end(empty)), cpputil::end(data));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(empty), cpputil::begin(empty),
        cpputil::begin(empty), cpputil::end(empty)), cpputil::end(empty));

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(empty), cpputil::end(empty),
        cpputil::begin(data), cpputil::end(data), pred), cpputil::end(empty));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data), cpputil::end(data),
        cpputil::begin(empty), cpputil::end(empty), pred), cpputil::end(data));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(empty), cpputil::begin(empty),
        cpputil::begin(empty), cpputil::end(empty), pred), cpputil::end(empty));
}

TEST(FindFirstOfTest, TestOverlappingRanges)
{
    const auto pred = [](int x, int y) { return x == y; };

    std::vector<int> data_1{ 0, 1 };
    std::vector<int> data_2{ 2, 0, 2 };

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_2), cpputil::end(data_2)), cpputil::begin(data_1));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_2), cpputil::end(data_2), pred), cpputil::begin(data_1));

    std::vector<int> data_3{ 0, 1 };
    std::vector<int> data_4{ 2, 1, 2 };

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_3), cpputil::end(data_3),
        cpputil::begin(data_4), cpputil::end(data_4)), --cpputil::end(data_3));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_3), cpputil::end(data_3),
        cpputil::begin(data_4), cpputil::end(data_4), pred), --cpputil::end(data_3));
}

TEST(FindFirstOfTest, TestNonOverlappingRanges)
{
    const auto pred = [](int x, int y) { return x == y; };

    std::vector<int> data_1{ 0, 1 };
    std::vector<int> data_2{ 2, 3 };

    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_2), cpputil::end(data_2)), cpputil::end(data_1));
    EXPECT_EQ(cpputil::find_first_of(cpputil::begin(data_1), cpputil::end(data_1),
        cpputil::begin(data_2), cpputil::end(data_2), pred), cpputil::end(data_1));
}

} // namespace test
