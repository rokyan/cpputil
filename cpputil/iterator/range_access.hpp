#ifndef CPPUTIL_BEGIN_HPP
#define CPPUTIL_BEGIN_HPP

#include <cstddef>
#include <iterator>

namespace cpputil
{

template<typename Container>
constexpr auto begin(Container& c) -> decltype(c.begin())
{
    return c.begin();
}

template<typename Container>
constexpr auto begin(const Container& c) -> decltype(c.begin())
{
    return c.begin();
}

template<typename T, std::size_t N>
constexpr auto begin(T(&arr)[N]) noexcept -> T*
{
    return arr;
}

template<typename Container>
constexpr auto cbegin(const Container& c) noexcept(noexcept(cpputil::begin(c)))
{
    return cpputil::begin(c);
}

template<typename Container>
constexpr auto end(Container& c) -> decltype(c.end())
{
    return c.end();
}

template<typename Container>
constexpr auto end(const Container& c) -> decltype(c.end())
{
    return c.end();
}

template<typename T, std::size_t N>
constexpr auto end(T(&arr)[N]) noexcept -> T*
{
    return arr + N;
}

template<typename Container>
constexpr auto cend(const Container& c) noexcept(noexcept(cpputil::end(c)))
{
    return cpputil::end(c);
}

template<typename Container>
constexpr auto rbegin(Container& c) -> decltype(c.rbegin())
{
    return c.rbegin();
}

template<typename Container>
constexpr auto rbegin(const Container& c) -> decltype(c.rbegin())
{
    return c.rbegin();
}

template<typename T, std::size_t N>
constexpr auto rbegin(T(&arr)[N]) noexcept -> std::reverse_iterator<T*>
{
    return std::reverse_iterator<T*>(arr + N);
}

template<typename Container>
constexpr auto crbegin(const Container& c) noexcept(noexcept(cpputil::rbegin(c)))
{
    return cpputil::rbegin(c);
}

template<typename Container>
constexpr auto rend(Container& c) -> decltype(c.rend())
{
    return c.rend();
}

template<typename Container>
constexpr auto rend(const Container& c) -> decltype(c.rend())
{
    return c.rend();
}

template<typename T, std::size_t N>
constexpr auto rend(T(&arr)[N]) noexcept -> std::reverse_iterator<T*>
{
    return std::reverse_iterator<T*>(arr);
}

template<typename Container>
constexpr auto crend(const Container& c) noexcept(noexcept(cpputil::rend(c)))
{
    return cpputil::rend(c);
}

} // namespace cpputil

#endif // CPPUTIL_BEGIN_HPP
