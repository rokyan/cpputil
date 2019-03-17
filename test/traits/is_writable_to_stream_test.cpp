#include <gtest.hpp>
#include <traits.hpp>
#include <is_writable_to_stream_test_types.hpp>

namespace test
{

TEST(IsWritableToStreamTest, TestFundamentalTypes)
{
    EXPECT_TRUE(cpputil::is_writable_to_stream_v<int>);
    EXPECT_TRUE(cpputil::is_writable_to_stream_v<int&>);
}

TEST(IsWritableToStreamTest, TestCustomTypes)
{
    EXPECT_TRUE(cpputil::is_writable_to_stream_v<writable_to_stream&>);
    EXPECT_TRUE(cpputil::is_writable_to_stream_v<writable_to_stream>);

    EXPECT_FALSE(cpputil::is_writable_to_stream_v<non_writable_to_stream&>);
    EXPECT_FALSE(cpputil::is_writable_to_stream_v<non_writable_to_stream>);
}

} // namespace test
