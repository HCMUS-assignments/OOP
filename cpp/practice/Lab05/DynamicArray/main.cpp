#include "DynamicArray.hpp"

int main() {
    DynamicArray d1 = DynamicArray();
    d1.PushBack(1);
    d1.PushBack(2);
    d1.PushBack(3);
    d1.PushBack(4);
    d1.PushBack(5);


    DynamicArray d2 = DynamicArray(d1);
    d2.PushBack(6);


    cout << "d1 = " << d1.toString() << endl;
    cout << "d2 = " << d2.toString() << endl;

    return 225;
}