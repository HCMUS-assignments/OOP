#include "Date.hpp"

Date::Date() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    _year = 1900 + ltm->tm_year;
    _month = 1 + ltm->tm_mon;
    _day = ltm->tm_mday;
}

Date::Date(int year, int month, int day) {
    if (IsValidDate(year, month, day)) {
        _year = year;
        _month = month;
        _day = day;
    } else {
        cout << "Invalid date" << endl;
    }
}

Date::Date(const Date& d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

Date::~Date() {
}

int Date::Year() const {
    return _year;
}

int Date::Month() const {
    return _month;
}

int Date::Day() const {
    return _day;
}

void Date::SetYear(int year) {
    if (year < 0) {
        cout << "Year must be greater than 0" << endl;
    }
    _year = year;
}

void Date::SetMonth(int month) {
    if (month < 1 || month > 12) {
        cout << "Month must be between 1 and 12" << endl;
    }
    _month = month;
}

void Date::SetDay(int day) {
    if (day < 1 || day > 31) {
        cout << "Day must be between 1 and 31" << endl;
    }
    _day = day;
}

bool Date::IsLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

bool Date::IsValidDate(int year, int month, int day) {
    if (year < 0) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        if (IsLeapYear(year)) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        }
    }
    return true;
}

string Date::ToString() const {
    stringstream ss;
    if (_day < 10) {
        ss << "0";
    }
    ss << _day << "/";
    if (_month < 10) {
        ss << "0";
    }
    ss << _month << "/" << _year;

    return ss.str();
}

istream& operator >> (istream& is, Date* d) {
    int year, month, day;
    cout << "Enter year, month, day: ";
    is >> year >> month >> day;
    while (Date::IsValidDate(year, month, day) == false) {
        cout << "Invalid date. Please enter again: ";
        is >> year >> month >> day;
    }
    d->SetYear(year);
    d->SetMonth(month);
    d->SetDay(day);

    return is;
}

ostream& operator << (ostream& os, const Date* d) {
    os << d->ToString();
    return os;
}

