#include <gtest.hpp>
#include <distance.hpp>
#include <functional>

namespace test
{
    // value_type, pointer and reference actual values are insufficient for tests.

    template<typename IteratorCategory>
    struct iterator_mock
    {
        using iterator_category = IteratorCategory;
        using difference_type = std::size_t;
        using value_type = void;
        using pointer = void;
        using reference = void;

        using callback_type = std::function<void()>;

        iterator_mock(std::size_t value, callback_type callback)
            : value{ value }
            , callback{ callback }
        {}

        iterator_mock& operator++()
        {
            callback();
            ++value;
            return *this;
        }

        callback_type callback;
        std::size_t value;
    };

    template<typename IteratorCategory>
    std::size_t operator-(const iterator_mock<IteratorCategory>& left, const iterator_mock<IteratorCategory>& right)
    {
        return left.value - right.value;
    }

    template<typename IteratorCategory>
    bool operator==(const iterator_mock<IteratorCategory>& left, const iterator_mock<IteratorCategory>& right)
    {
        return left.value == right.value;
    }

    template<typename IteratorCategory>
    bool operator!=(const iterator_mock<IteratorCategory>& left, const iterator_mock<IteratorCategory>& right)
    {
        return left.value != right.value;
    }

    using input_iterator_mock = iterator_mock<cpputil::input_iterator_tag>;
    using random_access_iterator_mock = iterator_mock<cpputil::random_access_iterator_tag>;

    TEST(DistanceTest, TestInputIterator)
    {
        std::size_t increment_counter = 0;
        auto callback = [&cnt = increment_counter]() { ++cnt; };
        auto noop = [] {};

        input_iterator_mock first_input_it{ 0, callback };
        input_iterator_mock last_input_it{ 4, noop };

        std::size_t distance = cpputil::distance(first_input_it, last_input_it);

        EXPECT_EQ(distance, 4) <<
            "Wrong distance is calculated";
        EXPECT_EQ(increment_counter, 4) <<
            "First iterator has been incremented wrong number of times";
    }

    TEST(DistanceTest, TestRandomAccessterator)
    {
        std::size_t increment_counter = 0;
        auto callback = [&cnt = increment_counter]() { ++cnt; };
        auto noop = [] {};

        random_access_iterator_mock first_ra_it{ 0, callback };
        random_access_iterator_mock last_ra_it{ 4, noop };

        std::size_t distance = cpputil::distance(first_ra_it, last_ra_it);

        EXPECT_EQ(distance, 4) <<
            "Wrong distance is calculated";
        EXPECT_EQ(increment_counter, 0) <<
            "First iterator has been incremented wrong number of times";
    }
}