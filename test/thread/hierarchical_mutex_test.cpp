#include <gtest.hpp>
#include <thread.hpp>
#include <type_traits>

namespace test
{

using cpputil::hierarchical_mutex;

TEST(HierarchicalMutexTest, TestGeneralClassProperties)
{
    EXPECT_TRUE((std::is_constructible_v<hierarchical_mutex, std::size_t&>)) <<
        "hierarchical_mutex is expected to be constructible with an std::size_t argument";

    EXPECT_FALSE(std::is_copy_constructible_v<hierarchical_mutex>) <<
        "hierarchical_mutex is expected not to be copy-constructible";
    EXPECT_FALSE(std::is_copy_assignable_v<hierarchical_mutex>) <<
        "hierarchical_mutex is expected not to be copy-assignable";

    EXPECT_FALSE(std::is_move_constructible_v<hierarchical_mutex>) <<
        "hierarchical_mutex is expected not to be move-constructible";
    EXPECT_FALSE(std::is_move_assignable_v<hierarchical_mutex>) <<
        "hierarchical_mutex is expected not to be move-assignable";
}

TEST(HierarchicalMutexTest, TestLockCorrectOrder)
{
    hierarchical_mutex m_1{ 1 };
    hierarchical_mutex m_2{ 2 };

    EXPECT_NO_THROW(m_2.lock()) <<
        "Lock must not throw";
    EXPECT_NO_THROW(m_1.lock()) <<
        "Lock must not throw";
    EXPECT_NO_THROW(m_1.unlock()) <<
        "Unlock must not throw";
    EXPECT_NO_THROW(m_2.unlock()) <<
        "Unlock must not throw";
}

TEST(HierarchicalMutexTest, TestLockIncorrectOrder)
{
    hierarchical_mutex m_1{ 1 };
    hierarchical_mutex m_2{ 2 };

    EXPECT_NO_THROW(m_1.lock()) <<
        "Lock must not throw";
    EXPECT_THROW(m_2.lock(), std::logic_error) <<
        "Lock must throw because of hierarchy";
    EXPECT_NO_THROW(m_1.unlock()) <<
        "Unlock must not throw";
}

} // namespace test
