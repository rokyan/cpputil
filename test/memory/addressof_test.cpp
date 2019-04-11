#include <gtest.hpp>
#include <memory.hpp>
#include <traits.hpp>

namespace test
{

struct Entity
{
    void* operator&() const noexcept { return nullptr; }
};

TEST(AddressOfTest, TestAddressOf)
{
    EXPECT_SAME_TYPES(decltype(&cpputil::declval<Entity&>()), void*);
    EXPECT_SAME_TYPES(decltype(cpputil::addressof(cpputil::declval<Entity&>())), Entity*);
}

} // namespace test