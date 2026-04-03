#pragma once

#include <vector>
#include <string>
#include <sstream>

namespace Interpreter
{
    enum class TokenType 
    {
        Operator, Number, Unknown
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
            if(cont == std::string{ Operator::Plus } || 
               cont == std::string{ Operator::Minus ||
               cont == std::string{ Operator::Mult } ||
               cont == std::string{ Operator::Div }}) type = TokenType::Operator;
            else type = TokenType::Unknown;
         }
        explicit Token(double num): content{ std::to_string(num) }, type{ TokenType::Number }
        {
            content.erase(content.find_last_not_of('0') + 1, std::string::npos);
            if(content.back() == '.') content.pop_back();
        }
        explicit Token(Operator op): type{TokenType::Number}
        {
            if(op == Operator::Plus) content = std::string{Operator::Plus};
            if(op == Operator::Minus) content = std::string{Operator::Minus};
            if(op == Operator::Mult) content = std::string{Operator::Mult};
            if(op == Operator::Div) content = std::string{Operator::Div};
        }
        std::string getContent() const
        { return content; }
        TokenType getType() const
        { return type; }
    };

    typedef std::vector<Token> Tokens;
    // typedef Operator Token;

    namespace Lexer
    {
        inline Tokens Tokenize(std::string expr) 
        {
            if(expr.empty()) return Tokens{};
            if(expr == std::string{Operator::Plus}) return {Token{std::string{Operator::Plus}}};

            std::istringstream stream{expr};
            Tokens listTokens;
            char ch;
            double partExprC;
            double partExprD;

            while(stream >> ch){
                if(std::isdigit(ch)){
                    stream.putback(ch);
                    double num;
                    stream >> num;
                    listTokens.push_back(Token{num});
                }
                else 
                    listTokens.push_back(Token{std::string(1,ch)});
                
            }
    
            return listTokens;
            // return {Token{"1"}};
        }
    }
}
