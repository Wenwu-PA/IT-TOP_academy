#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../modules/Lexer.h"

// class LexerEncoding: public testing::Test
// {
// public:
//     Lexer lexer;

// };

// 1 //
TEST(LexerTests, Return_empty_token_list_when_empty_expression)
{
    Interpreter::Tokens tokens{ Interpreter::Lexer::Tokenize("") };
    EXPECT_EQ(true, tokens.empty());
}

// 2 //
TEST(LexerTests, Return_op_token_list_when_empty_expression)
{
    Interpreter::Tokens tokens{ Interpreter::Lexer::Tokenize("+") };
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("+", tokens[0].getContent());
}

// 3 //
TEST(LexerTests, Should_tokenize_single_digit)
{
    Interpreter::Tokens tokens{ Interpreter::Lexer::Tokenize("1") };
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("1", tokens[0].getContent());
}

// 4 //
TEST(LexerTests, Should_get_type_for_number_token)
{
    Interpreter::Token numToken(102.2);
    EXPECT_EQ(Interpreter::TokenType::Number, numToken.getType());
    EXPECT_EQ("102.2", numToken.getContent());
}

// 5 //
TEST(LexerTests, Should_get_operator_code_from_operator_token)
{
    Interpreter::Token numToken(Interpreter::Operator::Plus);
    EXPECT_EQ("+", numToken.getContent());
}

// 6 //
TEST(LexerTests, List_tokens_from_simple_expression)
{
    Interpreter::Tokens tokens(Interpreter::Lexer::Tokenize("2+4"));
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("2", tokens[0].getContent());
    EXPECT_EQ("+", tokens[1].getContent());
    EXPECT_EQ("4", tokens[2].getContent());
}
// 7
TEST(LexerTests, List_tokens_from_simple_expression1)
{
    Interpreter::Tokens tokens(Interpreter::Lexer::Tokenize("7+7"));
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("7", tokens[0].getContent());
    EXPECT_EQ("+", tokens[1].getContent());
    EXPECT_EQ("7", tokens[2].getContent());
}
// 8
TEST(LexerTests, List_tokens_from_simple_expression2)
{
    Interpreter::Tokens tokens(Interpreter::Lexer::Tokenize("10+4"));
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("10", tokens[0].getContent());
    EXPECT_EQ("+", tokens[1].getContent());
    EXPECT_EQ("4", tokens[2].getContent());
}
// 9
TEST(LexerTests, List_tokens_from_simple_expression3)
{
    Interpreter::Tokens tokens(Interpreter::Lexer::Tokenize("22+4"));
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("22", tokens[0].getContent());
    EXPECT_EQ("+", tokens[1].getContent());
    EXPECT_EQ("4", tokens[2].getContent());
}
// 10

TEST(LexerTests, List_tokens_from_simple_expression5)
{
    Interpreter::Tokens tokens(Interpreter::Lexer::Tokenize("22*(9+22)*8"));
    EXPECT_EQ(9, tokens.size());
    EXPECT_EQ("22", tokens[0].getContent());
    EXPECT_EQ("*", tokens[1].getContent());
    EXPECT_EQ("(", tokens[2].getContent());
    EXPECT_EQ("9", tokens[3].getContent());
    EXPECT_EQ("+", tokens[4].getContent());
    EXPECT_EQ("22", tokens[5].getContent());
    EXPECT_EQ(")", tokens[6].getContent());
    EXPECT_EQ("*", tokens[7].getContent());
    EXPECT_EQ("8", tokens[8].getContent());
}
TEST(LexerTests, List_tokens_from_simple_expression6)
{
    Interpreter::Tokens tokens(Interpreter::Lexer::Tokenize("22/4"));
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("22", tokens[0].getContent());
    EXPECT_EQ("/", tokens[1].getContent());
    EXPECT_EQ("4", tokens[2].getContent());
}
TEST(LexerTests, List_tokens_from_simple_expression7)
{
    Interpreter::Tokens tokens(Interpreter::Lexer::Tokenize("22.321+42.112"));
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("22.321", tokens[0].getContent());
    EXPECT_EQ("+", tokens[1].getContent());
    EXPECT_EQ("42.112", tokens[2].getContent());
}
TEST(LexerTests, List_tokens_from_simple_expression8)
{
    Interpreter::Tokens tokens(Interpreter::Lexer::Tokenize("222-4"));
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("222", tokens[0].getContent());
    EXPECT_EQ("-", tokens[1].getContent());
    EXPECT_EQ("4", tokens[2].getContent());
}