#ifndef CMYDATE_H
#define CMYDATE_H

#include <iostream>
#include <sstream>
using namespace std;

class CMyDate {
    protected:
        int d;
        int m;
        int y;
    public:
        // constructor
        CMyDate();
        CMyDate(int, int, int);
        CMyDate(string);

        // operator =
        CMyDate& operator=(const CMyDate&);

        // operator
        bool operator==(const CMyDate&);
        bool operator!=(const CMyDate&);
        bool operator>(const CMyDate&);
        bool operator>=(const CMyDate&);
        bool operator<(const CMyDate&);
        bool operator<=(const CMyDate&);

        friend ostream& operator<<(ostream&, CMyDate&);

        string toStr();

};

#endif