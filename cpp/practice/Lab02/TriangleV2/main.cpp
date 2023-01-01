#include "Triangle.hpp"

int main() {
    Point *a = new Point(1,1);
    Point *b = new Point(1,2);
    Point *c = new Point(4,2);
    Triangle *t = new Triangle(a, b, c);
    cout << "here " << endl;
    cout << t->getArea() << endl;
    cout << t->getPerimeter() << endl;
    cin >> t;
    cout << t << endl;
    cout << t->getArea() << endl;
    cout << t->getPerimeter() << endl;
    
    return 0;
}