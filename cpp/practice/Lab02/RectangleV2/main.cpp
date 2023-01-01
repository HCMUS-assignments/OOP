#include "Rectangle.hpp"

int main() {
    Rectangle *r1 = new Rectangle();
    cout << "Rectangle 1: " << r1 << endl;

    Rectangle *r2 = new Rectangle();
    Point *topLeft = new Point(1,1);
    Point *bottomRight = new Point(10,10);
    cin >> r2;
    cout << "Rectangle 2: " << r2 << endl;
    cout << "top left: " << r2->getTopLeft() << endl;
    cout << "bottom right: " << r2->getBottomRight() << endl;
    cout << "area: " << r2->getArea() << endl;
    cout << "perimeter: " << r2->getPerimeter() << endl;

    return 0;
}