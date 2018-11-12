#ifndef CPPUTIL_FOR_EACH_HPP
#define CPPUTIL_FOR_EACH_HPP

namespace cpputil
{
    template<typename InputIterator, typename Function>
    constexpr auto for_each(InputIterator first, InputIterator last, Function func)
        -> Function
    {
        for (; first < last; ++first)
        {
            func(*first);
        }

        return func;
    }

    template<typename InputIterator, typename T, typename Function>
    constexpr auto for_each_n(InputIterator first, T n, Function func)
        -> Function
    {
        for (T i = 0; i < n; ++first, static_cast<void>(++i))
        {
            func(*first);
        }

        return func;
    }
}

#endif // CPPUTIL_FOR_EACH_HPP
