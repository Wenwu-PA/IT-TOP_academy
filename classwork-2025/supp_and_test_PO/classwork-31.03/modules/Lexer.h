#pragma once

#include <vector>
#include <string>

namespace Interpreter
{
    enum TokenType{
        Operator,
        Number,
        Unknown
    };

    enum Operator
    {
        Plus = '+',
        Minus = '-',
        Mult = '*',
        Div = '/'
    };
    
    class Token
    {
        std::string content;
        TokenType type;
    public:
        explicit Token(std::string cont): content{cont}
        {
            if (cont == std::string{Operator::Plus} || 
            cont == std::string{Operator::Minus} ||
            cont == std::string{Operator::Mult} ||
            cont == std::string{Operator::Div}){
                type = TokenType::Operator;
            }
            type = TokenType::Unknown;

        }
        explicit Token(double num)
                        : content{std::to_string(num)}, type(TokenType::Number)
        {}
        explicit Token(enum Operator op)
                        :type{TokenType::Operator}
        {
            if (op == Operator::Plus) content = std::string{Operator::Plus};
            if (op == Operator::Minus) content = std::string{Operator::Minus};
            if (op == Operator::Mult) content = std::string{Operator::Mult};
            if (op == Operator::Div) content = std::string{Operator::Div};

        }
        std::string getContent() const
        {return content;}
        TokenType getType() const
        {return type;}
    };

    typedef std::vector<Token> Tokens;
    
    // typedef Operator Token;

    namespace Lexer
    {
        inline Tokens Tokenize(std::string expr) 
        {
            if(expr.empty()) return Tokens{};
            if(expr == std::string{Operator::Plus}) return {Token{std::string{Operator::Plus}}};

            return {Token{"1"}};
            
        }

    }
}
