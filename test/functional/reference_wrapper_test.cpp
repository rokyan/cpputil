#include <gtest.hpp>
#include <functional.hpp>

namespace test
{

using test_types = make_test_types<int, double>;

DECLARE_TYPED_TEST_NAME(ReferenceWrapperTypedTest);
TYPED_TEST_CASE(ReferenceWrapperTypedTest, test_types);

using cpputil::reference_wrapper;

TYPED_TEST(ReferenceWrapperTypedTest, TestTypeAlias)
{
    EXPECT_SAME_TYPES(typename reference_wrapper<TypeParam>::type, TypeParam);
}

TYPED_TEST(ReferenceWrapperTypedTest, TestConstructors)
{
    EXPECT_TRUE((std::is_nothrow_constructible_v<reference_wrapper<TypeParam>, TypeParam&>)) <<
        "Reference wrapper must be nothrow constructible from lvalue of type TypeParam";
    EXPECT_TRUE((!std::is_constructible_v<reference_wrapper<TypeParam>, TypeParam>)) <<
        "Reference wrapper must not be constructible from rvalue of type TypeParam";
    EXPECT_TRUE((std::is_nothrow_copy_constructible_v<reference_wrapper<TypeParam>>)) <<
        "Reference wrapper must be nothrow copy constructible";
    EXPECT_TRUE((std::is_trivially_copyable_v<reference_wrapper<TypeParam>>)) <<
        "Reference wrapper must be trivially copyable";

    TypeParam referenced{};
    reference_wrapper<TypeParam> rw1(referenced);
    reference_wrapper<TypeParam> rw2(rw1);

    EXPECT_EQ(&rw1.get(), cpputil::addressof(referenced));
    EXPECT_EQ(&rw2.get(), cpputil::addressof(referenced));
}

TYPED_TEST(ReferenceWrapperTypedTest, TestCopyAssignmentOperator)
{
    EXPECT_TRUE((std::is_nothrow_copy_assignable_v<reference_wrapper<TypeParam>>)) <<
        "Reference wrapper must be nothrow copy assignable";

    TypeParam referenced1{};
    reference_wrapper<TypeParam> rw1(referenced1);
    EXPECT_EQ(&rw1.get(), cpputil::addressof(referenced1));

    TypeParam referenced2{};
    reference_wrapper<TypeParam> rw2(referenced2);
    EXPECT_EQ(&rw2.get(), cpputil::addressof(referenced2));

    rw1 = rw2;
    EXPECT_EQ(&rw1.get(), cpputil::addressof(referenced2));
}

TYPED_TEST(ReferenceWrapperTypedTest, TestConversionOperator)
{
    TypeParam referenced{};
    reference_wrapper<TypeParam> rw(referenced);

    EXPECT_EQ(static_cast<TypeParam>(rw), referenced);
}

TYPED_TEST(ReferenceWrapperTypedTest, TestGetMethod)
{
    TypeParam referenced{};
    reference_wrapper<TypeParam> rw(referenced);

    EXPECT_EQ(rw.get(), referenced);
}

TEST(ReferenceWrapperTest, TestFunctionCallOperator)
{
    auto callable = [](int arg) { return arg; };
    using rw_type = reference_wrapper<decltype(callable)>;
    rw_type rw(callable);

    EXPECT_TRUE((std::is_invocable_v<rw_type, int>));
    EXPECT_EQ(rw(0), 0);
}

TYPED_TEST(ReferenceWrapperTypedTest, TestRefFunction)
{
    TypeParam referenced{};
    auto rw = cpputil::ref(referenced);

    EXPECT_SAME_TYPES(decltype(rw), reference_wrapper<TypeParam>);
    EXPECT_EQ(&rw.get(), cpputil::addressof(referenced));
}

TYPED_TEST(ReferenceWrapperTypedTest, TestCRefFunction)
{
    const TypeParam referenced{};
    auto rw = cpputil::cref(referenced);

    EXPECT_SAME_TYPES(decltype(rw), reference_wrapper<const TypeParam>);
    EXPECT_EQ(&rw.get(), cpputil::addressof(referenced));
}

} // namespace test
