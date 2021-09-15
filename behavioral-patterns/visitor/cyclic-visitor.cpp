#include <bits/stdc++.h>
using namespace std;

// cyclic visitor: based on function overloading
//                 works only on a stable hierarchy
// acyclic visitor: based on RTTI
//                  no hierarchy limitations, but slower

template <typename T>
struct Visitor
{
    virtual void visit(T& visitor_base) = 0;
};

struct VisitorBase
{
    virtual ~VisitorBase() = default;
};

struct Expression
{
    virtual ~Expression() = default;

    virtual void accept(VisitorBase& obj)
    {
        // cout << "Expression..." << endl;
        using EV = Visitor<Expression>;
        if (auto ev = dynamic_cast<EV*>(&obj))
            ev->visit(*this);
    }
};

struct DoubleExpression : Expression
{
    double value;
    DoubleExpression(double _value) : value{_value} {}

    void accept(VisitorBase& obj)
    {
        // cout << "DoubleExpression..." << endl;
        using EV = Visitor<DoubleExpression>;
        if (auto ev = dynamic_cast<EV*>(&obj))
            ev->visit(*this);
    }    
};

struct AdditionExpression : Expression
{
    Expression *left{nullptr}, *right{nullptr};
    AdditionExpression(Expression *_left, Expression *_right) : left{_left}, right{_right} {}

    ~AdditionExpression()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }

    void accept(VisitorBase& obj)
    {
        // cout << "AdditionExpression..." << endl;
        using EV = Visitor<AdditionExpression>;
        if (auto ev = dynamic_cast<EV*>(&obj))
            ev->visit(*this);
    }    
};

struct ExpressionPrinter    : VisitorBase
                            , Visitor<Expression>
                            , Visitor<DoubleExpression>
                            , Visitor<AdditionExpression>
{
    void visit(Expression& visitor_base) override
    {
        cout << "....";
    }

    void visit(DoubleExpression& visitor_base) override
    {
        cout << visitor_base.value ;
    }

    void visit(AdditionExpression& visitor_base) override
    {
        cout << "(";
        visitor_base.left->accept(*this);
        cout << "+";
        visitor_base.right->accept(*this);
        cout << ")";
    }
};


int main(int argc, char **argv)
{

    auto expr = new AdditionExpression{
                        new DoubleExpression{8}, 
                        new AdditionExpression{
                            new DoubleExpression{9}, new DoubleExpression{10}
                        }
                };

    ExpressionPrinter ex_printer;
    ex_printer.visit(*expr);
    return 0;
}
