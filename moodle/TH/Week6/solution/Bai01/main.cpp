#include "header.h"

int main() {
    cout << "start...\n";
    ComplexShape *temp = new ComplexShape();
    cout << "end ...\n";
    temp->input();
    cout << "input ...\n";
    temp->print();
    cout << "So luong hinh tron: " << temp->circle_Num() << endl;
    cout << "So luong hinh chu nhat: " << temp->rectangle_Num() << endl;
    cout << "Dien tich cac hinh la: " << temp->area() << endl;

    Point p1(2,2);
    Point p2(9,2);
    cout << "Is selected (2,2): " << temp->IsSelected(p1) << endl;
    cout << "Is selected (9,2): " << temp->IsSelected(p2) << endl;


    return 225;
}