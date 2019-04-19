#pragma once

#include "minmax_element.hpp"

#include <initializer_list>
#include <utility>

namespace cpputil
{

template<typename T>
constexpr std::pair<const T&, const T&> minmax(const T& x, const T& y)
{
    using ret_type = std::pair<const T&, const T&>;
    return (x < y) ? ret_type(x, y) : ret_type(y, x);
}

template<typename T, typename Comp>
constexpr std::pair<const T&, const T&> minmax(const T& x, const T& y, Comp comp)
{
    using ret_type = std::pair<const T&, const T&>;
    return comp(x, y) ? ret_type(x, y) : ret_type(y, x);
}

template<typename T>
constexpr std::pair<T, T> minmax(std::initializer_list<T> list)
{
    const auto it_pr = cpputil::minmax_element(list.begin(), list.end());
    return std::make_pair(*it_pr.first, *it_pr.second);
}

template<typename T, typename Comp>
constexpr std::pair<T, T> minmax(std::initializer_list<T> list, Comp comp)
{
    const auto it_pr = cpputil::minmax_element(list.begin(), list.end(), comp);
    return std::make_pair(*it_pr.first, *it_pr.second);
}

} // namespace cpputil