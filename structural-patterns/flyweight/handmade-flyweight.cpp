#include <bits/stdc++.h>

using namespace std;

class User
{
    friend ostream& operator<<(ostream& _os, const User& _user);
    class UserImpl
    {
    public:
        UserImpl(const string& _first_name,
                 const string& _last_name) 
                            : first_name{add(_first_name)}
                            , last_name{add(_last_name)}
        {

        }

        static map<string, size_t>& get_database()
        {
            static map<string, size_t> hashdb;

            return hashdb;
        }

        static size_t add(const string& _name)
        {
            static size_t key = 0;
            auto& db = get_database();

            auto itor = db.find(_name);
            if (itor == db.end())
            {
                db[_name] = key++;
            }
            return db[_name];
        }

        string get_name(size_t _key) const
        {
            auto& db = get_database();
            for (auto itor = db.begin(); itor != db.end(); itor++)
            {
                if (itor->second == _key)
                    return itor->first;
            }
            return "nullptr";
        }

        string get_first_name() const
        {
            return get_name(first_name);
        }

        string get_last_name() const
        {
            return get_name(last_name);
        }

        size_t get_first_name_key() const
        {
            return first_name;
        }

        size_t get_last_name_key() const
        {
            return last_name;
        }
        
        size_t get_database_size() const
        {
            return get_database().size();
        }
    private:
        size_t first_name;
        size_t last_name;
    };

public:
    User(string _first_name, string _last_name) : user_impl{make_shared<UserImpl>(_first_name, _last_name)} {}
private:
    shared_ptr<UserImpl> user_impl;
};

ostream& operator<<(ostream& _os, const User& _user)
{
    _os << "[User] full name " << _user.user_impl->get_first_name() << "-" << _user.user_impl->get_last_name() << ", database size " << _user.user_impl->get_database_size();
    return _os;
}

int main(int argc, char **argv)
{
    User u1{"Jimmy", "Nguyen"};
    User u2{"Kathy", "Nguyen"};
    User u3{"Jimmy", "Kathy"};
    User u4{"Nguyen", "Kathy"};
    User u5{"Kathy", "Jimmy"};
    User u6{"Nguyen", "Jimmy"};

    cout << u1 << endl;
    cout << u2 << endl;
    cout << u3 << endl;
    cout << u4 << endl;
    cout << u5 << endl;
    cout << u6 << endl;
    return 0;
}