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

    Student G(211221121, 9.5);
    Student H(G);
    Student K;
    K = G;
    G.print();
    H.print();
    K.print();

    return 225;
}