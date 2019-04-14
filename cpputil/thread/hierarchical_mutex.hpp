#pragma once

#include <mutex>

namespace cpputil
{

class hierarchical_mutex
{
public:
    explicit hierarchical_mutex(std::size_t hierarchy);

    hierarchical_mutex(const hierarchical_mutex&) = delete;
    hierarchical_mutex& operator=(const hierarchical_mutex&) = delete;

    void lock();
    void unlock();
    bool try_lock();

private:
    void check_violation() const;
    void update_hierarchy();

private:
    std::mutex internal_mutex;

    std::size_t hierarchy;
    std::size_t prev_hierarchy;

    static thread_local std::size_t thread_hierarchy;
};

} // namespace cpputil