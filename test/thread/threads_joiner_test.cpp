#include <gtest.hpp>
#include <thread.hpp>
#include <vector>
#include <thread>

namespace test
{

TEST(ThreadsJoinerTest, TestThreadsAreJoined)
{
    std::vector<std::thread> threads;

    for (unsigned int thread_idx = 0; thread_idx < 4u; thread_idx++)
    {
        threads.emplace_back([] { using namespace std::chrono_literals; std::this_thread::sleep_for(100ms); });
    }

    {
        cpputil::threads_joiner joiner(threads);
    }

    for (std::thread& thread : threads)
    {
        ASSERT_FALSE(thread.joinable());
    }
}

}