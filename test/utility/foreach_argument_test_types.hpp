#pragma once

namespace test
{

template<typename T>
struct testable
{
    void operator()(T t) &
    {
        value += t;
    }

    void operator()(T t) &&
    {
        value -= t;
    }

    T value{};
};

} // namespace test
