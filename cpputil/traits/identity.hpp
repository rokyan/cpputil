#pragma once

namespace cpputil
{

template<typename T>
struct identity
{
    using type = T;
};

template<typename T>
using identity_t = typename identity<T>::type;

} // namespace cpputil
