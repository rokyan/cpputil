#include <gtest.hpp>
#include <traits.hpp>

namespace test
{

TEST(EnableIfTest, TestEnableIf)
{
    using def_type = cpputil::enable_if_t<true>;
    EXPECT_SAME_TYPES(def_type, void);

    using custom_type = cpputil::enable_if_t<true, int>;
    EXPECT_SAME_TYPES(custom_type, int);
}

} // namespace test