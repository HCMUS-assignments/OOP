#include "Rectangle.hpp"

int main() {
    Rectangle r1;
    cin >> r1;
    cout << r1;
    cout << "Area: " << r1.getArea() << endl;
    cout << "Perimeter: " << r1.getPerimeter() << endl;
    return 0;
}