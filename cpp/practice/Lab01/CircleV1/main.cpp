#include "Circle.hpp"

int main() {
    Circle c1;
    cout << c1 << endl;

    Circle c2(5, Point(1, 2));
    cout << c2 << endl;

    Circle c3;
    cin >> c3;
    cout << c3 << endl;

    cout << "Radius of c3 = " << c3.getRadius() << endl;
    cout << "Center of c3 = " << c3.getCenter() << endl;
    cout << "Area of c3 = " << c3.getArea() << endl;
    cout << "Perimeter of c3 = " << c3.getPerimeter() << endl;

    return 0;
}