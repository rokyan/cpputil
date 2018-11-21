#include "hierarchical_mutex.hpp"
#include <stdexcept>
#include <limits>

namespace cpputil
{

thread_local std::size_t hierarchical_mutex::thread_hierarchy = std::numeric_limits<std::size_t>::max();

hierarchical_mutex::hierarchical_mutex(std::size_t hierarchy)
    : hierarchy(hierarchy)
    , prev_hierarchy(0)
{}

auto hierarchical_mutex::lock() -> void
{
    check_violation();
    internal_mutex.lock();
    update_hierarchy();
}

auto hierarchical_mutex::unlock() -> void
{
    thread_hierarchy = prev_hierarchy;
    internal_mutex.unlock();
}

auto hierarchical_mutex::try_lock() -> bool
{
    check_violation();

    if (!internal_mutex.try_lock())
    {
        return false;
    }

    update_hierarchy();

    return true;
}

auto hierarchical_mutex::check_violation() const -> void
{
    if (hierarchy >= thread_hierarchy)
    {
        throw std::logic_error("hierarchy violation");
    }
}

auto hierarchical_mutex::update_hierarchy() -> void
{
    prev_hierarchy = thread_hierarchy;
    thread_hierarchy = hierarchy;
}

} // namespace cpputil
