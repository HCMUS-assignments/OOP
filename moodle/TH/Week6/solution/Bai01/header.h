#ifndef SHAPE_H
#define SHAPE_H

#define PI 3.14

#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

struct Point
{
    double X;
    double Y;

    Point() {
        X = 0;
        Y = 0;
    }
    Point (int x, int y) {
        X = x;
        Y = y;
    }
};

class Shape
{
public:
    // constructors
    Shape() ;

    // destructor 
    ~Shape();

    // copy constructor
    Shape(const Shape &other);

    /* area of shape, e.g. area of circle, or retangle */ 
    virtual double area() = 0;

    virtual Shape *Clone() = 0;
    virtual bool IsSelected(Point p) = 0;

    virtual void input() = 0;
    virtual void print() = 0;


    // others
    virtual string getName() = 0;
};

#endif

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
protected:
    Point C;
    double R;

public:
    // constructors
    Circle();
    Circle(Point, double);

    // destructor
    ~Circle();

    // copy constructor
    Circle(const Circle &other);

    // override area() method
    double area();


    bool IsSelected(Point p);
    Shape *Clone();

    void input();
    void print();

    string getName();
};

#endif

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape
{
protected:
    Point X;
    double W, H;

public:
    // constructors
    Rectangle();
    Rectangle(Point, double, double);

    // destructor 
    ~Rectangle();

    // copy constructor
    Rectangle(const Rectangle &other) ;

    // area of rectangle
    double area();

    bool IsSelected(Point p);
    Shape *Clone();

    void input();
    void print();

    // others
    string getName();
};

#endif

#ifndef COMPLEXSHAPE_H
#define COMPLEXSHAPE_H

class ComplexShape : public Shape
{
protected:
    // Các hình thành phần: Circle, rectangle

    int sz;
    Shape **Children;

public:
    // constructors
    ComplexShape();

    // destructor
    ~ComplexShape();

    // copy constructor 
    ComplexShape(const ComplexShape &other);

    // area od complexShape
    double area();

    bool IsSelected(Point);
    Shape *Clone();

    void input();
    void print();
    int circle_Num();
    int rectangle_Num();

    // others
    string getName();
};

#endif
