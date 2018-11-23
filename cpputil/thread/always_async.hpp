#ifndef CPPUTIL_ALWAYS_ASYNC_HPP
#define CPPUTIL_ALWAYS_ASYNC_HPP

#include <forward.hpp>
#include <future>

namespace cpputil
{

template<typename Func, typename... Args>
auto always_async(Func&& func, Args&&... args)
{
    return std::async(std::launch::async,
        cpputil::forward<Func>(func), cpputil::forward<Args>(args)...);
}

}

#endif // CPPUTIL_ALWAYS_ASYNC_HPP
