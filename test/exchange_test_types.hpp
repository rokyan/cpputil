#pragma once

namespace test
{
    template<typename T>
    struct move_only
    {
        move_only(move_only&&) = default;
        move_only& operator=(move_only&&) = default;

        T data;
    };

    template<typename T>
    struct convertible_to
    {
        convertible_to& operator=(T&& other_data)
        {
            data = cpputil::move(other_data);
            return *this;
        }

        operator T() const { return data; }

        T data;
    };
}