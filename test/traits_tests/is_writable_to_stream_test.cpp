#include <gtest.hpp>
#include <traits.hpp>
#include <is_writable_to_stream_test_types.hpp>

namespace test
{
    TEST(IsWritableToStreamTest, TestFundamentalTypes)
    {
        EXPECT_TRUE(traits::is_writable_to_stream_v<int>);
        EXPECT_TRUE(traits::is_writable_to_stream_v<int&>);
    }

    TEST(IsWritableToStreamTest, TestCustomTypes)
    {
        EXPECT_TRUE(traits::is_writable_to_stream_v<writable_to_stream&>);
        EXPECT_TRUE(traits::is_writable_to_stream_v<writable_to_stream>);

        EXPECT_FALSE(traits::is_writable_to_stream_v<non_writable_to_stream&>);
        EXPECT_FALSE(traits::is_writable_to_stream_v<non_writable_to_stream>);
    }
}