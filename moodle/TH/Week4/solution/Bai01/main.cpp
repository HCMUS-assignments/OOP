#include "Student.h"

int main() {
    Person A;
    Person C(211221121);
    Person D (C);
    A.print();
    C.print();
    D.print();

    Person E = D;
    E.print();

    return 225;
}