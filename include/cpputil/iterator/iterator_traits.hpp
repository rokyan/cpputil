#pragma once

#include "iterator_tags.hpp"
#include "..\traits\traits.hpp"

namespace cpputil
{
    namespace impl
    {
        template<typename Iterator, typename = traits::void_t<>>
        struct iterator_traits_impl {};

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
    }

    template<typename Iterator>
    struct iterator_traits :
        impl::iterator_traits_impl<Iterator> {};

    template<typename T>
    struct iterator_traits<T*>
    {
        using iterator_category = random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
    };

    template<typename T>
    struct iterator_traits<const T*>
    {
        using iterator_category = random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;
    };

    template<typename T>
    using iterator_category_t = typename iterator_traits<T>::iterator_category;

    template<typename T>
    using value_type_t = typename iterator_traits<T>::value_type;

    template<typename T>
    using difference_type_t = typename iterator_traits<T>::difference_type;

    template<typename T>
    using pointer_t = typename iterator_traits<T>::pointer;

    template<typename T>
    using reference_t = typename iterator_traits<T>::reference;
}
