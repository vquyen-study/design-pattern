> **Problem:** You are asked to write and expression processor for simple function numeric expressions with the following constraints:
>> - Expressions use to integral value (ex: 1, 2, 3, ...), single-leter variables defined in >> *variables* as well as '+' and '-' operators only.
>> - There is no need to support braces or any other operations.
>> - If the is no found variable or if the expression is entered with variable with > 1 letters (ex : >> xy) then evulator returns 0(zero).
>> - In case of any parsing failure, evulator returns 0.

- Example:
```
    caculate("1+2+3") should return 6.
    caculate("1+2-xy") should return 0.
    caculate("10-2-x") when x = 3 is in variable should return 5.
```

- Template code:
```C++
#include <bits/stdc++.h>
using namespace std;

struct ExpressionProcessor
{
  map<char,int> variables;

  int calculate(const string& expression)
  {
    // TODO
    
  }
};
```


- Full code:
```C++
#include <bits/stdc++.h>
using namespace std;

struct ExpressionProcessor
{
  map<char,int> variables;

  int calculate(const string& expression)
  {
    // TODO
    int operation = '+';
    int result = 0;
    for (auto i = 0; i < expression.size(); i++)
    {
        switch(expression[i])
        {
            case '+':
            case '-':
                operation = expression[i];
                break;
            case '0'...'9':
            {
                int temp_val = 0;
                auto j = i;
                for (; j < expression.size(); ++j)
                    if (isdigit(expression[j]))
                        temp_val = (10 * temp_val) + (expression[j] - '0');
                    else break;
                
                /* Advance i to (j - 1) */
                i = (j - 1);
                
                switch(operation)
                {
                    case '+':
                        result += temp_val;
                        break;
                    case '-':
                        result -= temp_val;
                        break;
                }
            }
                break;
            case 'a'...'z':
            case 'A'...'Z':
            {
                if ((i + 1) < expression.size() && isalpha(expression[i + 1]))
                    return 0;

                auto itor = variables.find(expression[i]);
                if (itor == variables.cend())
                    return 0;
                switch(operation)
                {
                    case '+':
                        result += itor->second;
                        break;
                    case '-':
                        result -= itor->second;
                        break;
                    default:
                        return 0;
                }
                
            }
                break;
            default:
                return 0;
        
        }
    }
    
    return result;
  }
};
```