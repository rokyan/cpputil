#ifndef CPPUTIL_IS_WRITABLE_TO_STREAM_TEST_TYPES_HPP
#define CPPUTIL_IS_WRITABLE_TO_STREAM_TEST_TYPES_HPP

#include <iosfwd>

namespace test
{

struct writable_to_stream {};
struct non_writable_to_stream {};

std::istream& operator<<(std::ostream& is, const writable_to_stream&);

} // namespace test

#endif // CPPUTIL_IS_WRITABLE_TO_STREAM_TEST_TYPES_HPP
