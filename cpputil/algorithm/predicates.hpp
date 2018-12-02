#ifndef CPPUTIL_ALGORITHM_PREDICATES_HPP
#define CPPUTIL_ALGORITHM_PREDICATES_HPP

namespace cpputil
{

template<typename T>
struct iter_eq_to_val
{
    constexpr explicit iter_eq_to_val(T& value)
        : wrapped_val(value)
    {}

    template<typename Iterator>
    constexpr auto operator()(Iterator it) const -> bool
    {
        return wrapped_val == *it;
    }

    T& wrapped_val;
};

template<typename T>
constexpr auto make_iter_eq_to_val(T& value) -> iter_eq_to_val<T>
{
    return iter_eq_to_val<T>(value);
}

struct iter_eq_to_iter
{
    template<typename Iterator1, typename Iterator2>
    constexpr auto operator()(Iterator1 iter1, Iterator2 iter2) const -> bool
    {
        return *iter1 == *iter2;
    }
};

constexpr auto make_iter_eq_to_iter() -> iter_eq_to_iter
{
    return iter_eq_to_iter();
}

template<typename Predicate>
struct iter_comp_to_iter
{
    constexpr explicit iter_comp_to_iter(Predicate pred)
        : wrapped_pred(pred)
    {}

    template<typename Iterator1, typename Iterator2>
    constexpr auto operator()(Iterator1 iter1, Iterator2 iter2) const -> bool
    {
        return wrapped_pred(*iter1, *iter2);
    }

    Predicate wrapped_pred;
};

template<typename Predicate>
constexpr auto make_iter_comp_to_iter(Predicate pred) -> iter_comp_to_iter<Predicate>
{
    return iter_comp_to_iter(pred);
}

template<typename Predicate>
struct iter_pred
{
    constexpr iter_pred(Predicate pred)
        : wrapped_pred(pred)
    {}

    template<typename Iterator>
    constexpr auto operator()(Iterator it) const -> bool
    {
        return wrapped_pred(*it);
    }

    Predicate wrapped_pred;
};

template<typename Predicate>
constexpr auto make_iter_pred(Predicate pred) -> iter_pred<Predicate>
{
    return iter_pred<Predicate>{ pred };
}

template<typename Predicate>
struct iter_neg_pred
{
    constexpr iter_neg_pred(Predicate pred)
        : wrapped_pred(pred)
    {}

    template<typename Iterator>
    constexpr auto operator()(Iterator it) const -> bool
    {
        return !wrapped_pred(*it);
    }

    Predicate wrapped_pred;
};

template<typename Predicate>
constexpr auto make_iter_neg_pred(Predicate pred) -> iter_neg_pred<Predicate>
{
    return iter_neg_pred<Predicate>(pred);
}

} // namespace cpputil

#endif // CPPUTIL_ALGORITHM_PREDICATES_HPP
