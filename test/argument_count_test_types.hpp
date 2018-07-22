#include <types.hpp>

namespace test
{
    class some_class;

    namespace
    {
        auto lambda = [](T0, T1) {};
        auto mutable_lambda = [](T0, T1) mutable {};
    }

    using lambda_type = decltype(lambda);
    using mutable_lambda_type = decltype(mutable_lambda);
}