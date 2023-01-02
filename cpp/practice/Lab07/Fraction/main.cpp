#include "Random.hpp"
#include "Fraction.hpp"
#include <vector>

int main() {
    Random r = Random();
    int n = r.Next(225);
    cout << "n: " << n << endl;
    vector <Fraction> v;
    for (int i = 0; i < n; i++) {
        v.push_back(Fraction(r.Next(), r.Next()));
        cout << v[i] << " ";
    }
    cout << endl;

    int m1 = r.Next();
    cout << "m1: " << m1 << endl;
    int m2 = r.Next(22);
    cout << "m2: " << m2 << endl;

    try {
        if (m1 >= n) {
            throw "index out of range";
        } else {
            cout << "Value at index m1: " << v[m1] << endl;
            cout << "Inverse of value at index m1: " << v[m1].getInverse() << endl;
            if ( ! v[m1].isOptimized()) {
                v[m1].optimize();
                cout << "Optimized value at index m1: " << v[m1] << endl;
            }
        }
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    try {
        if (m2 >= n) {
            throw "index out of range";
        } else {
            cout << "Value at index m2: " << v[m2] << endl;
            cout << "Inverse of value at index m2: " << v[m2].getInverse() << endl;
            if ( ! v[m2].isOptimized()) {
                v[m2].optimize();
                cout << "Optimized value at index m2: " << v[m2] << endl;
            }
        }
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 225;

}