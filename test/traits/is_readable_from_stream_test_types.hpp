#ifndef CPPUTIL_IS_READABLE_FROM_STREAM_TEST_TYPES_HPP
#define CPPUTIL_IS_READABLE_FROM_STREAM_TEST_TYPES_HPP

#include <iosfwd>

namespace test
{

struct readable_from_stream {};
struct non_readable_from_stream {};

std::istream& operator>>(std::istream& is, readable_from_stream&);

} // namespace test

#endif // CPPUTIL_IS_READABLE_FROM_STREAM_TEST_TYPES_HPP
