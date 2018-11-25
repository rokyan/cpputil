#ifndef CPPUTIL_MOVE_TEST_TYPES_HPP
#define CPPUTIL_MOVE_TEST_TYPES_HPP

// TODO: remove <type_traits> inclusion and use custom traits
#include <type_traits>

namespace test
{

struct movable_noexcept_non_copyable
{
    movable_noexcept_non_copyable(movable_noexcept_non_copyable&&) = delete;
    movable_noexcept_non_copyable(const movable_noexcept_non_copyable&) = default;
};

static_assert(!std::is_move_constructible_v<movable_noexcept_non_copyable>);
static_assert(!std::is_nothrow_move_constructible_v<movable_noexcept_non_copyable>);
static_assert(std::is_copy_constructible_v<movable_noexcept_non_copyable>);
static_assert(std::is_nothrow_copy_constructible_v<movable_noexcept_non_copyable>);

struct movable_non_copyable
{
    movable_non_copyable(movable_non_copyable&&) {};
    movable_non_copyable(const movable_non_copyable&) = delete;
};

static_assert(std::is_move_constructible_v<movable_non_copyable>);
static_assert(!std::is_nothrow_move_constructible_v<movable_non_copyable>);
static_assert(!std::is_copy_constructible_v<movable_non_copyable>);
static_assert(!std::is_nothrow_copy_constructible_v<movable_non_copyable>);

struct copyable_noexcept_non_movable
{
    copyable_noexcept_non_movable(copyable_noexcept_non_movable&&) = delete;
    copyable_noexcept_non_movable(const copyable_noexcept_non_movable&) = default;
};

static_assert(!std::is_move_constructible_v<copyable_noexcept_non_movable>);
static_assert(!std::is_nothrow_move_constructible_v<copyable_noexcept_non_movable>);
static_assert(std::is_copy_constructible_v<copyable_noexcept_non_movable>);
static_assert(std::is_nothrow_copy_constructible_v<copyable_noexcept_non_movable>);

struct copyable_non_movable
{
    copyable_non_movable(copyable_non_movable&&) = delete;
    copyable_non_movable(const copyable_non_movable&) {};
};

static_assert(!std::is_move_constructible_v<copyable_non_movable>);
static_assert(!std::is_nothrow_move_constructible_v<copyable_non_movable>);
static_assert(std::is_copy_constructible_v<copyable_non_movable>);
static_assert(!std::is_nothrow_copy_constructible_v<copyable_non_movable>);

struct movable_noexcept_copyable_noexcept
{
    movable_noexcept_copyable_noexcept(movable_noexcept_copyable_noexcept&&) = default;
    movable_noexcept_copyable_noexcept(const movable_noexcept_copyable_noexcept&) = default;
};

static_assert(std::is_move_constructible_v<movable_noexcept_copyable_noexcept>);
static_assert(std::is_nothrow_move_constructible_v<movable_noexcept_copyable_noexcept>);
static_assert(std::is_copy_constructible_v<movable_noexcept_copyable_noexcept>);
static_assert(std::is_nothrow_copy_constructible_v<movable_noexcept_copyable_noexcept>);

struct movable_copyable
{
    movable_copyable(movable_copyable&&) {};
    movable_copyable(const movable_copyable&) {};
};

static_assert(std::is_move_constructible_v<movable_copyable>);
static_assert(!std::is_nothrow_move_constructible_v<movable_copyable>);
static_assert(std::is_copy_constructible_v<movable_copyable>);
static_assert(!std::is_nothrow_copy_constructible_v<movable_copyable>);

} // namespace test

#endif // CPPUTIL_MOVE_TEST_TYPES_HPP
