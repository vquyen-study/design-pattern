### Problem:
> - A combination is a lock that opens after the right digits have been entered. A lock is preprogrammed with a combination( eg: 12345) and the user is expected to enter this combination to unlock the lock.
> - The lock has a ***status*** field that indicates the state of the lock. the rules are:
>> - If the lock has just been locked(or at the startup), the status is LOCKED.
>> - If a digit has been entered, that digit is shown on the screen. As the user enters more digits, they are added to Status.
>> - If the user has entered the correct sequence of digits, the lock status changes to OPEN.
>> - If the use enters an incorrect sequence of digits, the lock status changes to ERROR.
> - Please implement the ***CombinationLock*** class to enable this behavior. Be sure to test both *correct* and *incorrect* inputs.
> - Here is an example unit test for the lock.
> ```C++
> CombinationLock cl(1, 2, 3);
> ASSERT_EQ("LOCKED", cl.status);
> cl.enter_digit(1);
> ASSERT_EQ("1", cl.status);
> cl.enter_digit(2);
> ASSERT_EQ("12", cl.status);
> cl.enter_digit(3);
> ASSERT_EQ("OPEN", cl.status);
> ```


> Template
> ```C++
> #include <iostream>
> #include <vector>
> #include <string>
> using namespace std;
> 
> class CombinationLock
> {
>     vector<int> combination;
> public:
>     string status;
> 
>     CombinationLock(const vector<int> &combination) : combination(combination) {
>       
>     }
> 
>     void enter_digit(int digit)
>     {
>       // TODO
>     }
> };
> ```


### Solution 1:
> ```C++
> #include <bits/stdc++.h>
> using namespace std;
> 
> class CombinationLock
> {
>     vector<int> combination;
>     
> public:
>     string status;
> 
>     CombinationLock(const vector<int> &combination) : combination(combination) {
>         status = "LOCKED";
>       
>     }
> 
>     void enter_digit(int digit)
>     {
>         if (status == "LOCKED" || status == "ERROR") status = "";
>         
>         status += to_string(digit);
>         
>         if (status.size() == combination.size())
>         {
>             stringstream result;
>             copy(combination.begin(), combination.end(), std::ostream_iterator<int>(result, ""));
>             status = (status == result.str() ? "OPEN" : "ERROR");
>         }
>         
>     }
> };
> ```

### Solution 2:
> ```C++
> class CombinationLock
> {
>     vector<int> combination;
>     int digits_entered{0};
>     bool failed{false};
> 
>     void reset()
>     {
>       status = "LOCKED";
>       digits_entered = 0;
>       failed = false;
>     }
> public:
>     string status;
> 
>     CombinationLock(const vector<int> &combination) : combination(combination) {
>       reset();
>     }
> 
>     void enter_digit(int digit)
>     {
>       if (status == "LOCKED") status = "";
>       status +=  to_string(digit);
>       if (combination[digits_entered] != digit)
>       {
>         failed = true;
>       }
>       digits_entered++;
> 
>       if (digits_entered == combination.size())
>         status = failed ? "ERROR" : "OPEN";
>     }
> };
> ```