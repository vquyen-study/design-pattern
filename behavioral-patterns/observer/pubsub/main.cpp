#include <bits/stdc++.h>
using namespace std;

#include "Observer.hpp"
#include "Observable.hpp"

struct Child : public Observable<Child>
{
    int age;
    string name;
    Child(const string& _name, int _age) : name{_name}, age{_age}
    {

    }

    ~Child() 
    {

    }

    void set_age(int _age)
    {
        age = _age;
        notify(*this, "age");
    }
};

struct Parent : public Observer<Child>
{
    virtual void field_changed(Child& source, const std::string& field_name)
    {
        cout << field_name << " " << source.name << " now is " << source.age << endl;
    }
};

int main(int argc, char **argv)
{
    Child ch1{"Messi", 22};
    Child ch2{"Ronado", 18};
    Parent p1;

    ch1.subscribe(p1);
    ch2.subscribe(p1);

    ch1.set_age(36);

    return 0;
}