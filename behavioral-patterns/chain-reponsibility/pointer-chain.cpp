#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name{""};
    int age{0};
    int grade{0};
    string id{"000000"};
};

class StudentModifier
{
    StudentModifier* next{nullptr};
public:
    StudentModifier(Student& _student) : student{_student} {}

    void add(StudentModifier* _modifier)
    {
        if (next) next->add(_modifier);
        else    next = _modifier;
    }

    virtual void modify()
    {
        if (next) 
        {
            next->modify();
            next = nullptr;     // unlink after process.
        }
    }
protected:
    Student& student;
};

class StudentGetNextGrade : public StudentModifier
{
public:
    StudentGetNextGrade(Student& _student) : StudentModifier{_student}  
    {

    }
    void modify() override
    {
        student.grade++;
        StudentModifier::modify();
    }
};

class StudentIncreaseAge : public StudentModifier
{
public:
    StudentIncreaseAge(Student& _student) : StudentModifier{_student}  
    {

    }
    void modify() override
    {
        student.age++;
        StudentModifier::modify();
    }
};

ostream& operator<<(ostream& _os, Student _obj)
{
    _os << "name " << _obj.name << ", age " << _obj.age << ", grade " << _obj.grade << ", id " << _obj.id ;
    return _os;
}

int main(int argc, char **argv)
{
    Student st{"Messi", 9, 5, "000001"};
    StudentIncreaseAge md_increase_age{st};
    StudentGetNextGrade md_next_grade{st};

    StudentModifier modifier{st};
    modifier.add(&md_increase_age);
    modifier.add(&md_next_grade);

    cout << st << endl;
    modifier.modify();
    modifier.modify();
    cout << st << endl;
    return 0;
}