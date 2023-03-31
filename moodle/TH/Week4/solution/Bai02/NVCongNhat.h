#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H

#include "NhanVien.h"

class NVCongNhat : public NhanVien
{
private:
    int numDay;

public:
    // constructor
    NVCongNhat();
    NVCongNhat(string, string, string, string, int);

    // destructor
    ~NVCongNhat();

    // copy constructor
    NVCongNhat(const NVCongNhat &src);

    // overloading operator =

    NVCongNhat &operator=(const NVCongNhat &src);

    // setters
    void setNumDay(int);

    // getters
    int getNumDay();

    // other methods
    int getSalary();
    int getProduct_Day();

    void enterInfo();
    void printInfo();
};

#endif