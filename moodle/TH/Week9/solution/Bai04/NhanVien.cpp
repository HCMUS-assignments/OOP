#include "NhanVien.h"

// constructor
NhanVien::NhanVien()
{
    ID = FullName = Birthdate = Address = "";
}
NhanVien::NhanVien(string _id, string _name, string _birthdate, string _address)
{
    // cout << "\nConstructor of NhanVien is called.\n";
    // assertion

    int year = stoi(_birthdate.substr(_birthdate.find_last_of('/') + 1));
    // get curent year
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    // get years old
    int age = currentYear - year;
    // assertion
    assert(age >= 18 && age <= 60);


    FullName = _name;
    ID = _id;
    Birthdate = _birthdate;
    Address = _address;

    assert(ID.length() == 5);

}

// destructor
NhanVien::~NhanVien()
{
    ID = FullName = Birthdate = Address = "";
}

// copy constructor
NhanVien::NhanVien(const NhanVien &src)
{
    // cout << "\nCopy constructor of NhanVien is called.\n";
    FullName = src.FullName;
    ID = src.ID;
    Birthdate = src.Birthdate;
    Address = src.Address;
}

// overloading operator =
NhanVien &NhanVien ::operator=(const NhanVien &src)
{
    // cout << "\nOverloading operator = of NhanVien is called.\n";
    if (this != &src)
    {
        FullName = src.FullName;
        ID = src.ID;
        Birthdate = src.Birthdate;
        Address = src.Address;
    }
    return *this;
}

// setters
void NhanVien::setID(string _id)
{
    ID = _id;
    assert(ID.length() == 5);
}
void NhanVien::setFullName(string _name)
{
    FullName = _name;
}
void NhanVien::setBirthdate(string _birthdate)
{
    int year = stoi(_birthdate.substr(_birthdate.find_last_of('/')));
    // get curent year
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    // get years old
    int age = currentYear - year;
    // assertion
    assert(age >= 18 && age <= 60);

    Birthdate = _birthdate;
}
void NhanVien::setAddress(string _address)
{
    Address = _address;
}

// getters
string NhanVien::getID()
{
    return ID;
}
string NhanVien::getFullName()
{
    return FullName;
}
string NhanVien::getBirthdate()
{
    return Birthdate;
}
string NhanVien::getAddress()
{
    return Address;
}

// other methods
int NhanVien::getSalary()
{
    return 0; // virtual method
}
void NhanVien::enterInfo()
{
    // virtual method
}
void NhanVien::printInfo()
{
    // virtual method
}

int NhanVien ::getProduct_Day()
{
    // virtual method
}
