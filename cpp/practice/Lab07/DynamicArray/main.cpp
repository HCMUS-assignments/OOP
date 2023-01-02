#include "DynamicArray.hpp"

int main() {
    // test overloading operators
    DynamicArray *da = new DynamicArray();
    cin >> da;
    cout << da << endl;

    int n;
    cout << "Enter n: ";
    cin >> n;

    int value = da->GetAt(n);
    cout << "Value at index " << n << " is " << value << endl;

    return 225;
}