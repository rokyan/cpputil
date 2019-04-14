#pragma once

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

} // namespace cpputil