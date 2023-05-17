#include "MyVector.h"

int main() {
    MyVector<int> v;
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.print();
    v.reserve(20);
    v.print();
    return 0;
}