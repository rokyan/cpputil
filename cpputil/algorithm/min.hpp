#pragma once

#include "min_element.hpp"

#include <initializer_list>

namespace cpputil
{

template<typename T>
constexpr const T& min(const T& x, const T& y)
{
    return (x < y) ? x : y;
}

template<typename T, typename Comp>
constexpr const T& min(const T& x, const T& y, Comp comp)
{
    return comp(x, y) ? x : y;
}

template<typename T>
constexpr const T& min(std::initializer_list<T> list)
{
    return *cpputil::min_element(list.begin(), list.end());
}

template<typename T, typename Comp>
constexpr const T& min(std::initializer_list<T> list, Comp comp)
{
    return *cpputil::min_element(list.begin(), list.end(), comp);
}

} // namespace cpputil
