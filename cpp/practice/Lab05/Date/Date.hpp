#ifndef _DATE_HPP
#define _DATE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

class Date {
    private:
        int _year;
        int _month;
        int _day;

    public:
        // constructor
        Date();
        Date(int year, int month, int day);
        Date(const Date& d);

        // destructor
        ~Date();

        // getters
        int Year() const;
        int Month() const;
        int Day() const;

        // setters
        void SetYear(int year);
        void SetMonth(int month);
        void SetDay(int day);

        // methods
        static bool IsLeapYear(int year);
        static bool IsValidDate(int year, int month, int day);

        string ToString() const;

};

#endif