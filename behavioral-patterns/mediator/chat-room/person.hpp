#ifndef __PERSON_H__
#define __PERSON_H__

#include <bits/stdc++.h>
using namespace std;

// #include "chat-room.hpp"

struct chat_room;

struct person
{
    string TAG;
    string name;

    vector<string> chat_log;

    shared_ptr<chat_room> room;

    person(const string& _name) : name{_name} 
    {
        TAG = "[" + name + "] ";
    }
    ~person() = default;

    void say(const string& msg) const;
    void pm(const string& dest_name, const string& msg) const;

    void receive(const string& origin, const string& msg);

};

#endif // __PERSON_H__