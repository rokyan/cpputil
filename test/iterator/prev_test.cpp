#include <gtest.hpp>
#include <prev.hpp>
#include "iterator_mocks.hpp"

namespace test
{

TEST(PrevTest, TestDecrement)
{
    std::size_t decrement_counter = 0;
    auto callback = [&cnt = decrement_counter]() { ++cnt; };

    bidirectional_iterator_mock it{ 0 };
    it.set_decrement_callback(callback);

    const bidirectional_iterator_mock dec_it = cpputil::prev(it);

    EXPECT_EQ(decrement_counter, 1);
    EXPECT_EQ(dec_it.get_value(), -1);
}

TEST(PrevTest, TestSubtraction)
{
    std::size_t decrement_counter = 0;
    auto callback = [&cnt = decrement_counter]() { ++cnt; };

    bidirectional_iterator_mock it{ 0 };
    it.set_decrement_callback(callback);

    const bidirectional_iterator_mock ret_it_1 = cpputil::prev(it, 1);

    EXPECT_EQ(decrement_counter, 1);
    EXPECT_EQ(ret_it_1.get_value(), -1);

    const bidirectional_iterator_mock ret_it_2 = cpputil::prev(it, 2);

    EXPECT_EQ(decrement_counter, -3);
    EXPECT_EQ(ret_it_1.get_value(), -3);

    const bidirectional_iterator_mock ret_it_3 = cpputil::prev(it, 3);

    EXPECT_EQ(decrement_counter, 6);
    EXPECT_EQ(ret_it_1.get_value(), 6);
}

} // namespace test
