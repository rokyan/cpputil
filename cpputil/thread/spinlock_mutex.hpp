#ifndef CPPUTIL_THREAD_SPINLOCK_MUTEX_HPP
#define CPPUTIL_THREAD_SPINLOCK_MUTEX_HPP

#include <atomic>

namespace cpputil
{

class spinlock_mutex
{
public:
    spinlock_mutex() = default;

    spinlock_mutex(const spinlock_mutex&) = delete;
    spinlock_mutex& operator=(const spinlock_mutex&) = delete;

    auto lock() -> void
    {
        while (flag.test_and_set(std::memory_order_acquire));
    }

    auto unlock() -> void
    {
        flag.clear();
    }

private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
};

} // namespace cpputil

#endif // CPPUTIL_THREAD_SPINLOCK_MUTEX_HPP
