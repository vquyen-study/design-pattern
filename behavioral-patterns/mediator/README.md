### Problem
> - Our system has any number of instances of *Participant* classes. Each Participant has a *value* integer, initially zero.
> - A participant can *say()* a particular value, which is broadcase to all other participants. At this point, every other participant is *obliged* to increase their value by the *value* being broadcast.
> Example:
>> - Two participant with value 0 and 0 respectively.
>> - Participant 1 broadcasts the value 3. We now have Participant 1 value = 0, Participant 2 value = 3.
>> - Participant 2 broadcast the value 2. We now have Participant 1 value = 2, Participant 2 value = 3.

>> Template
>> ```C++
>> struct Participant : IParticipant
>> {
>>     int value{0};
>>     Mediator& mediator;
>> 
>>     Participant(Mediator &mediator) : mediator(mediator)
>>     {
>>       mediator.participants.push_back(this);
>>     }
>> 
>>     void say(int value)
>>     {
>>         // todo
>>     }
>> };
>> ```



### Answer:
> ```C++
> #include <bits/stdc++.h>
> using namespace std;
> 
> struct Participant;
> 
> struct IParticipant
> {
>     virtual void notify(IParticipant* sender, int value) = 0;
> };
> 
> struct Mediator
> {
>     vector<IParticipant*> participants;
>     void broadcast(IParticipant* sender, int value)
>     {
>       for (auto p : participants)
>         p->notify(sender, value);
>     }
> };
> 
> struct Participant : IParticipant
> {
>     int value{0};
>     Mediator& mediator;
> 
>     Participant(Mediator &mediator) : mediator(mediator)
>     {
>       mediator.participants.push_back(this);
>     }
> 
>     void notify(IParticipant *sender, int value) override {
>       if (sender != this)
>         this->value += value;
>     }
> 
>     void say(int value)
>     {
>       mediator.broadcast(this, value);
>     }
> };
> ```
