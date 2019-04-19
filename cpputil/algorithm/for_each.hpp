#pragma once

namespace cpputil
{

template<typename InputIterator, typename Function>
constexpr Function for_each(InputIterator first, InputIterator last, Function func)
{
    for (; first < last; ++first)
    {
        func(*first);
    }

    return func;
}

template<typename InputIterator, typename T, typename Function>
constexpr Function for_each_n(InputIterator first, T n, Function func)
{
    for (T i = 0; i < n; ++first, static_cast<void>(++i))
    {
        func(*first);
    }

    return func;
}

} // namespace cpputil