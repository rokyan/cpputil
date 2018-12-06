#include <gtest.hpp>
#include <thread.hpp>
#include <iterator.hpp>
#include <algorithm.hpp>
#include <thread>
#include <vector>

namespace test
{

TEST(SpinlockMutexTest, TestSpinlockMutex)
{
    constexpr auto threads_num = 8;
    constexpr auto iters_num = 64;

    auto counter = 0;

    cpputil::spinlock_mutex sp_mutex;

    auto payload = [=, &counter, &sp_mutex]() {
        for (auto iter = 0; iter < iters_num; ++iter)
        {
            sp_mutex.lock();
            ++counter;
            sp_mutex.unlock();
        }
    };

    std::vector<std::thread> threads;

    for (auto thread_id = 0; thread_id < threads_num; ++thread_id)
    {
        threads.emplace_back(payload);
    }

    cpputil::for_each(cpputil::begin(threads), cpputil::end(threads),
        [](auto& thread) { thread.join(); });

    EXPECT_EQ(counter, threads_num * iters_num);
}

} // namespace test
