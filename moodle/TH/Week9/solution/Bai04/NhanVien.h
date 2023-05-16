#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <assert.h>
#include <ctime>
using namespace std;

class NhanVien
{
protected:
    string ID;
    string FullName;
    string Birthdate;
    string Address;

public:
    // constructor
    NhanVien();
    NhanVien(string, string, string, string);

    // destructor
    ~NhanVien();

    // copy constructor
    NhanVien(const NhanVien &src);

    // overloading operator =
    NhanVien &operator=(const NhanVien &src);

    // setters
    virtual void setID(string);
    virtual void setFullName(string);
    virtual void setBirthdate(string);
    virtual void setAddress(string);

    // getters
    virtual string getID();
    virtual string getFullName();
    virtual string getBirthdate();
    virtual string getAddress();

    // other methods
    virtual int getSalary();
    virtual void enterInfo();
    virtual void printInfo();
    virtual int getProduct_Day();

    virtual string getTypeNV() = 0;
    virtual int getNum() = 0;
};

#endif