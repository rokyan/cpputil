#pragma once

namespace traits
{
    template<typename T>
    struct identity
    {
        using type = T;
    };

    template<typename T>
    using identity_t = typename identity<T>::type;
}
