#include <gtest.hpp>
#include <advance.hpp>
#include "iterator_mocks.hpp"

namespace test
{
    TEST(AdvanceTest, TestInputIterator)
    {
        std::size_t increment_counter = 0;
        auto callback = [&cnt = increment_counter]() { ++cnt; };

        input_iterator_mock it{ 0 };
        it.set_increment_callback(callback);

        cpputil::advance(it, 4);

        EXPECT_EQ(increment_counter, 4) <<
            "Iterator has been incremented wrong number of times";
    }

    TEST(AdvanceTest, TestBidirectionalIterator)
    {
        std::size_t increment_counter = 0;
        auto increment_callback = [&cnt = increment_counter]() { ++cnt; };

        std::size_t decrement_counter = 0;
        auto decrement_callback = [&cnt = decrement_counter]() { ++cnt; };

        bidirectional_iterator_mock it{ 0 };
        it.set_increment_callback(increment_callback);
        it.set_decrement_callback(decrement_callback);

        cpputil::advance(it, 4);
        cpputil::advance(it, -4);

        EXPECT_EQ(increment_counter, 4) <<
            "Iterator has been incremented wrong number of times";
        EXPECT_EQ(decrement_counter, 4) <<
            "Iterator has been decremented wrong number of times";
    }

    TEST(AdvanceTest, TestRandomAccessIterator)
    {
        std::size_t increment_counter = 0;
        auto increment_callback = [&cnt = increment_counter]() { ++cnt; };

        std::size_t decrement_counter = 0;
        auto decrement_callback = [&cnt = decrement_counter]() { ++cnt; };

        random_access_iterator_mock it{ 0 };
        it.set_increment_callback(increment_callback);
        it.set_decrement_callback(decrement_callback);

        cpputil::advance(it, 4);
        cpputil::advance(it, -4);

        EXPECT_EQ(increment_counter, 1) <<
            "Iterator has been incremented wrong number of times";
        EXPECT_EQ(decrement_counter, 1) <<
            "Iterator has been decremented wrong number of times";
    }
}
