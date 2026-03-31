#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../modules/Lexer.h"

// class LexerEncoding: public testing::Test
// {
// public:
//     Lexer lexer;

// };

TEST(LexerTests, Return_empty_token_list_when_empty_expression)
{
    Interpreter::Tokens tokens{ Interpreter::Lexer::Tokenize("") };
    EXPECT_EQ(true, tokens.empty());
}

TEST(LexerTests, Return_op_token_list_when_empty_expression)
{
    Interpreter::Tokens tokens{ Interpreter::Lexer::Tokenize("+") };
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("+",tokens[0].getContent());
}
TEST(LexerTests, Should_tokenize_single_digit)
{
    Interpreter::Tokens tokens{ Interpreter::Lexer::Tokenize("1") };
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("1",tokens[0].getContent());
}
TEST(LexerTests, Should_get_type_for_number_token){
    Interpreter::Token numToken(1.2);
    EXPECT_EQ(Interpreter::TokenType::Number,numToken.getType());
}
TEST(LexerTests, Should_get_type_for_number){
    Interpreter::Token numToken(Interpreter::Operator::Plus);
    EXPECT_EQ("+",numToken.getContent());
}