#include "DynamicArray.hpp"

int main() {
    DynamicArray *arr;
    arr = new DynamicArray();
    arr->PushBack(1);
    arr->PushBack(2);
    arr->PushBack(3);
    arr->PushBack(4);

    for (int i = 0; i < 4; i++) {
        cout << arr->GetAt(i) << endl;
    }

    arr = new DynamicArray(10);

    for (int i = 0; i < 10; i++) {
        arr->PushBack(i);
    }

    cout << "Length: " << arr->GetLen() << endl;

    return 225;
}