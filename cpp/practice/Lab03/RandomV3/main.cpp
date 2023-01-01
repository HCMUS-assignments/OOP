#include "Random.hpp"

int main() {
    Random r;
    cout << r.Next() << endl;
    cout << r.Next(225) << endl;
    return 0;
}