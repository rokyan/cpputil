#pragma once

#include <iostream>

namespace test
{
    struct readable_from_stream {};
    struct non_readable_from_stream {};

    std::istream& operator>>(std::istream& is, readable_from_stream&);
}