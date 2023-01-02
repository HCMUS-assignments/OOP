#ifndef _TIME_HPP
#define _TIME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

class Time {
private:
    int _hour;
    int _min;
    int _sec;

public:

    // constructor
    Time();
    Time(int hour, int min, int sec);
    Time(const Time& t);

    // destructor
    ~Time();

    // getters
    int Hour() const;
    int Min() const;
    int Sec() const;

    // setters
    void SetHour(int hour);
    void SetMin(int min);
    void SetSec(int sec);

    // methods
    static bool IsValidTime(int hour, int min, int sec);

    string toString() const;

    // overload operators
    friend istream& operator>>(istream& is, Time* t);
    friend ostream& operator<<(ostream& os, const Time* t);
    
};

#endif