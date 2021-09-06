### Problem:
> - Consider the quadratic equation and its canonical solution:
> ax^2 + bx + c = 0
> x1 = (-b + sqrt(b^2 - 4ac)) / (2a)
> x2 = (-b - sqrt(b^2 - 4ac)) / (2a)
> 
> - The part ***b^2 - 4ac*** is called the *discriminant*. Suppose we want to provide an API with *two different strategies* for calculating > the *discriminant*:
>   1. In **OrdinaryDiscriminantStrategy** if the *discriminant* is negative, we return it as-is. This is OK, since our main API return > **std::complex** numbers anyway.
>   2. In **RealDiscriminantStrategy**, if the discriminant is negative, the return value is NaN(Not a Number). NaN propagates throughout the caculation, so the equation solver gives two NaN values.
> 
> - Please implement both of these strategies as well as the equation slover itself. with regards to plus-minus in the formula, please return '+' result as the first element and '-' as the second.

- Template:
```C++
#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};
```

### Solution
```C++
#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override
    {
        return ((b * b) - (4 * a * c));
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override
    {
        double delta = ((b * b) - (4 * a * c));
        if (delta < 0)
            return numeric_limits<double>::quiet_NaN();
        
        return delta;
    }
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
      complex<double> disc{strategy.calculate_discriminant(a,b,c), 0};
      auto root_disc = sqrt(disc);
      return {
          (-b+root_disc) / (2*a),
          (-b-root_disc) / (2*a) };
    };
};
```