#pragma once

#include "iterator_tags.hpp"
#include "iterator_traits.hpp"

namespace cpputil
{
    namespace impl
    {
        template<typename InputIterator>
        auto distance_impl(InputIterator first, InputIterator last, input_iterator_tag) ->
            typename iterator_traits<InputIterator>::difference_type
        {
            typename iterator_traits<InputIterator>::difference_type difference = 0;

            while (first != last)
            {
                ++difference;
                ++first;
            }

            return difference;
        }

        template<typename InputIterator>
        auto distance_impl(InputIterator first, InputIterator last, random_access_iterator_tag) ->
            typename iterator_traits<InputIterator>::difference_type
        {
            return last - first;
        }
    }

    template<typename InputIterator>
    auto distance(InputIterator first, InputIterator last) ->
        typename iterator_traits<InputIterator>::difference_type
    {
        return impl::distance_impl(first, last, iterator_category_t<InputIterator>{});
    }
}
