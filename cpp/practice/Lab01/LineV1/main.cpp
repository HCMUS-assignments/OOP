#include "Line.hpp"

int main() {
    Line l1;
    cout << "Line 1: " << l1 << endl;

    Line l2(Point(1, 2), Point(3, 4));
    cout << "Line 2: " << l2 << endl;

    Line l3;
    cout << "Enter line 3: ";
    cin >> l3;
    cout << "Line 3: " << l3 << endl;

    return 0;
}