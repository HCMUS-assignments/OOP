#include "Triangle.hpp"

int main() {
    Point a = Point(1, 1);
    Point b = Point(11, 1);
    Point c = Point(6, 10);
    Triangle t = Triangle(a, b, c);
    Triangle t2 = Triangle(t);

    cout << t.getArea() << endl;
    cout << t2.getArea() << endl;

    cout << t.toString() << endl;
    cout << t2.toString();
    
    return 0;
}