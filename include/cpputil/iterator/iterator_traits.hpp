#pragma once

#include "..\traits\traits.hpp"
#include <iterator> // for iterator tags

namespace cpputil
{
    namespace impl
    {

    template<typename Iterator, typename = traits::void_t<>>
    struct iterator_traits_impl {
        using type = void;
    };

    template<typename Iterator>
    struct iterator_traits_impl<Iterator, traits::void_t<
        typename Iterator::iterator_category,
        typename Iterator::value_type,
        typename Iterator::difference_type,
        typename Iterator::pointer,
        typename Iterator::reference>>
    {
        using iterator_category = typename Iterator::iterator_category;
        using value_type = typename Iterator::value_type;
        using difference_type = typename Iterator::difference_type;
        using pointer = typename Iterator::pointer;
        using reference = typename Iterator::reference;
    };

    } // impl

template<typename Iterator>
struct iterator_traits :
    impl::iterator_traits_impl<Iterator> {};

template<typename T>
struct iterator_traits<T*>
{
    using iterator_category = std::random_access_iterator_tag;
    using value_type = traits::remove_const_t<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
};

template<typename T>
struct iterator_traits<const T*>
{
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;
};

} // cpputil
