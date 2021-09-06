#include <bits/stdc++.h>
using namespace std;

#include "person.hpp"
#include "chat-room.hpp"

void person::say(const string& msg) const
{
    cout << TAG << "say()" << endl;

    room->broadcast(name, msg);
}

void person::pm(const string& dest_name, const string& msg) const
{
    auto list = room->get_people_list();
    for (auto p : list)
    {
        if (p->name == dest_name)
        {
            p->receive(name, msg);
            break;
        }
    }
}

void person::receive(const string& origin, const string& msg) 
{
    cout << TAG << "<<" << origin  << ">> " << " \"" << msg << "\"" << endl;
    chat_log.emplace_back(origin + "\"" + msg + "\"");
}

