#include <bits/stdc++.h>
using namespace std;

#include "chat-room.hpp"
#include "person.hpp"

int main(int argc, char **argv)
{
    shared_ptr<person> per_1 = make_shared<person>(person{"Person 1"});
    shared_ptr<person> per_2 = make_shared<person>(person{"Person 2"});
    shared_ptr<person> per_3 = make_shared<person>(person{"Person 3"});

    shared_ptr<chat_room> room = make_shared<chat_room>(chat_room());
    room->join(per_1, room);
    room->join(per_2, room);
    room->join(per_3, room);

    per_1->say("This fake news from person 1 ...");
    per_2->say("This fake news from person 2 ...");
    per_3->say("This fake news from person 3 ...");

    cout << endl;

    per_1->pm("Person 2", "Hi Person 2....");
    per_2->pm("Person 3", "Hi Person 2....");
    
    return 0;
}

