#include <bits/stdc++.h>
using namespace std;

struct DoubleExpression;
struct AdditionalExpression;
struct SubstractionExpression;

struct VisitorInterface
{
	virtual void visit(DoubleExpression *de) = 0;
	virtual void visit(AdditionalExpression *ae) = 0;
	virtual void visit(SubstractionExpression *se) = 0;
};

struct ExpressionPrinter : VisitorInterface
{

    ExpressionPrinter() = default;

	void visit(DoubleExpression *de) override;
	void visit(AdditionalExpression *ae) override;
	void visit(SubstractionExpression *se) override;
};

struct ExpressionInterface
{
	virtual void accept(VisitorInterface *visitor) = 0;
};

struct DoubleExpression : ExpressionInterface
{
	double value;
	DoubleExpression(double _value) : value{_value} {}
	
	void accept(VisitorInterface *visitor) override
	{
		visitor->visit(this);
	}
};

struct AdditionalExpression : ExpressionInterface
{
	ExpressionInterface *left, *right;
	AdditionalExpression(ExpressionInterface *_left, ExpressionInterface *_right) : left{_left}, right{_right} {}
	void accept(VisitorInterface *visitor) override
	{
		visitor->visit(this);
	}
};
struct SubstractionExpression : ExpressionInterface
{
	ExpressionInterface *left, *right;
	SubstractionExpression(ExpressionInterface *_left, ExpressionInterface *_right) : left{_left}, right{_right} {}
	
	void accept(VisitorInterface *visitor) override
	{
		visitor->visit(this);
	}
};

void ExpressionPrinter::visit(DoubleExpression *de) 
{
    cout << de->value;
}

void ExpressionPrinter::visit(AdditionalExpression *ae)
{
    cout << "(";
    ae->left->accept(this);
    cout << "+";
    ae->right->accept(this);
    cout << ")";
}

void ExpressionPrinter::visit(SubstractionExpression *se)
{
    cout << "(";
    se->left->accept(this);
    cout << "-";
    se->right->accept(this);
    cout << ")";
}

int main(int argc, char **argv)
{
	auto *ei = new AdditionalExpression {
                                new SubstractionExpression{new DoubleExpression{2}, new DoubleExpression{3}},
                                new SubstractionExpression{new DoubleExpression{5}, new DoubleExpression{9}},
                            };

    ExpressionPrinter eprinter;
    eprinter.visit(ei);
	return 0;
}