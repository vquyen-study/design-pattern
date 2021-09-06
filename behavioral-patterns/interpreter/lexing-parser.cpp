#include <bits/stdc++.h>
using namespace std;

#include <boost/lexical_cast.hpp>

struct Token
{
    enum Type {Integer, Plus, Minus, Lparen, Rparen} type;
    string text;

    Token(Type _type, const string& _text) : type{_type}, text {_text}
    {

    }

    friend ostream& operator<<(ostream& _os, const Token& obj)
    {
        _os << obj.text;
        return _os;
    }
};


struct TokenConverter
{
    using Type = Token::Type;

    static vector<Token> lex(const string& _input)
    {
        vector<Token> res;
        string num = "";
        for (auto i = 0; i < _input.size(); i++)
        {
            switch (_input[i])
            {
            case '+':
                res.emplace_back(Type::Plus, "+");
                break;
            case '-':
                res.emplace_back(Type::Minus, "-");
                break;
            case '(':
                res.emplace_back(Type::Lparen, "(");
                break;         
            case ')':
                res.emplace_back(Type::Rparen, ")");
                break;
            case '0'...'9':
                do
                {
                    num += _input[i++];
                } while (isdigit(static_cast<int>(_input[i])));
                res.emplace_back(Type::Integer, num);

                /* Clear number string & decrease index 'i' */
                num.clear();
                i--;
                break;      
            default:
                break;
            }
        }
        return res;
    }
};

struct Element
{
    virtual ~Element() = default;
    virtual int eval() = 0;
};

struct Integer : Element
{
    int value;
    Integer(const int& _value) : value{_value} {}
    int eval() override { return value; }
};

struct BinaryOperation : Element
{
    using Type = Token::Type;
    Type type;
    shared_ptr<Element> lhs, rhs;

    int eval() override 
    { 
        if (type == Type::Plus)
            return lhs->eval() + rhs->eval();
        else
            return lhs->eval() - rhs->eval(); 
    }
};


unique_ptr<Element> parse(const vector<Token>& tokens)
{
  auto result = make_unique<BinaryOperation>();
  bool have_lhs = false;
  for (size_t i = 0; i < tokens.size(); i++)
  {
    auto token = tokens[i];
    switch(token.type)
    {
    case Token::Type::Integer:
    {
      int value = boost::lexical_cast<int>(token.text);
      auto integer = make_shared<Integer>(value);
      if (!have_lhs) {
        result->lhs = integer;
        have_lhs = true;
      }
      else result->rhs = integer;
    }
      break;
    case Token::Type::Minus:
    case Token::Type::Plus:
      result->type = token.type;
      break;
    case Token::Type::Lparen:
    {
      auto j = i + 1;
      for (; j < tokens.size(); ++j)
        if (tokens[j].type == Token::Type::Rparen)
          break; // found it!

        auto first = tokens.begin() + i + 1;
        auto end = tokens.begin() + j;
        vector<Token> subexpression(first, end);
        auto element = parse(subexpression);
        if (!have_lhs) 
        {
            result->lhs = move(element);
            have_lhs = true;
        }
        else result->rhs = move(element);

        i = j; // advance

    }
    break;
    }
  }
  return result;
}

int main(int argc, char **argv)
{
    string input{"(13-4)-(12+1)"};

    vector<Token> tks = TokenConverter::lex(input);

    for (auto& el : tks)
        cout << el;

    auto _parser = parse(tks);

    cout << " = " << _parser->eval();
    return 0;
}