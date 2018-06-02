#pragma once

#include <type_traits>

namespace cpputil
{
    template<typename T>
    std::add_rvalue_reference_t<T> declval() noexcept;
}