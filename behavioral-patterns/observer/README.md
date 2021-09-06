## Problems:
> - Imagine a game where one or more rats can attack a player. Each individual rat has an *attack* value of 1. Howerver, rats attack as a swarm, so each rat's *attack* value is equal to the total number of rats in play.
> - Given that a rat enters play through the constructor and leaves play(dies) via its destructor, please implement the *Game* and *Rat* classes so that, at any point in the game, the attack value of a rat is always consistent.
>
> Template code
> ```C++
> #include <iostream>
> #include <vector>
> using namespace std;
> 
> struct Game
> {
>     // todo
> };
> 
> struct Rat : IRat
> {
>     Game& game;
>     int attack{1};
> 
>     Rat(Game &game) : game(game)
>     {
>       // todo, obviously
>     }
> 
>     ~Rat() 
>     { 
>         // rat dies here!
>     }
> };
> ```


## Solution:
>```C++
> #include <iostream>
> #include <vector>
> #include <algorithm>
> using namespace std;
> 
> // struct IRat;
> struct IRat
> {
>     virtual void update(size_t attack) = 0;
> };
> 
> struct Game
> {
>     // todo
>     vector<IRat*> rats;
>     
>     virtual void add_new_rat(IRat *new_rat) 
>     {
>         rats.push_back(new_rat);
>         for (auto rat : rats) rat->update(rats.size());
>     }
>     
>     virtual void kick_off_rat(IRat *new_rat)
>     {
>         rats.erase(std::remove(rats.begin(), rats.end(), new_rat));
>         for (auto rat : rats) rat->update(rats.size());
>     }
>     
> };
> 
> struct Rat : IRat
> {
>     Game& game;
>     int attack{1};
> 
>     Rat(Game &game) : game(game)
>     {
>         // todo, obviously
>         game.add_new_rat(this);
>     }
> 
>     ~Rat() 
>     { 
>         // rat dies here!
>         game.kick_off_rat(this);
>     }
>     
>     
>     void update(size_t _attack) override
>     {
>         attack = _attack;
>     }
> };
>```