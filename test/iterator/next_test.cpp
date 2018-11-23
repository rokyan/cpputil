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

    it = cpputil::next(it, 1);

    EXPECT_EQ(increment_counter, 1);
    EXPECT_EQ(it.get_value(), 1);

    it = cpputil::next(it, 2);

    EXPECT_EQ(increment_counter, 3);
    EXPECT_EQ(it.get_value(), 3);

    it = cpputil::next(it, 3);

    EXPECT_EQ(increment_counter, 6);
    EXPECT_EQ(it.get_value(), 6);
}

} // namespace test
