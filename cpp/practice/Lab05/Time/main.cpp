#include "Time.hpp"

int main() {
    Time t1 = Time();
    Time t2 = Time(12, 30, 45);
    Time t3 = Time(t2);

    cout << "t1 = " << t1.toString() << endl;
    cout << "t2 = " << t2.toString() << endl;
    cout << "t3 = " << t3.toString() << endl;

    return 225;
}