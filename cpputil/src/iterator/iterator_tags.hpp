#ifndef CPPUTIL_ITERATOR_TAGS_HPP
#define CPPUTIL_ITERATOR_TAGS_HPP

#include <iterator>

namespace cpputil
{

using input_iterator_tag = std::input_iterator_tag;
using output_iterator_tag = std::output_iterator_tag;
using forward_iterator_tag = std::forward_iterator_tag;
using bidirectional_iterator_tag = std::bidirectional_iterator_tag;
using random_access_iterator_tag = std::random_access_iterator_tag;

} // namespace cpputil

#endif // CPPUTIL_ITERATOR_TAGS_HPP
