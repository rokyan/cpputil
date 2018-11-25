#ifndef CPPUTIL_FOREACH_ARGUMENT_TEST_TYPES_HPP
#define CPPUTIL_FOREACH_ARGUMENT_TEST_TYPES_HPP

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

} // namespace cpputil

#endif // CPPUTIL_FOREACH_ARGUMENT_TEST_TYPES_HPP