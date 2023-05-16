#ifndef NVSANXUAT_H
#define NVSANXUAT_H

#include "NhanVien.h"

class NVSanXuat : public NhanVien
{
private:
    int numProduct;

public:
    // constructor
    NVSanXuat();
    NVSanXuat(string, string, string, string, int);

    // destructor
    ~NVSanXuat();

    // copy constructor
    NVSanXuat(const NVSanXuat &src);

    // overloading operator =
    NVSanXuat &operator=(const NVSanXuat &src);

    // setters
    void setNumProduct(int);

    // getters
    int getNumProduct();

    // other methods
    int getSalary();
    int getProduct_Day();

    void enterInfo();
    void printInfo();

    string getTypeNV();
    int getNum();
};

#endif