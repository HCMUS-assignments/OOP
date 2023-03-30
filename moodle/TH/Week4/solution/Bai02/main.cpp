#include "NVCongNhat.h"
#include "NVSanXuat.h"

int main() {
    NVCongNhat nv1;
    nv1.enterInfo();
    nv1.printInfo();

    NVCongNhat nv2("Nguyen Van A", "NV001", "01/01/1990", "Ha Noi", 20);
    nv2.printInfo();

    NVCongNhat nv3(nv2);
    nv3.printInfo();

    NVCongNhat nv4;
    nv4 = nv3;
    nv4.printInfo();

    NVSanXuat nv5;
    fflush(stdin);
    nv5.enterInfo();
    nv5.printInfo();

    NVSanXuat nv6("Nguyen Van B", "NV002", "02/02/1990", "Ha Noi", 100);
    nv6.printInfo();

    NVSanXuat nv7(nv6);
    nv7.printInfo();

    NVSanXuat nv8;
    nv8 = nv7;
    nv8.printInfo();

    return 0;
}