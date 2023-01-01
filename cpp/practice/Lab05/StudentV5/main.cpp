#include "Student.hpp"

int main() {
    Student s1("Bui", "Thi Thanh", "Ngan");
    Student s2(s1);

    cout << "s1 = " << s1.toString() << endl;
    cout << "s2 = " << s2.toString() << endl;

    return 0;
}