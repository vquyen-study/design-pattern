#ifndef __CHAT_ROOM_H__
#define __CHAT_ROOM_H__
#include <bits/stdc++.h>
using namespace std;

// #include "person.hpp"

struct person;

struct chat_room
{
    vector<shared_ptr<person>> people;

    chat_room() = default;
    ~chat_room() = default;

    void broadcast(const string& orgin, const string& msg) const;
    void join(shared_ptr<person> _person, shared_ptr<chat_room> _room) ;

    vector<shared_ptr<person>> get_people_list() const;
};


#endif // __CHAT-ROOM_H__