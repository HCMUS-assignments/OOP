#include "Line.hpp"

int Point::instanceCount = 0;
int Line::InstanceCount = 0;

int main() {
    Point *p1 = new Point(1, 1);
    Point *p2 = new Point(2, 2);
    Line *l1 = new Line(p1, p2);
    cout << "Line length: " << l1->Length() << endl;

    cout << "Point instances: " << Point::instanceCount << endl;
    cout << "Line instances: " << Line::InstanceCount << endl;

    cout << "----------------" << endl;

    Line *l2 = new Line(*l1);
    cout << "Line length: " << l2->Length() << endl;

    cout << "Point instances: " << Point::instanceCount << endl;
    cout << "Line instances: " << Line::InstanceCount << endl;

    return 0;
}

