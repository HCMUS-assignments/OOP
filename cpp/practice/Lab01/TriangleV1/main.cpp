#include "Triangle.hpp"

int main() {
    Triangle t1;
    cin >> t1;
    cout << "The area of the triangle is " << t1.getArea() << endl;
    cout << "The perimeter of the triangle is " << t1.getPerimeter() << endl;
    return 0;
}