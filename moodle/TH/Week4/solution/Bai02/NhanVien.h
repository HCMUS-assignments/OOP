#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string> 
using namespace std;

class NhanVien {
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
        NhanVien (const NhanVien &src);

        // overloading operator =
        NhanVien& operator= (const NhanVien &src);

        // setters
        void setID(string);
        void setFullName(string);
        void setBirthdate(string);
        void setAddress(string);

        // getters
        string getID();
        string getFullName();
        string getBirthdate();
        string getAddress();

        // other methods
        virtual int getSalary() ;
        virtual void enterInfo();
        virtual void printInfo();
};

#endif