#include <gtest.hpp>
#include <utility.hpp>
#include <traits.hpp>

namespace test
{

TEST(IntegerSequenceTest, TestIntegerSequence)
{
    using integer_seq_0 = cpputil::make_integer_sequence<int, 0>;
    EXPECT_TRUE((traits::is_same_v<integer_seq_0, cpputil::integer_sequence<int>>));
    EXPECT_EQ(integer_seq_0::size(), 0);

    using integer_seq_1 = cpputil::make_integer_sequence<int, 1>;
    EXPECT_TRUE((traits::is_same_v<integer_seq_1, cpputil::integer_sequence<int, 0>>));
    EXPECT_EQ(integer_seq_1::size(), 1);

    using integer_seq_2 = cpputil::make_integer_sequence<int, 2>;
    EXPECT_TRUE((traits::is_same_v<integer_seq_2, cpputil::integer_sequence<int, 0, 1>>));
    EXPECT_EQ(integer_seq_2::size(), 2);

    using integer_seq_3 = cpputil::make_integer_sequence<int, 3>;
    EXPECT_TRUE((traits::is_same_v<integer_seq_3, cpputil::integer_sequence<int, 0, 1, 2>>));
    EXPECT_EQ(integer_seq_3::size(), 3);

    using integer_seq_4 = cpputil::make_integer_sequence<int, 4>;
    EXPECT_TRUE((traits::is_same_v<integer_seq_4, cpputil::integer_sequence<int, 0, 1, 2, 3>>));
    EXPECT_EQ(integer_seq_4::size(), 4);
}

TEST(IntegerSequenceTest, TestIndexSequence)
{
    using index_seq_0 = cpputil::make_index_sequence<0>;
    EXPECT_TRUE((traits::is_same_v<index_seq_0, cpputil::index_sequence<>>));
    EXPECT_EQ(index_seq_0::size(), 0);

    using index_seq_1 = cpputil::make_index_sequence<1>;
    EXPECT_TRUE((traits::is_same_v<index_seq_1, cpputil::index_sequence<0>>));
    EXPECT_EQ(index_seq_1::size(), 1);

    using index_seq_2 = cpputil::make_index_sequence<2>;
    EXPECT_TRUE((traits::is_same_v<index_seq_2, cpputil::index_sequence<0, 1>>));
    EXPECT_EQ(index_seq_2::size(), 2);

    using index_seq_3 = cpputil::make_index_sequence<3>;
    EXPECT_TRUE((traits::is_same_v<index_seq_3, cpputil::index_sequence<0, 1, 2>>));
    EXPECT_EQ(index_seq_3::size(), 3);

    using index_seq_4 = cpputil::make_index_sequence<4>;
    EXPECT_TRUE((traits::is_same_v<index_seq_4, cpputil::index_sequence<0, 1, 2, 3>>));
    EXPECT_EQ(index_seq_4::size(), 4);
}

TEST(IntegerSequenceTest, TestIndexSequenceFor)
{
    using index_seq = cpputil::index_sequence_for<T0, T1, T2, T3>;

    EXPECT_TRUE((traits::is_same_v<index_seq, cpputil::index_sequence<0, 1, 2, 3>>));
    EXPECT_EQ(index_seq::size(), 4);
}

} // namespace test