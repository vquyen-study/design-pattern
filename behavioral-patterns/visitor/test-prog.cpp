#include <bits/stdc++.h>
using namespace std;

struct Value;
struct AdditionExpression;
struct MultiplicationExpression;

struct ExpressionVisitor
{
  // accept methods here :)
  virtual void accept(Value& ae) = 0;
  virtual void accept(AdditionExpression& ae) = 0;
  virtual void accept(MultiplicationExpression& ae) = 0;
};

struct Expression
{
  virtual void visit(ExpressionVisitor& ev) = 0;
};

struct Value : Expression
{
  int value;

  Value(int value) : value(value) {}
  void visit(ExpressionVisitor& ev) override
  {
	 ev.accept(*this);
  }
};

struct AdditionExpression : Expression
{
  Expression &lhs, &rhs;

  AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}
  
  void visit(ExpressionVisitor& ev) override
  {
	 ev.accept(*this);
  }
};

struct MultiplicationExpression : Expression
{
  Expression &lhs, &rhs;

  MultiplicationExpression(Expression &lhs, Expression &rhs)
    : lhs(lhs), rhs(rhs) {}
	
	void visit(ExpressionVisitor& ev) override
	{
	 ev.accept(*this);
	}
};

struct ExpressionPrinter : ExpressionVisitor
{
	ostringstream oss;
    // accept methods here :)
	void accept(Value& v) override
	{
		oss << v.value;
	}
	
	void accept(AdditionExpression& ae) override
	{
		oss << "(";
        ae.lhs.visit(*this);
		oss << "+";
        ae.rhs.visit(*this);
		oss << ")";
	}
	
	void accept(MultiplicationExpression& me) override
	{
		me.lhs.visit(*this);
		oss << "*";
		me.rhs.visit(*this);
	}
	
	string str() const { return oss.str(); }
};

int main(int argc, char **argv)
{
    Value a{2};
	Value b{3};
	AdditionExpression simple{a, b};
	MultiplicationExpression me{simple, b};
	AdditionExpression simple1{a, me};

	ExpressionPrinter ep;
	ep.accept(simple1);

    cout << ep.str() << endl;
    return 0;
}