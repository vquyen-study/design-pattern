Template method coding exercise.
> **Problem:** Imagine a typical collectibe card game which has cards representing creatures. Each creature has two values; *attack* and > *health*. Creatures can fight each other, dealing their attack damage, thereby reducing their opponent's health.
> - The calss CardGame implments the logic for two creatures fighting one other. However, the exact mechanics of how damage is dealt is > different:
> 	- *TemporaryCardDamage*: In some games(eg Magic the Gathering) unless the creature has been killed, its health returns to the original > value at the end of combat.
> 	- *PermanentCardDamage*: In other game (eg Hearthstone), health damage persists.
> - You're asked to implement classes *TemporaryCardDamage* and *PermanentCardDamage* that would allow us to simulate combat between > creatures.
> - Examples:
> 	- With temporary damage, creatures 1/2 and 1/3 can never kill on another. With permanent damage, second creature will win after 2 > rounds of combat.
> 	- With eith temporary and permanent damage, two 2/2 creatures kill one other.

- Template code
> ```C++
> #include <iostream>
> #include <vector>
> #include <complex>
> #include <tuple>
> using namespace std;
> 
> struct Creature
> {
>     int attack, health;
> 
>     Creature(int attack, int health) : attack(attack), health(health) {}
> };
> 
> struct CardGame
> {
>     vector<Creature> creatures;
> 
>     CardGame(const vector<Creature> &creatures) : creatures(creatures) {}
> 
>     // return the index of the creature that won (is a live)
>     // example:
>     // - creature1 alive, creature2 dead, return creature1
>     // - creature1 dead, creature2 alive, return creature2
>     // - no clear winner: return -1
>     int combat(int creature1, int creature2)
>     {
>       // todo
>     }
> 
>     virtual void hit(Creature& attacker, Creature& other) = 0;
> };
> 
> struct TemporaryCardDamageGame : CardGame
> {
>     TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}
> 
>     void hit(Creature &attacker, Creature &other) override {
>       // todo
>     }
> };
> 
> struct PermanentCardDamageGame : CardGame
> {
>     PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}
> 
>     void hit(Creature &attacker, Creature &other) override
>     {
>       // todo
>     }
> };
> ```


- Solution:
```C++
#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct Creature
{
    int attack, health;

    Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
    vector<Creature> creatures;

    CardGame(const vector<Creature> &creatures) : creatures(creatures) {}

    // return -1 if there is no clear winner
    int combat(int creature1, int creature2)
    {
      Creature& first = creatures[creature1];
      Creature& second = creatures[creature2];
      hit(first, second);
      hit(second, first);
      bool first_alive = first.health > 0;
      bool second_alive = second.health > 0;
      if (first_alive == second_alive) return -1;
      return first_alive ? creature1 : creature2;
    }

    virtual void hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
    TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override {
      auto old_health = other.health;
      other.health -= attacker.attack;
      if (other.health > 0) other.health = old_health;
    }
};

struct PermanentCardDamageGame : CardGame
{
    PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override
    {
      other.health -= attacker.attack;
    }
};
```