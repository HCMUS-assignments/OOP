#include "Rectangle.hpp"

int Point::instanceCount = 0;
int Rectangle::InstanceCount = 0;

int main () {
    Rectangle *r1 = new Rectangle();
    Rectangle *r2 = new Rectangle(new Point(1, 1), new Point(2, 2));

    cout << "r1 area: " << r1->CalcArea() << endl;
    cout << "r1 perimeter: " << r1->CalcPerimeter() << endl;
    cout << "r2 area: " << r2->CalcArea() << endl;
    cout << "r2 perimeter: " << r2->CalcPerimeter() << endl;

    Rectangle *r3 = new Rectangle();
    r3->SetTopLeft(new Point(3, 3));
    r3->SetBottomRight(new Point(4, 4));

    cout << "r3 area: " << r3->CalcArea() << endl;
    cout << "r3 perimeter: " << r3->CalcPerimeter() << endl;

    cout << "Point's instance: " << Point::instanceCount << endl;
    cout << "Rectangle's instance: " << Rectangle::InstanceCount << endl;

    return 225;
}