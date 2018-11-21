#ifndef CPPUTIL_IDENTITY_HPP
#define CPPUTIL_IDENTITY_HPP

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

#endif // CPPUTIL_IDENTITY_HPP
