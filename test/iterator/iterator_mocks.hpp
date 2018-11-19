#ifndef CPPUTIL_ITERATOR_MOCKS_H
#define CPPUTIL_ITERATOR_MOCKS_H

#include <iterator_tags.hpp>

namespace test
{

template<typename>
class iterator_mock;

template<typename IteratorCategory>
auto operator-(const iterator_mock<IteratorCategory>&, const iterator_mock<IteratorCategory>&) -> int;
template<typename IteratorCategory>
auto operator==(const iterator_mock<IteratorCategory>&, const iterator_mock<IteratorCategory>&) -> bool;
template<typename IteratorCategory>
auto operator!=(const iterator_mock<IteratorCategory>&, const iterator_mock<IteratorCategory>&) -> bool;

template<typename IteratorCategory>
class iterator_mock
{
public:
    // value_type, pointer and reference actual values are insufficient for tests.
    using iterator_category = IteratorCategory;
    using difference_type = int;
    using value_type = void;
    using pointer = void;
    using reference = void;

private:
    using increment_callback_type = std::function<void()>;
    using decrement_callback_type = std::function<void()>;

public:
    iterator_mock(int value = 0)
        : value{ value }
    {}

    auto operator++() -> iterator_mock&
    {
        ++value;
        increment_callback();
        return *this;
    }

    auto operator--() -> iterator_mock&
    {
        --value;
        decrement_callback();
        return *this;
    }

    auto operator+=(int n) -> iterator_mock&
    {
        value += n;
        increment_callback();
        return *this;
    }

    auto operator-=(int n) -> iterator_mock&
    {
        value -= n;
        decrement_callback();
        return *this;
    }

    [[nodiscard]] auto get_value() const noexcept -> int
    {
        return value;
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
    int value;

    increment_callback_type increment_callback = [] {};
    decrement_callback_type decrement_callback = [] {};

    friend auto operator-<IteratorCategory>(const iterator_mock<IteratorCategory>&,
        const iterator_mock<IteratorCategory>&) -> int;
    friend auto operator==<IteratorCategory>(const iterator_mock<IteratorCategory>&,
        const iterator_mock<IteratorCategory>&) -> bool;
    friend auto operator!=<IteratorCategory>(const iterator_mock<IteratorCategory>&,
        const iterator_mock<IteratorCategory>&) -> bool;

};

template<typename IteratorCategory>
auto operator-(const iterator_mock<IteratorCategory>& left, const iterator_mock<IteratorCategory>& right) -> int
{
    return left.value - right.value;
}

template<typename IteratorCategory>
auto operator==(const iterator_mock<IteratorCategory>& left, const iterator_mock<IteratorCategory>& right) -> bool
{
    return left.value == right.value;
}

template<typename IteratorCategory>
auto operator!=(const iterator_mock<IteratorCategory>& left, const iterator_mock<IteratorCategory>& right) -> bool
{
    return left.value != right.value;
}

using input_iterator_mock =
    iterator_mock<cpputil::input_iterator_tag>;
using output_iterator_mock =
    iterator_mock<cpputil::output_iterator_tag>;
using forward_iterator_mock =
    iterator_mock<cpputil::forward_iterator_tag>;
using bidirectional_iterator_mock =
    iterator_mock<cpputil::bidirectional_iterator_tag>;
using random_access_iterator_mock =
    iterator_mock<cpputil::random_access_iterator_tag>;

} // namespace test

#endif // CPPUTIL_ITERATOR_MOCKS_H
