#ifndef CEBOOK_H
#define CEBOOK_H

#include "CMyDate.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CEbook {
    protected:
        string ISBN;    // mã sách
        string name;    // tên sách
        string author;  // tên tác giả
        CMyDate date;   // ngày xuất bản
        string kind;    // thể loại
        string publisher;   // nhà xuất bản
        double price;   // giá bán

    public:
        // constructors
        CEbook();
        CEbook(string, string, string, CMyDate, string, string, double);

        // copy constructor
        CEbook(const CEbook&);

        // operator =
        CEbook& operator=(const CEbook&);

        // other methods
        // getters 
        string getISBN();
        string getName();
        double getPrice();
        CMyDate getDate();

        // operators
        bool operator>(const CEbook&);
        bool operator>=(const CEbook&);
        bool operator<(const CEbook&);
        bool operator<=(const CEbook&);

        // input/output
        friend ifstream& operator>>(ifstream&, CEbook&);
        friend ofstream& operator<<(ofstream&, CEbook&);
};

#endif