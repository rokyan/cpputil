#pragma once

#include <type_traits>

namespace cpputil
{
    template<typename T1, typename T2>
    struct pair
    {
        using first_type = T1;
        using second_type = T2;

        T1 first;
        T2 second;

        pair(const pair&) = default;
        pair(pair&&) = default;

        template<typename U1 = T1, typename U2 = T2,
            std::enable_if_t<std::conjunction_v<std::is_default_constructible<U1>, std::is_default_constructible<U2>>, int> = 0>
        constexpr pair() :
            first{},
            second{}
        {}
    };
}