#ifndef CPPUTIL_RANGE_MOCKS_HPP
#define CPPUTIL_RANGE_MOCKS_HPP

namespace test
{

template<typename T>
class range_mock
{
public:
#define DEFINE_ITERATOR(ITERATOR_NAME) \
    struct ITERATOR_NAME { \
        constexpr operator T() const { return value; } \
        T value; \
    };

    DEFINE_ITERATOR(iterator)
    DEFINE_ITERATOR(const_iterator)
    DEFINE_ITERATOR(reverse_iterator)
    DEFINE_ITERATOR(const_reverse_iterator)

public:
    range_mock(T first, T last)
        : first(first)
        , last(last)
    {}

    constexpr auto begin() noexcept -> iterator { return { first }; }
    constexpr auto begin() const noexcept -> const_iterator { return { first }; }
    constexpr auto cbegin() const noexcept -> const_iterator { return { first }; }

    constexpr auto end() noexcept -> iterator { return { last }; }
    constexpr auto end() const noexcept -> const_iterator { return { last }; }
    constexpr auto cend() const noexcept -> const_iterator { return { last }; }

    constexpr auto rbegin() noexcept -> reverse_iterator { return { last }; }
    constexpr auto rbegin() const noexcept -> const_reverse_iterator { return { last }; }
    constexpr auto crbegin() const noexcept -> const_reverse_iterator { return { last }; }

    constexpr auto rend() noexcept -> reverse_iterator { return { first }; }
    constexpr auto rend() const noexcept -> const_reverse_iterator { return { first }; }
    constexpr auto rcend() const noexcept -> const_reverse_iterator { return { first }; }

private:
    T first;
    T last;
};

using integer_range_mock = range_mock<int>;

} // namespace test

#endif // CPPUTIL_RANGE_MOCKS_HPP
