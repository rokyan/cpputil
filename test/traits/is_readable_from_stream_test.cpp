#include <gtest.hpp>
#include <traits.hpp>
#include <is_readable_from_stream_test_types.hpp>

namespace test
{

TEST(IsReadableFromStreamTest, TestFundamentalTypes)
{
    EXPECT_TRUE(cpputil::is_readable_from_stream_v<int&>);
    EXPECT_FALSE(cpputil::is_readable_from_stream_v<int>);
}

TEST(IsReadableFromStreamTest, TestCustomTypes)
{
    EXPECT_TRUE(cpputil::is_readable_from_stream_v<readable_from_stream&>);
    EXPECT_FALSE(cpputil::is_readable_from_stream_v<readable_from_stream>);

    EXPECT_FALSE(cpputil::is_readable_from_stream_v<non_readable_from_stream&>);
    EXPECT_FALSE(cpputil::is_readable_from_stream_v<non_readable_from_stream>);
}

} // namespace test
