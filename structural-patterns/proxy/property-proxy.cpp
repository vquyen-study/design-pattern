#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Property
{
private:
    T value;

public:
    Property(T _value)
    {
        *this = value;
    }

    T operator=(const T& _value)
    {
        return value = _value;
    }

    operator T()
    {
        return value;
    }
};


struct Creature
{
    Property<double> strength{1};
    Property<double> agility{2};
};

int main(int argc, char **argv)
{
    Creature creature;
    creature.strength = 10;
    creature.agility = 15;

    double u = creature.agility;

    cout << "Strength: " << creature.agility << " , Agility: " << creature.strength << endl;

    return 0;
}