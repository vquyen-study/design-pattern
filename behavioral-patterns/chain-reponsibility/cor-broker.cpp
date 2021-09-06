#include <bits/stdc++.h>
using namespace std;

#include <boost/signals2.hpp>
using namespace boost::signals2;


struct Query
{
    string name;
    enum Argument {attack, defense} argument;
    int result;

    Query(const string& _name, Argument _arg, int _result)  : name{_name}
                                                            , argument{_arg}
                                                            , result{_result}
    {


    }
};

struct Game
{
    boost::signals2::signal<void(Query&)> queries;
};

class Creature
{
    Game& game;
    int attack, defense;
public:
    std::string name;
    Creature() = default;
    Creature(Game& _game, const string& _name, 
            const int _attak, const int _defense) :
            game{_game},
            attack{_attak}, defense{_defense},  name{_name}
    {
        
    }

    int GetAttack() const
    {
        Query q{name, Query::Argument::attack, attack};
        game.queries(q);
        return q.result;
    }

    friend ostream& operator<<(ostream& _os, const Creature& obj)
    {
        _os << "name " << obj.name 
            << ", attack " << obj.GetAttack() 
            << ", defense "  << obj.defense << endl;
        return _os;
    }
};

class CreatureModifier
{
    Game& game;
    Creature& creature;
public:
    virtual ~CreatureModifier() = default;
    CreatureModifier(Game& _game, 
                    Creature& _creature)    : game{_game} 
                                            , creature{_creature}
    {

    }
};

class DoubleAttackModifier : public CreatureModifier
{
    connection conn;
public:
    DoubleAttackModifier(Game& _game, 
                        Creature& _creature)    : CreatureModifier{_game, _creature}
    {
        conn = _game.queries.connect([&](Query& q){
            if (q.name == _creature.name || q.argument == Query::Argument::attack)
            {
                q.result *= 2; /* Double argurment. */
            }
        });
    }

    ~DoubleAttackModifier()
    {
        conn.disconnect();
    }
};



int main(int argc, char **argv)
{
    Game game;
    Creature goblin{ game, "Strong Goblin", 2, 2 };

    cout << goblin << endl;
    {
        /**
         * This has been created an DoubleAttackModifier object, and register 
         * signal2 function handler to handle income message later on. 
         */
        DoubleAttackModifier dam{ game, goblin };
        cout << goblin << endl;
        
    }
    cout << goblin << endl;
    
    return 0;
}