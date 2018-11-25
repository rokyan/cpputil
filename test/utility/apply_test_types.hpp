#ifndef CPPUTIL_APPLY_TEST_TYPES_HPP
#define CPPUTIL_APPLY_TEST_TYPES_HPP

namespace test
{

struct mem_pointer_testable
{
    int mem_fun(int x) const { return x; }
    int mem_obj = 1;
};

struct ref_qualifiers_testable
{
    int operator()(int x) const & { return x; }
    int operator()(int x) const && { return -x; }
};

}

#endif // CPPUTIL_APPLY_TEST_TYPES_HPP

