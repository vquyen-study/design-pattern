#include <bits/stdc++.h>
using namespace std;

#include "person.hpp"
#include "chat-room.hpp"

void chat_room::broadcast(const string& origin, const string& msg) const
{
    for (auto p : people)
    {
        if (p->name != origin)
        {
            p->receive(origin, msg);
        }
    }
}

void chat_room::join(shared_ptr<person> _person, shared_ptr<chat_room> _room) 
{
    broadcast(_person->name, "Hi everybody, I'm " + _person->name);
    _person->room = _room;
    people.push_back(_person);
}

vector<shared_ptr<person>> chat_room::get_people_list() const
{
    return people;
}