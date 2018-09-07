#include <gtest.hpp>
#include <sequence_call.hpp>
#include <algorithm>
#include <string>

namespace test
{
    TEST(SequenceCallTest, TestArithmeticSequenceCall)
    {
        int value = 1;
        
        value = cpputil::make_sequence_call(
            [](int& value) -> int& { value += 1; return value; },
            [](int& value) -> int& { value += 2; return value; },
            [](int& value) -> int& { value += 4; return value; },
            [](int& value) -> int& { value += 8; return value; }
        )(value);

        EXPECT_EQ(16, value);
    }

    TEST(SequenceCallTest, TestStringOperationsSequenceCall)
    {
        std::string text{ " a b c d e " };

        text = cpputil::make_sequence_call(
            [](std::string& text) -> std::string& {
                text.erase(std::remove_if(std::begin(text), std::end(text), ::isspace),
                    std::cend(text));

                return text;
            },
            [](std::string& text) -> std::string& {
                std::transform(std::begin(text), std::end(text),
                    std::begin(text), ::toupper);

                return text;
            }
        )(text);

        EXPECT_EQ(text, "ABCDE");
    }
}