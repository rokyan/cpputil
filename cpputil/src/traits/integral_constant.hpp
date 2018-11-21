#ifndef CPPUTIL_INTERGRAL_CONSTANT_HPP
#define CPPUTIL_INTERGRAL_CONSTANT_HPP

namespace traits
{

template<typename T, T v>
struct integral_constant
{
    static constexpr T value = v;

    using value_type = T;
    using type = integral_constant<T, v>;

    constexpr operator value_type() const noexcept { return value; }
    constexpr T operator()() const noexcept { return value; }
};

template<bool B>
using bool_constant = integral_constant<bool, B>;

using false_type = bool_constant<false>;
using true_type = bool_constant<true>;

} // namespace traits

#endif // CPPUTIL_INTERGRAL_CONSTANT_HPP
