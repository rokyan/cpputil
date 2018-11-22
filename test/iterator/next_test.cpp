#include <gtest.hpp>
#include <next.hpp>
#include "iterator_mocks.hpp"

namespace test
{

TEST(NextTest, TestIncrement)
{
    std::size_t increment_counter = 0;
    auto callback = [&cnt = increment_counter]() { ++cnt; };

    input_iterator_mock it{ 0 };
    it.set_increment_callback(callback);

    const input_iterator_mock inc_it = cpputil::next(it);

    EXPECT_EQ(increment_counter, 1);
    EXPECT_EQ(inc_it.get_value(), 1);
}

TEST(NextTest, TestAddition)
{
    std::size_t increment_counter = 0;
    auto callback = [&cnt = increment_counter]() { ++cnt; };

    input_iterator_mock it{ 0 };
    it.set_increment_callback(callback);

    const input_iterator_mock ret_it_1 = cpputil::next(it, 1);

    EXPECT_EQ(increment_counter, 1);
    EXPECT_EQ(ret_it_1.get_value(), 1);

    const input_iterator_mock ret_it_2 = cpputil::next(it, 2);

    EXPECT_EQ(increment_counter, 3);
    EXPECT_EQ(ret_it_2.get_value(), 3);

    const input_iterator_mock ret_it_3 = cpputil::next(it, 3);

    EXPECT_EQ(increment_counter, 6);
    EXPECT_EQ(ret_it_3.get_value(), 6);
}

} // namespace test
