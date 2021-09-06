#include <bits/stdc++.h>
using namespace std;

struct CurrencyObj
{
    int balance;
    CurrencyObj(const int& _balan) : balance{_balan} {}

    /* Copy operator. */
    CurrencyObj& operator=(const CurrencyObj& _obj)
    {
        balance = _obj.balance;
        return *this;
    }

    CurrencyObj& operator+(const CurrencyObj& _value)
    {
        balance += _value.balance;
        return *this;
    }

    CurrencyObj& operator+=(int _value)
    {
        balance += _value;
        return *this;
    }

    friend ostream& operator<<(ostream& _os, const CurrencyObj& obj)
    {
        _os << obj.balance;
        return _os;
    }
};

class BankAccount
{
    class MementoImpl
    {
        friend class BankAccount;
    public:
        MementoImpl() = default;
        ~MementoImpl() = default;

        bool add(const CurrencyObj& _amount)
        {
            if (curr_pos != memento.size())
                memento.erase(memento.begin()+ curr_pos + 1, memento.end());

            memento.emplace_back(_amount);
            curr_pos = memento.size() - 1;
            return true;
        }

        bool undo(CurrencyObj& obj)
        {
            if (curr_pos > 0)
            {
                --curr_pos;
                obj = memento[curr_pos];
                return true;
            }
            return false;
        }

        bool redo(CurrencyObj& obj)
        {
            if ((curr_pos + 1) < memento.size())
            {
                ++curr_pos;
                obj = memento[curr_pos];
                return true;
            }
            return false;
        }
    private:
        vector<CurrencyObj> memento;
        size_t curr_pos{0};
    };
public:
    BankAccount(int _amount) : balance{_amount}
    {
        memento.add(balance);
    }

    bool deposit(int _amount)
    {
        balance += _amount;
        memento.add(balance);
        return true;
    }

    bool undo()
    {
        return memento.undo(balance);
    }

    bool redo()
    {
        return memento.redo(balance);
    }

    friend ostream& operator<<(ostream& _os, const BankAccount& obj)
    {
        _os << "Balance is " << obj.balance;
        return _os;
    }
private:
    CurrencyObj balance;
    MementoImpl memento;
};

int main(int argc, char**argv)
{
    BankAccount ba{160};
    ba.deposit(30); // 190
    ba.deposit(60); // 250
    ba.deposit(130); // 380.

    cout << ba << endl;
    ba.undo();
    cout << "Undo " << ba << endl;
    ba.undo();
    cout << "Undo " << ba << endl;

    ba.redo();
    cout << "Redo " << ba << endl;
    ba.redo();
    cout << "Redo " << ba << endl;

    auto flag = ba.redo();
    cout << boolalpha << "Redo " << flag  << " " <<  ba << endl; 
    return 0;
}