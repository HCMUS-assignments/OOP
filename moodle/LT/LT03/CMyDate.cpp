#include "CMyDate.h"

// constructor
CMyDate::CMyDate()
{
    d = 0;
    m = 0;
    y = 0;
}
CMyDate::CMyDate(int day, int month, int year)
{
    d = day;
    m = month;
    y = year;
}
CMyDate::CMyDate(string line)
{
    stringstream ss(line);
    string temp;
    getline(ss, temp, '/');
    d = stoi(temp);
    getline(ss, temp, '/');
    m = stoi(temp);
    y = stoi(ss.str());
}

// operator
bool CMyDate::operator==(const CMyDate &another)
{
    if (d == another.d && m == another.m && y == another.y)
        return true;
    return false;
}
bool CMyDate::operator!=(const CMyDate &another)
{
    if (d != another.d || m != another.m || y != another.y)
        return true;
    return false;
}
bool CMyDate::operator>(const CMyDate &another)
{
    if (y > another.y)
        return true;
    else if (y == another.y)
    {
        if (m > another.m)
            return true;
        else if (m == another.m)
        {
            if (d > another.d)
                return true;
        }
    }
    return false;
}
bool CMyDate::operator>=(const CMyDate &another)
{
    if (y > another.y)
        return true;
    else if (y == another.y)
    {
        if (m > another.m)
            return true;
        else if (m == another.m)
        {
            if (d >= another.d)
                return true;
        }
    }
    return false;
}
bool CMyDate::operator<(const CMyDate &another)
{
    if (y < another.y)
        return true;
    else if (y == another.y)
    {
        if (m < another.m)
            return true;
        else if (m == another.m)
        {
            if (d < another.d)
                return true;
        }
    }
    return false;
}
bool CMyDate::operator<=(const CMyDate &another)
{
    if (y < another.y)
        return true;
    else if (y == another.y)
    {
        if (m < another.m)
            return true;
        else if (m == another.m)
        {
            if (d <= another.d)
                return true;
        }
    }
    return false;
}

// operator =
CMyDate &CMyDate::operator=(const CMyDate &another)
{
    if (this == &another)
        return *this;
    d = another.d;
    m = another.m;
    y = another.y;
    return *this;
}

ostream &operator<<(ostream &os, CMyDate &another)
{
    os << another.d << "/" << another.m << "/" << another.y;
    return os;
}

string CMyDate::toStr()
{
    stringstream ss;
    ss << d << "/" << m << "/" << y;
    return ss.str();
}
