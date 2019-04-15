#pragma once

#include <thread>
#include <move.hpp>

namespace cpputil
{

class scoped_thread
{
public:
    scoped_thread(std::thread thread)
        : wrapped_thread(cpputil::move(thread))
    {
        if (!wrapped_thread.joinable())
        {
            throw std::logic_error("thread is not joinable");
        }
    }

    ~scoped_thread()
    {
        wrapped_thread.join();
    }

    scoped_thread(const scoped_thread&) = delete;
    scoped_thread& operator=(const scoped_thread&) = delete;

    scoped_thread(scoped_thread&&) = default;
    scoped_thread& operator=(scoped_thread&&) = default;

private:
    std::thread wrapped_thread;
};

} // namespace cpputil