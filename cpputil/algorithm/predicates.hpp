#pragma once

namespace cpputil
{

template<typename T>
struct iter_eq_to_val
{
    constexpr explicit iter_eq_to_val(T& value)
        : value(value)
    {}

    template<typename Iterator>
    constexpr bool operator()(Iterator it) const
    {
        return value == *it;
    }

    T& value;
};

template<typename T>
constexpr iter_eq_to_val<T> make_iter_eq_to_val(T& value)
{
    return iter_eq_to_val<T>(value);
}

struct iter_eq_to_iter
{
    template<typename Iterator1, typename Iterator2>
    constexpr bool operator()(Iterator1 iter1, Iterator2 iter2) const
    {
        return *iter1 == *iter2;
    }
};

constexpr iter_eq_to_iter make_iter_eq_to_iter()
{
    return iter_eq_to_iter();
}

struct iter_less_then_iter
{
    template<typename Iterator1, typename Iterator2>
    constexpr bool operator()(Iterator1 iter1, Iterator2 iter2) const
    {
        return *iter1 < *iter2;
    }
};

constexpr iter_less_then_iter make_iter_less_then_iter()
{
    return iter_less_then_iter();
}

template<typename Predicate>
struct iter_comp_to_iter
{
    constexpr explicit iter_comp_to_iter(Predicate pred)
        : pred(pred)
    {}

    template<typename Iterator1, typename Iterator2>
    constexpr bool operator()(Iterator1 iter1, Iterator2 iter2) const
    {
        return pred(*iter1, *iter2);
    }

    Predicate pred;
};

template<typename Predicate>
constexpr iter_comp_to_iter<Predicate> make_iter_comp_to_iter(Predicate pred)
{
    return iter_comp_to_iter(pred);
}

template<typename Predicate>
struct iter_pred
{
    constexpr iter_pred(Predicate pred)
        : pred(pred)
    {}

    template<typename Iterator>
    constexpr bool operator()(Iterator it) const
    {
        return pred(*it);
    }

    Predicate pred;
};

template<typename Predicate>
constexpr iter_pred<Predicate> make_iter_pred(Predicate pred)
{
    return iter_pred<Predicate>(pred);
}

template<typename Predicate>
struct iter_neg_pred
{
    constexpr iter_neg_pred(Predicate pred)
        : pred(pred)
    {}

    template<typename Iterator>
    constexpr bool operator()(Iterator it) const
    {
        return !pred(*it);
    }

    Predicate pred;
};

template<typename Predicate>
constexpr iter_neg_pred<Predicate> make_iter_neg_pred(Predicate pred)
{
    return iter_neg_pred<Predicate>(pred);
}

} // namespace cpputil
