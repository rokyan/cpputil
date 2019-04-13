#include <gtest.hpp>
#include <memory.hpp>

namespace test
{

class entity
{
private:
    static std::size_t destroyed;

public:
    ~entity()
    {
        destroyed++;
    }

    void reset_destroyed() const noexcept
    {
        destroyed = 0;
    }

    [[nodiscard]] std::size_t get_destroyed() const noexcept
    {
        return destroyed;
    }
};

std::size_t entity::destroyed = 0;

TEST(DestroyTest, TestDestroyAt)
{
    constexpr std::size_t objects_num = 1;

    entity e;
    e.reset_destroyed();

    alignas(entity) unsigned char raw_buffer[objects_num * sizeof(entity)];
    const entity* const ptr = new (raw_buffer) entity{};

    cpputil::destroy_at(ptr);

    EXPECT_EQ(e.get_destroyed(), 1);
}

TEST(DestroyTest, TestDestroy)
{
    constexpr std::size_t objects_num = 4;

    entity e;
    e.reset_destroyed();

    alignas(entity) unsigned char raw_buffer[objects_num * sizeof(entity)];

    for (std::size_t i = 0; i < objects_num; i++)
    {
        const std::size_t offset = i * sizeof(entity);
        static_cast<void>(new (raw_buffer + offset) entity{});
    }

    cpputil::destroy(reinterpret_cast<entity*>(raw_buffer),
        reinterpret_cast<entity*>(raw_buffer + objects_num * sizeof(entity)));

    EXPECT_EQ(e.get_destroyed(), objects_num);
}

TEST(DestroyTest, TestDestroyN)
{
    constexpr std::size_t objects_num = 4;

    entity e;
    e.reset_destroyed();

    alignas(entity) unsigned char raw_buffer[objects_num * sizeof(entity)];

    for (std::size_t i = 0; i < objects_num; i++)
    {
        const std::size_t offset = i * sizeof(entity);
        static_cast<void>(new (raw_buffer + offset) entity{});
    }

    cpputil::destroy_n(reinterpret_cast<entity*>(raw_buffer), objects_num);

    EXPECT_EQ(e.get_destroyed(), objects_num);
}

} // namespace test