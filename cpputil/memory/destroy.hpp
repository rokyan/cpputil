#pragma once

#include "addressof.hpp"
#include <cstddef>

namespace cpputil
{

template<typename T>
void destroy_at(T* ptr)
{
    ptr->~T();
}

template<typename ForwardIt>
void destroy(ForwardIt first, ForwardIt last)
{
    for (; first != last; ++first)
    {
        cpputil::destroy_at(cpputil::addressof(*first));
    }
}

template<typename ForwardIt>
void destroy_n(ForwardIt first, std::size_t n)
{
    for (; n > 0; static_cast<void>(++first), n--)
    {
        cpputil::destroy_at(cpputil::addressof(*first));
    }
}

} // namespace cpputil
