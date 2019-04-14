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

void hierarchical_mutex::lock()
{
    check_violation();
    internal_mutex.lock();
    update_hierarchy();
}

void hierarchical_mutex::unlock()
{
    thread_hierarchy = prev_hierarchy;
    internal_mutex.unlock();
}

bool hierarchical_mutex::try_lock()
{
    check_violation();

    if (!internal_mutex.try_lock())
    {
        return false;
    }

    update_hierarchy();

    return true;
}

void hierarchical_mutex::check_violation() const
{
    if (hierarchy >= thread_hierarchy)
    {
        throw std::logic_error("hierarchy violation");
    }
}

void hierarchical_mutex::update_hierarchy()
{
    prev_hierarchy = thread_hierarchy;
    thread_hierarchy = hierarchy;
}

} // namespace cpputil
