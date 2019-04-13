#include <gtest.hpp>
#include <memory.hpp>
#include <traits.hpp>

namespace test
{

struct test_entity
{
    void* operator&() const noexcept { return nullptr; }
};

TEST(AddressOfTest, TestAddressOf)
{
    EXPECT_SAME_TYPES(decltype(&cpputil::declval<test_entity&>()), void*);
    EXPECT_SAME_TYPES(decltype(cpputil::addressof(cpputil::declval<test_entity&>())), test_entity*);
}

} // namespace test