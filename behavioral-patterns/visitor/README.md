Visitor Coding Exercise
- You are asked to implement a double-dispatch visitor called ExpressionPrinter for printing different mathematical expression. The range of expression covers addition and multiplication please put round brackets around addition but *not* around multiplication! Also, please avoid any blank spaces in output.
- Example:
	- Input: AdditionExpression{Literal{2}, Literal{3}} - btw, this is pseudocode, you can not inline those references unfortunately.
	- Output: (2+3)
Here is the corresponding unit test:
```C++
	Value a{2};
	Value b{3};
	AdditionExpression simple{v2, v3};
	ExpressionPrinter ep;
	ep.accept(simple);
	ASSERT_EQ("(2+3)", ep.str());
```

- Template code.
```C++
#include <string>
#include <sstream>
using namespace std;

struct ExpressionVisitor
{
  // accept methods here :)
};

struct Expression
{
  virtual void visit(ExpressionVisitor& ev) = 0;
};

struct Value : Expression
{
  int value;

  Value(int value) : value(value) {}
};

struct AdditionExpression : Expression
{
  Expression &lhs, &rhs;

  AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}
};

struct MultiplicationExpression : Expression
{
  Expression &lhs, &rhs;

  MultiplicationExpression(Expression &lhs, Expression &rhs)
    : lhs(lhs), rhs(rhs) {}
};

struct ExpressionPrinter : ExpressionVisitor
{
    // accept methods here :)

  string str() const { /* todo */ }
};
```

- Answer:
```C++
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
```