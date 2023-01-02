#include "Random.hpp"
#include <vector>

int main() {
    Random r = Random();
    int n = r.Next(225);
    vector<int> v;
    cout << "n: " << n << endl;
    for (int i = 0; i < n; i++) {
        v.push_back(r.Next());
        cout << v[i] << " ";
    }
    cout << endl;

    int m = r.Next();
    cout << "m: " << m << endl;

    try {
        if (m >= n) {
            throw "index out of range";
        } else {
            cout << "Value at index m: " << v[m] << endl;
        }
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 225;

}