#include <gtest.hpp>
#include <iterator_operations.hpp>
#include <iterator_mocks.hpp>

namespace test
{

TEST(DistanceTest, TestInputIterator)
{
    std::size_t increment_counter = 0;
    auto callback = [&cnt = increment_counter]() { ++cnt; };

    input_iterator_mock first_input_it{ 0 };
    input_iterator_mock last_input_it{ 4 };

    first_input_it.set_increment_callback(callback);

    const std::size_t distance = cpputil::distance(first_input_it, last_input_it);

    EXPECT_EQ(distance, 4) <<
        "Wrong distance is calculated";
    EXPECT_EQ(increment_counter, 4) <<
        "First iterator has been incremented wrong number of times";
}

TEST(DistanceTest, TestRandomAccessterator)
{
    std::size_t increment_counter = 0;
    auto callback = [&cnt = increment_counter]() { ++cnt; };

    random_access_iterator_mock first_rndac_it{ 0 };
    random_access_iterator_mock last_rndac_it{ 4 };

    first_rndac_it.set_increment_callback(callback);

    const std::size_t distance = cpputil::distance(first_rndac_it, last_rndac_it);

    EXPECT_EQ(distance, 4) <<
        "Wrong distance is calculated";
    EXPECT_EQ(increment_counter, 0) <<
        "First iterator has been incremented wrong number of times";
}

} // namespace test

