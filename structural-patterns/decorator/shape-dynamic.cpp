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

class ShapeColor : public Shape
{
private:
    Shape& shape;
public:
    explicit ShapeColor(Shape& _shape) : shape{_shape} {}
    ~ShapeColor() {}

    double area() override
    {
        return shape.area();
    }

    double perimeter() override
    {
        return shape.perimeter();
    }

    string str() override
    {
        return shape.str();
    }
};

class RedShape : public ShapeColor
{
private:
    /* data */
public:
    RedShape(Shape& _shape) : ShapeColor{_shape} {}
    ~RedShape() {}

    double area() override
    {
        return ShapeColor::area();
    }

    double perimeter() override
    {
        return ShapeColor::perimeter();
    }

    string str() override
    {
        string s = ShapeColor::str();
        if (s.find("decorator with") == string::npos)
        {
            s += " decorator with Red";
        }
        else if (s.find("Red") == string::npos)
        {
            s = s + " and Red";
        }
        return s;
    }
};

class GreenShape : public ShapeColor
{
private:
    /* data */
public:
    GreenShape(Shape& _shape) : ShapeColor{_shape} {}
    ~GreenShape() {}

    double area() override
    {
        return ShapeColor::area();
    }

    double perimeter() override
    {
        return ShapeColor::perimeter();
    }

    string str() override
    {
        string s = ShapeColor::str();
        if (s.find("decorator with") == string::npos)
        {
            s += " decorator with Green";
        }
        else if (s.find("Green") == string::npos)
        {
            s = s + " and Green";
        }
        return s;
    }
};

int main(int argc, char **argv)
{
    
    Rectangle rec = Rectangle();
    RedShape red_rec(rec);
    GreenShape green_red_rec(red_rec);

    cout << green_red_rec.str() << endl;
    return 0;
}

