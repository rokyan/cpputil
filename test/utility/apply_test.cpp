#include <gtest.hpp>
#include <utility.hpp>
#include <apply_test_types.hpp>

namespace test
{

TEST(ApplyTest, TestApplyWithLambda)
{
    const auto unary_callable =[](int x) {
        return x * x;
    };
    EXPECT_EQ(cpputil::apply(unary_callable, std::make_tuple(2)), 4);

    const auto binary_callable = [](int x, int y) {
        return x * x + y * y;
    };
    EXPECT_EQ(cpputil::apply(binary_callable, std::make_tuple(2, 4)), 20);

    const auto ternary_callable = [](int x, int y, int z) {
        return x * x + y * y + z * z;
    };
    EXPECT_EQ(cpputil::apply(ternary_callable, std::make_tuple(2, 4, 8)), 84);
}

TEST(ApplyTest, TestApplyWithGenericLambda)
{
    const auto gen_sum = [](auto&&... es) {
        return (es + ...);
    };

    EXPECT_EQ(cpputil::apply(gen_sum, std::make_tuple(1, 2L, 3LL, 4.0f, 5.0)), 15.0);
}

TEST(ApplyTest, TestApplyWithMemberPointer)
{
    mem_pointer_testable t;

    const auto mem_obj_ptr = &mem_pointer_testable::mem_obj;
    const auto mem_fun_ptr = &mem_pointer_testable::mem_fun;

    EXPECT_EQ(cpputil::apply(mem_obj_ptr, std::make_tuple(t)), 1);
    EXPECT_EQ(cpputil::apply(mem_fun_ptr, std::make_tuple(t, 1)), 1);
}

TEST(ApplyTest, TestValueCategoryCorrectness)
{
    ref_qualifiers_testable t;

    EXPECT_EQ(cpputil::apply(t, std::make_tuple(1)), 1);
    EXPECT_EQ(cpputil::apply(cpputil::move(t), std::make_tuple(1)), -1);
}

} // namespace test