#ifndef CPPUTIL_HIERARCHICAL_MUTEX_HPP
#define CPPUTIL_HIERARCHICAL_MUTEX_HPP

#include <mutex>

namespace cpputil
{

class hierarchical_mutex
{
public:
    explicit hierarchical_mutex(std::size_t hierarchy);

    hierarchical_mutex(const hierarchical_mutex&) = delete;
    hierarchical_mutex& operator=(const hierarchical_mutex&) = delete;

    auto lock() -> void;
    auto unlock() -> void;
    auto try_lock() -> bool;

private:
    auto check_violation() const -> void;
    auto update_hierarchy() -> void;

private:
    std::mutex internal_mutex;

    std::size_t hierarchy;
    std::size_t prev_hierarchy;

    static thread_local std::size_t thread_hierarchy;
};

} // namespace cpputil

#endif // CPPUTIL_HIERARCHICAL_MUTEX_HPP
