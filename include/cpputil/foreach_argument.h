#pragma once

#include <forward.h>

namespace cpputil
{

    template<typename Func, typename... Args>
    void foreach_argument(Func&& f, Args&&... args)
    {
        (static_cast<void>(cpputil::forward<Func>(f)(cpputil::forward<Args>(args))), ...);
    }
}