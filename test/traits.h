#pragma once

#include <type_traits>

namespace test {

    // Determine lvalue/rvalue

    template<typename T>
    constexpr std::is_lvalue_reference<T&&> is_lvalue(T&&) {
        return {};
    }

    template<typename T>
    constexpr std::is_rvalue_reference<T&&> is_rvalue(T&&) {
        return {};
    }
}