#include <iostream>
#include <string>

using namespace std;

class Shape {
    public:
    virtual double area() = 0;
    virtual double area() const = 0;
};

class Cicle : public Shape {
    public:
    mutable double radius;
    Cicle(double r)
    {
        radius = r;
    }
    double area() const override
    {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
    public:
    mutable double side;
    Square(double s)
    {
        side = s;
    }
    double area() const override
    {
        return side * side;
    }
};

class Rectangle : public Shape {
    public:
    mutable double length;
    mutable double width;
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    double area() const override
    {
        return length * width;
    }
};

class Triangle : public Shape {
    public:
    mutable double base;
    mutable double height;
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }
    double area() const override
    {
        return 0.5 * base * height;
    }
};