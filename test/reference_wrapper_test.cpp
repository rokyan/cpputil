#include <gtest\gtest.h>
#include <reference_wrapper.h>
#include <type_traits>

namespace test {

    // Setup typed tests

    template<typename T>
    class reference_wrapper_typed_test : public testing::Test {};

    TYPED_TEST_CASE(reference_wrapper_typed_test, testing::Types<int>);

    // Tests

    TYPED_TEST(reference_wrapper_typed_test, test_type) {
        EXPECT_TRUE((std::is_same_v<cpputil::reference_wrapper<TypeParam>::type, TypeParam>));
    }

    TYPED_TEST(reference_wrapper_typed_test, test_constructors) {
        EXPECT_TRUE((std::is_nothrow_constructible_v<cpputil::reference_wrapper<TypeParam>, TypeParam&>)) <<
            "Reference wrapper must be nothrow constructible from lvalue of type TypeParam";
        EXPECT_TRUE((!std::is_constructible_v<cpputil::reference_wrapper<TypeParam>, TypeParam>)) <<
            "Reference wrapper must not be constructible from rvalue of type TypeParam";
        EXPECT_TRUE((std::is_nothrow_copy_constructible_v<cpputil::reference_wrapper<TypeParam>>)) <<
            "Reference wrapper must be nothrow copy constructible";
        EXPECT_TRUE((std::is_trivially_copyable_v<cpputil::reference_wrapper<TypeParam>>)) <<
            "Reference wrapper must be trivially copyable";

        TypeParam referenced{};
        cpputil::reference_wrapper<TypeParam> rw1(referenced);
        cpputil::reference_wrapper<TypeParam> rw2(rw1);

        EXPECT_EQ(&rw1.get(), std::addressof(referenced));
        EXPECT_EQ(&rw2.get(), std::addressof(referenced));
    }

    TYPED_TEST(reference_wrapper_typed_test, test_copy_assignment_operator) {
        EXPECT_TRUE((std::is_nothrow_copy_assignable_v<cpputil::reference_wrapper<TypeParam>>)) <<
            "Reference wrapper must be nothrow copy assignable";

        TypeParam referenced1{};
        cpputil::reference_wrapper<TypeParam> rw1(referenced1);
        EXPECT_EQ(&rw1.get(), std::addressof(referenced1));

        TypeParam referenced2{};
        cpputil::reference_wrapper<TypeParam> rw2(referenced2);
        EXPECT_EQ(&rw2.get(), std::addressof(referenced2));

        rw1 = rw2;
        EXPECT_EQ(&rw1.get(), std::addressof(referenced2));
    }

    TYPED_TEST(reference_wrapper_typed_test, test_conversion_operator) {
        TypeParam referenced{};
        cpputil::reference_wrapper<TypeParam> rw(referenced);

        EXPECT_EQ(static_cast<TypeParam>(rw), referenced);
    }

    TYPED_TEST(reference_wrapper_typed_test, test_get) {
        TypeParam referenced{};
        cpputil::reference_wrapper<TypeParam> rw(referenced);

        EXPECT_EQ(rw.get(), referenced);
    }

    TEST(reference_wrapper_test, test_function_call_operator) {
        auto callable = [](int arg) { return arg; };
        using rw_type = cpputil::reference_wrapper<decltype(callable)>;
        rw_type rw(callable);

        EXPECT_TRUE((std::is_invocable_v<rw_type, int>));
        EXPECT_EQ(rw(0), 0);
    }

    TYPED_TEST(reference_wrapper_typed_test, test_ref) {
        TypeParam referenced{};
        auto rw = cpputil::ref(referenced);

        EXPECT_TRUE((std::is_same_v<decltype(rw), cpputil::reference_wrapper<TypeParam>>));
        EXPECT_EQ(&rw.get(), std::addressof(referenced));
    }

    TYPED_TEST(reference_wrapper_typed_test, test_cref) {
        const TypeParam referenced{};
        auto rw = cpputil::cref(referenced);

        EXPECT_TRUE((std::is_same_v<decltype(rw), cpputil::reference_wrapper<const TypeParam>>));
        EXPECT_EQ(&rw.get(), std::addressof(referenced));
    }
}