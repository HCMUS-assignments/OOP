#include "Date.hpp"

int main() {
    Date d1;
    cout << d1.ToString() << endl;

    Date d3(2018, 2, 28);
    cout << d3.ToString() << endl;

    Date d4(d3) ;
    cout << d4.ToString() << endl;

    Date d2(2018, 2, 29);
    cout << d2.ToString() << endl;

    return 0;
}