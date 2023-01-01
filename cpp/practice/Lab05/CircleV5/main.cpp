#include "Circle.hpp"

int main() {
    Circle c1(1.0, Point(0, 0));
    Circle c2(2.0, Point(1, 1));
    Circle c3(3.0, Point(2, 2));

    Circle c4(c1);
    Circle c5(c2);
    Circle c6(c3);

    cout << "c1 = " << c1.toString() << endl;
    cout << "c2 = " << c2.toString() << endl;
    cout << "c3 = " << c3.toString() << endl;
    cout << "c4 = " << c4.toString() << endl;
    cout << "c5 = " << c5.toString() << endl;
    cout << "c6 = " << c6.toString() << endl;
    

    return 0;
}