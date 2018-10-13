#pragma once

namespace test
{
    struct writable_to_stream {};
    struct non_writable_to_stream {};

    std::istream& operator<<(std::ostream& is, const writable_to_stream&);
}