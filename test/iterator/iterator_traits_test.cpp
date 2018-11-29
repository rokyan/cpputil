#include <gtest.hpp>
#include <iterator.hpp>

namespace test
{
    // Test utilities.

    struct iterator_category_mock {};
    struct value_type_mock {};
    struct difference_type_mock {};
    struct pointer_mock {};
    struct reference_mock {};

    struct iterator_mock
    {
        using iterator_category = iterator_category_mock;
        using value_type = value_type_mock;
        using difference_type = difference_type_mock;
        using pointer = pointer_mock;
        using reference = reference_mock;
    };

    // Tests.

    TEST(IteratorTraitsTest, TestIteratorType)
    {
        using actual_iterator_category = cpputil::iterator_traits<iterator_mock>::iterator_category;
        EXPECT_SAME_TYPES(actual_iterator_category, iterator_category);

        using actual_value_type = cpputil::iterator_traits<iterator_mock>::value_type;
        EXPECT_SAME_TYPES(actual_value_type, value_type);

        using actual_difference_type = cpputil::iterator_traits<iterator_mock>::difference_type;
        EXPECT_SAME_TYPES(actual_difference_type, difference_type);

        using actual_pointer = cpputil::iterator_traits<iterator_mock>::pointer;
        EXPECT_SAME_TYPES(actual_pointer, pointer);

        using actual_reference = cpputil::iterator_traits<iterator_mock>::reference;
        EXPECT_SAME_TYPES(actual_reference, reference);
    }

    using test_types = make_test_types<T0*, const T0*, volatile T0*, const volatile T0*>;

    DECLARE_TYPED_TEST_NAME(IteratorTraitsTypedTest);
    TYPED_TEST_CASE(IteratorTraitsTypedTest, test_types);

    TYPED_TEST(IteratorTraitsTypedTest, TestPointerTypes)
    {
        using actual_iterator_category = typename cpputil::iterator_traits<TypeParam>::iterator_category;
        EXPECT_SAME_TYPES(actual_iterator_category, std::random_access_iterator_tag);

        using actual_value_type = typename cpputil::iterator_traits<TypeParam>::value_type;
        EXPECT_SAME_TYPES(actual_value_type, traits::remove_const_t<traits::remove_pointer_t<TypeParam>>);

        using actual_difference_type = typename cpputil::iterator_traits<TypeParam>::difference_type;
        EXPECT_SAME_TYPES(actual_difference_type, std::ptrdiff_t);

        using actual_pointer = typename cpputil::iterator_traits<TypeParam>::pointer;
        EXPECT_SAME_TYPES(actual_pointer, TypeParam);

        using actual_reference = typename cpputil::iterator_traits<TypeParam>::reference;
        EXPECT_SAME_TYPES(actual_reference, traits::add_lvalue_reference_t<traits::remove_pointer_t<TypeParam>>);
    }

    TEST(IteratorTraitsTest, TestHelperTraits)
    {
        EXPECT_SAME_TYPES(cpputil::iterator_traits<iterator_mock>::iterator_category,
            cpputil::iterator_category_t<iterator_mock>);

        EXPECT_SAME_TYPES(cpputil::iterator_traits<iterator_mock>::value_type,
            cpputil::value_type_t<iterator_mock>);

        EXPECT_SAME_TYPES(cpputil::iterator_traits<iterator_mock>::difference_type,
            cpputil::difference_type_t<iterator_mock>);

        EXPECT_SAME_TYPES(cpputil::iterator_traits<iterator_mock>::pointer,
            cpputil::pointer_t<iterator_mock>);

        EXPECT_SAME_TYPES(cpputil::iterator_traits<iterator_mock>::reference,
            cpputil::reference_t<iterator_mock>);
    }
}