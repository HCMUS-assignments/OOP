#include "Line.hpp"

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Line l1(p1, p2);
    Line l2(l1);
    cout << l1.toString() << endl;
    cout << l2.toString() << endl;

    // test overload operator
    cout << "Enter a line: " << endl;
    cin >> &l1;
    cout << &l1 << endl;
    

    return 0;
}