#include "Fraction.hpp"

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    cout << f1 << endl;
    cout << f2 << endl;

    cin >> f1;
    cin >> f2;

    Fraction f3 = f1 + f2;
    cout << f3 << endl;
    cout << "num: " << f3.getNum() << " den: " << f3.getDen() << endl;

    f3 = f1 - f2;
    cout << f3 << endl;

    f3 = f1 * f2;
    cout << f3 << endl;

    f3 = f1 / f2;
    cout << f3 << endl;

    return 0;
}