#pragma once

#include "max_element.hpp"

#include <initializer_list>

namespace cpputil
{

template<typename T>
constexpr const T& max(const T& x, const T& y)
{
    return (y < x) ? x : y;
}

template<typename T, typename Comp>
constexpr const T& max(const T& x, const T& y, Comp comp)
{
    return comp(y, x) ? x : y;
}

template<typename T>
constexpr const T& max(std::initializer_list<T> list)
{
    return *cpputil::max_element(list.begin(), list.end());
}

template<typename T, typename Comp>
constexpr const T& max(std::initializer_list<T> list, Comp comp)
{
    return *cpputil::max_element(list.begin(), list.end(), comp);
}

} // namespace cpputil
