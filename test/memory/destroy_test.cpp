#include <gtest.hpp>
#include <memory.hpp>

namespace test
{

class test_entity
{
public:
    ~test_entity()
    {
        destroyed++;
    }

    static void reset_destroyed() noexcept
    {
        destroyed = 0;
    }

    [[nodiscard]] static std::size_t get_destroyed() noexcept
    {
        return destroyed;
    }

private:
    static std::size_t destroyed;
};

std::size_t test_entity::destroyed = 0;

class DestroyTest : public testing::Test
{
public:
    virtual void SetUp() override
    {
        test_entity::reset_destroyed();
    }
};

TEST_F(DestroyTest, TestDestroyAt)
{
    const std::size_t objects_num = 1;

    alignas(test_entity) unsigned char raw_buffer[objects_num * sizeof(test_entity)];
    const test_entity* const ptr = new (raw_buffer) test_entity{};

    cpputil::destroy_at(ptr);

    EXPECT_EQ(test_entity::get_destroyed(), 1);
}

TEST_F(DestroyTest, TestDestroy)
{
    const std::size_t objects_num = 4;

    alignas(test_entity) unsigned char raw_buffer[objects_num * sizeof(test_entity)];

    for (std::size_t i = 0; i < objects_num; i++)
    {
        const std::size_t offset = i * sizeof(test_entity);
        static_cast<void>(new (raw_buffer + offset) test_entity{});
    }

    cpputil::destroy(reinterpret_cast<test_entity*>(raw_buffer),
        reinterpret_cast<test_entity*>(raw_buffer + objects_num * sizeof(test_entity)));

    EXPECT_EQ(test_entity::get_destroyed(), objects_num);
}

TEST_F(DestroyTest, TestDestroyN)
{
    const std::size_t objects_num = 4;

    alignas(test_entity) unsigned char raw_buffer[objects_num * sizeof(test_entity)];

    for (std::size_t i = 0; i < objects_num; i++)
    {
        const std::size_t offset = i * sizeof(test_entity);
        static_cast<void>(new (raw_buffer + offset) test_entity{});
    }

    cpputil::destroy_n(reinterpret_cast<test_entity*>(raw_buffer), objects_num);

    EXPECT_EQ(test_entity::get_destroyed(), objects_num);
}

} // namespace test