#include <gtest.hpp>
#include <algorithm.hpp>
#include <functional.hpp>
#include <iterator.hpp>
#include <common.hpp>

namespace test
{

#define RANGE(cont)     cont.begin(), cont.end()

TEST(MinMaxOpsTest, TestMaxElement)
{
    integer_container empty;

    {
        const auto expected = empty.begin();
        EXPECT_EQ(cpputil::max_element(RANGE(empty)), expected);
    }
    {
        const auto expected = empty.begin();
        EXPECT_EQ(cpputil::max_element(RANGE(empty), cpputil::less()), expected);
    }

    integer_container single_elem{ 0 };

    {
        const auto expected = single_elem.begin();
        EXPECT_EQ(cpputil::max_element(RANGE(single_elem)), expected);
    }
    {
        const auto expected = single_elem.begin();
        EXPECT_EQ(cpputil::max_element(RANGE(single_elem), cpputil::less()), expected);
    }

    integer_container two_elems{ 0, 1 };

    {
        const auto expected = cpputil::prev(two_elems.end());
        EXPECT_EQ(cpputil::max_element(RANGE(two_elems)), expected);
    }
    {
        const auto expected = cpputil::prev(two_elems.end());
        EXPECT_EQ(cpputil::max_element(RANGE(two_elems), cpputil::less()), expected);
    }

    integer_container multiple_elems{ 0, 1, 0, 1 };

    {
        const auto expected = cpputil::next(multiple_elems.begin());
        EXPECT_EQ(cpputil::max_element(RANGE(multiple_elems)), expected);
    }
    {
        const auto expected = cpputil::next(multiple_elems.begin());
        EXPECT_EQ(cpputil::max_element(RANGE(multiple_elems), cpputil::less()), expected);
    }
}

TEST(MinMaxOpsTest, TestMinElement)
{
    integer_container empty;

    {
        const auto expected = empty.end();
        EXPECT_EQ(cpputil::min_element(RANGE(empty)), expected);
    }
    {
        const auto expected = empty.end();
        EXPECT_EQ(cpputil::min_element(RANGE(empty), cpputil::less()), expected);
    }

    integer_container single_elem{ 0 };

    {
        const auto expected = single_elem.begin();
        EXPECT_EQ(cpputil::min_element(RANGE(single_elem)), expected);
    }
    {
        const auto expected = single_elem.begin();
        EXPECT_EQ(cpputil::min_element(RANGE(single_elem), cpputil::less()), expected);
    }

    integer_container two_elems{ 0, 1 };

    {
        const auto expected = two_elems.begin();
        EXPECT_EQ(cpputil::min_element(RANGE(two_elems)), expected);
    }
    {
        const auto expected = two_elems.begin();
        EXPECT_EQ(cpputil::min_element(RANGE(two_elems), cpputil::less()), expected);
    }

    integer_container multiple_elems{ 0, 1, 0, 1 };

    {
        const auto expected = multiple_elems.begin();
        EXPECT_EQ(cpputil::min_element(RANGE(multiple_elems)), expected);
    }
    {
        const auto expected = multiple_elems.begin();
        EXPECT_EQ(cpputil::min_element(RANGE(multiple_elems), cpputil::less()), expected);
    }
}

TEST(MinMaxOpsTest, TestMinMaxElement)
{
    integer_container empty;

    {
        const auto expected = std::make_pair(empty.end(), empty.end());
        EXPECT_EQ(cpputil::minmax_element(RANGE(empty)), expected);
    }
    {
        const auto expected = std::make_pair(empty.end(), empty.end());
        EXPECT_EQ(cpputil::minmax_element(RANGE(empty), cpputil::less()), expected);
    }

    integer_container single_elem{ 0 };

    {
        const auto expected = std::make_pair(single_elem.begin(), single_elem.begin());
        EXPECT_EQ(cpputil::minmax_element(RANGE(single_elem)), expected);
    }
    {
        const auto expected = std::make_pair(single_elem.begin(), single_elem.begin());
        EXPECT_EQ(cpputil::minmax_element(RANGE(single_elem), cpputil::less()), expected);
    }

    integer_container two_elems{ 0, 1 };

    {
        const auto expected = std::make_pair(two_elems.begin(), cpputil::prev(two_elems.end()));
        EXPECT_EQ(cpputil::minmax_element(RANGE(two_elems)), expected);
    }
    {
        const auto expected = std::make_pair(two_elems.begin(), cpputil::prev(two_elems.end()));
        EXPECT_EQ(cpputil::minmax_element(RANGE(two_elems), cpputil::less()), expected);
    }

    integer_container multiple_elems{ 0, 1, 0, 1 };

    {
        const auto expected = std::make_pair(multiple_elems.begin(), cpputil::prev(multiple_elems.end()));
        EXPECT_EQ(cpputil::minmax_element(RANGE(multiple_elems)), expected);
    }
    {
        const auto expected = std::make_pair(multiple_elems.begin(), cpputil::prev(multiple_elems.end()));
        EXPECT_EQ(cpputil::minmax_element(RANGE(multiple_elems)), expected);
    }
}

TEST(MinMaxOpsTest, TestMax)
{
    EXPECT_EQ(cpputil::max(0, 1), 1);
    EXPECT_EQ(cpputil::max(0, 1, cpputil::less()), 1);

    EXPECT_EQ(cpputil::max({ 0, 2, 1, 3 }), 3);
    EXPECT_EQ(cpputil::max({ 0, 2, 1, 3 }, cpputil::less()), 3);
}

TEST(MinMaxOpsTest, TestMin)
{
    EXPECT_EQ(cpputil::min(0, 1), 0);
    EXPECT_EQ(cpputil::min(0, 1, cpputil::less()), 0);

    EXPECT_EQ(cpputil::min({ 1, 2, 0, 3 }), 0);
    EXPECT_EQ(cpputil::min({ 1, 2, 0, 3 }, cpputil::less()), 0);
}

TEST(MinMaxOpsTest, TestMinMax)
{
    {
        const auto& result = cpputil::minmax(1, 0);

        EXPECT_EQ(result.first, 0);
        EXPECT_EQ(result.second, 1);
    }
    {
        const auto& result = cpputil::minmax(1, 0, std::less());

        EXPECT_EQ(result.first, 0);
        EXPECT_EQ(result.second, 1);
    }

    {
        const auto& result = cpputil::minmax({ 1, 2, 0, 3 });

        EXPECT_EQ(result.first, 0);
        EXPECT_EQ(result.second, 3);
    }
    {
        const auto& result = cpputil::minmax({ 1, 2, 0, 3 }, std::less());

        EXPECT_EQ(result.first, 0);
        EXPECT_EQ(result.second, 3);
    }
}

TEST(MinMaxOpsTest, TestClamp)
{
    EXPECT_EQ(cpputil::clamp(0, 1, 3), 1);
    EXPECT_EQ(cpputil::clamp(0, 1, 3, cpputil::less()), 1);

    EXPECT_EQ(cpputil::clamp(1, 1, 3), 1);
    EXPECT_EQ(cpputil::clamp(1, 1, 3, cpputil::less()), 1);

    EXPECT_EQ(cpputil::clamp(2, 1, 3), 2);
    EXPECT_EQ(cpputil::clamp(2, 1, 3, cpputil::less()), 2);

    EXPECT_EQ(cpputil::clamp(3, 1, 3), 3);
    EXPECT_EQ(cpputil::clamp(3, 1, 3, cpputil::less()), 3);

    EXPECT_EQ(cpputil::clamp(4, 1, 3), 3);
    EXPECT_EQ(cpputil::clamp(4, 1, 3, cpputil::less()), 3);
}

} // namespace test