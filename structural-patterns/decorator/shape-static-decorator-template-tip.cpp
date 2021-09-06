#include <bits/stdc++.h>

using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual string str() = 0;
};

class Square : public Shape
{
private:
    double side;
public:
    Square(double _side) : side{_side} {}
    Square() : side{0} {}
    ~Square() {}

    double area() override
    {
        return side * side;
    }

    double perimeter() override
    {
        return 4 * side;
    }

    string str() override
    {
        return "Square";
    }
};

class Rectangle : public Shape
{
private:
    double heigh, width;
public:
    Rectangle(double h, double w) : heigh{h}, width{w} {}
    Rectangle() : heigh{0}, width{0} {}
    ~Rectangle() {}

    double area() override
    {
        return heigh * width;
    }
    double perimeter() override
    {
        return 2 * (heigh + width);
    }

    string str() override
    {
        return "Rectangle";
    }
};

template<typename T>
class ShapeColor : public T
{
    /* Do static checking, this class only allows the derived class of SHARPE class. */
    static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");
private:
    string shape_color;
public:
    ShapeColor() {}
    ~ShapeColor() {}

    template <typename ...Args>
    ShapeColor(const string& color, Args ...args) : T(forward<Args>(args)...), shape_color{color} {}

    string str() override
    {
        string s = T::str();
        
        if (s.find("decorator with") == string::npos)
        {
            s += " decorator with " + shape_color;
        }
        else if (s.find(shape_color) == string::npos)
        {
            s += " and " + shape_color;
        }

        return s;
    }
};



int main(int argc, char **argv)
{
    
    ShapeColor<ShapeColor<Square>> red_square{"Red", "Green", Square(3)};
    ShapeColor<ShapeColor<ShapeColor<Square>>> yellow_square {"yellow", red_square};
    
    cout << red_square.str() << " area " << red_square.area() << endl;
    cout << yellow_square.str() << " area " << yellow_square.area() << endl;

    return 0;
}

