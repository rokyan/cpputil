#pragma once

#include <vector>
#include <thread>

namespace cpputil
{

class threads_joiner
{
public:
    threads_joiner(std::vector<std::thread>& threads)
        : threads(threads)
    {}

    threads_joiner(const threads_joiner&) = delete;
    threads_joiner& operator=(const threads_joiner&) = delete;

    ~threads_joiner()
    {
        for (std::thread& thread : threads)
        {
            if (thread.joinable())
            {
                thread.join();
            }
        }
    }

private:
    std::vector<std::thread>& threads;
};

} // namespace cpputil