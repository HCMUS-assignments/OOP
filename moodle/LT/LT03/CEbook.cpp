#include "CEbook.h"

// constructors
CEbook::CEbook()
{
    ISBN = "";
    name = "";
    author = "";
    kind = "";
    publisher = "";
    price = 0;
}
CEbook::CEbook(string _isbn, string _name, string _author, CMyDate _date, string _kind, string _publisher, double _price)
{
    ISBN = _isbn;
    name = _name;
    author = _author;
    date = _date;
    kind = _kind;
    publisher = _publisher;
    price = _price;
}

// copy constructor
CEbook::CEbook(const CEbook &another)
{
    ISBN = another.ISBN;
    name = another.name;
    author = another.author;
    date = another.date;
    kind = another.kind;
    publisher = another.publisher;
    price = another.price;
}

// operator =
CEbook &CEbook::operator=(const CEbook &another)
{
    if (this != &another)
    {
        ISBN = another.ISBN;
        name = another.name;
        author = another.author;
        date = another.date;
        kind = another.kind;
        publisher = another.publisher;
        price = another.price;
    }
    return *this;
}

// other methods

// getters
string CEbook::getISBN()
{
    return ISBN;
}
string CEbook::getName()
{
    return name;
}
double CEbook::getPrice()
{
    return price;
}
string CEbook::getStrDate()
{
    return date.toStr();
}
CMyDate CEbook::getDate()
{
    return date;
}

// operators
bool CEbook::operator>(const CEbook &another)
{
    if (price > another.price)
        return true;
    return false;
}
bool CEbook::operator>=(const CEbook &another)
{
    if (price >= another.price)
        return true;
    return false;
}
bool CEbook::operator<(const CEbook &another)
{
    if (price < another.price)
        return true;
    return false;
}
bool CEbook::operator<=(const CEbook &another)
{
    if (price <= another.price)
        return true;
    return false;
}

// input/output
ifstream &operator>>(ifstream &fin, CEbook &src)
{
    string line;
    getline(fin, line);
    src.ISBN = line;
    getline(fin, line);
    src.name = line;
    getline(fin, line);
    src.author = line;
    getline(fin, line);
    src.date = CMyDate(line);
    getline(fin, line);
    src.kind = line;

    getline(fin, line);
    src.publisher = line;
    getline(fin, line);
    src.price = stod(line);
    cout << src.ISBN << " | " << src.name << " | " << src.author << " | " << src.date << " | " << src.kind << " | " << src.publisher << " | " << src.price << endl;

    return fin;
}
ofstream &operator<<(ofstream &fout, CEbook &src)
{
    fout << src.ISBN << " | " << src.name << " | " << src.author << " | " << src.date << " | " << src.kind << " | " << src.publisher << " | " << src.price << endl;
    return fout;
}
