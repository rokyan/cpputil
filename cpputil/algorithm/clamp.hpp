#pragma once

namespace cpputil
{

template<typename T>
constexpr const T& clamp(const T& value, const T& lo, const T& hi)
{
    if (value < lo)
    {
        return lo;
    }

    if (hi < value)
    {
        return hi;
    }

    return value;
}

template<typename T, typename Comp>
constexpr const T& clamp(const T& value, const T& lo, const T& hi, Comp comp)
{
    if (comp(value, lo))
    {
        return lo;
    }

    if (comp(hi, value))
    {
        return hi;
    }

    return value;
}

} // namespace cpputil