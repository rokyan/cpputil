#include <gtest.hpp>
#include <scoped_thread.hpp>
#include <move.hpp>
#include <type_traits>

namespace test
{
    using cpputil::scoped_thread;

    TEST(ScopedThreadTest, TestGeneralClassProperties)
    {
        EXPECT_TRUE((std::is_constructible_v<scoped_thread, std::thread>)) <<
            "scoped_thread is expected to be constructible with an rvalue argument of type std::thread";

        EXPECT_TRUE(std::is_move_constructible_v<scoped_thread>) <<
            "scoped_thread is expected to be move-constructible";
        EXPECT_TRUE(std::is_move_assignable_v<scoped_thread>) <<
            "scoped_thread is expected to be move-assignable";

        EXPECT_FALSE(std::is_copy_constructible_v<scoped_thread>) <<
            "scoped_thread is expected not to be copy-constructible";
        EXPECT_FALSE(std::is_copy_assignable_v<scoped_thread>) <<
            "scoped_thread is expected not to be copy-assignable";
    }

    TEST(ScopedThreadTest, TestThrowingConstructor)
    {
        EXPECT_NO_THROW({
            scoped_thread sc_thread(std::thread{ [] {} });
        });

        EXPECT_THROW({
            scoped_thread sc_thread(std::thread{});
        }, std::logic_error);
    }
}