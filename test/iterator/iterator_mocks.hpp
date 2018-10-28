#ifndef CPPUTIL_ITERATOR_MOCKS
#define CPPUTIL_ITERATOR_MOCKS

#include <iterator_tags.hpp>

namespace test
{
    template<typename>
    class iterator_mock;

    template<typename IteratorCategory>
    auto operator-(const iterator_mock<IteratorCategory>&,
        const iterator_mock<IteratorCategory>&) -> std::size_t;
    template<typename IteratorCategory>
    auto operator==(const iterator_mock<IteratorCategory>&,
        const iterator_mock<IteratorCategory>&) -> bool;
    template<typename IteratorCategory>
    auto operator!=(const iterator_mock<IteratorCategory>&,
        const iterator_mock<IteratorCategory>&) -> bool;

    template<typename IteratorCategory>
    class iterator_mock
    {
    public:
        // value_type, pointer and reference actual values are insufficient for tests.
        using iterator_category = IteratorCategory;
        using difference_type = std::size_t;
        using value_type = void;
        using pointer = void;
        using reference = void;

    private:
        using increment_callback_type = std::function<void()>;
        using decrement_callback_type = std::function<void()>;

    public:
        iterator_mock(std::size_t value)
            : value{ value }
        {}

        auto operator++() -> iterator_mock&
        {
            increment_callback();
            ++value;

            return *this;
        }

        auto operator--() -> iterator_mock&
        {
            decrement_callback();
            --value;

            return *this;
        }

        auto set_increment_callback(increment_callback_type callback) -> void
        {
            increment_callback = callback;
        }

        auto set_decrement_callback(decrement_callback_type callback) -> void
        {
            decrement_callback = callback;
        }

    private:
        std::size_t value;

        increment_callback_type increment_callback = [] {};
        decrement_callback_type decrement_callback = [] {};

        friend auto operator- <IteratorCategory>(const iterator_mock<IteratorCategory>&,
            const iterator_mock<IteratorCategory>&) -> std::size_t;
        friend auto operator== <IteratorCategory>(const iterator_mock<IteratorCategory>&,
            const iterator_mock<IteratorCategory>&) -> bool;
        friend auto operator!= <IteratorCategory>(const iterator_mock<IteratorCategory>&,
            const iterator_mock<IteratorCategory>&) -> bool;

    };

    template<typename IteratorCategory>
    auto operator-(const iterator_mock<IteratorCategory>& left,
        const iterator_mock<IteratorCategory>& right) -> std::size_t
    {
        return left.value - right.value;
    }

    template<typename IteratorCategory>
    auto operator==(const iterator_mock<IteratorCategory>& left,
        const iterator_mock<IteratorCategory>& right) -> bool
    {
        return left.value == right.value;
    }

    template<typename IteratorCategory>
    auto operator!=(const iterator_mock<IteratorCategory>& left,
        const iterator_mock<IteratorCategory>& right) -> bool
    {
        return left.value != right.value;
    }

    using input_iterator_mock = iterator_mock<cpputil::input_iterator_tag>;
    using random_access_iterator_mock = iterator_mock<cpputil::random_access_iterator_tag>;
}

#endif // CPPUTIL_ITERATOR_MOCKS
