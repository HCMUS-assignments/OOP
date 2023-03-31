#include "NhanVien.h"

// constructor
NhanVien::NhanVien()
{
    ID = FullName = Birthdate = Address = "";
}
NhanVien::NhanVien(string _name, string _id, string _birthdate, string _address)
{
    // cout << "\nConstructor of NhanVien is called.\n";
    FullName = _name;
    ID = _id;
    Birthdate = _birthdate;
    Address = _address;
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
NhanVien& NhanVien ::operator=(const NhanVien &src)
{
    // cout << "\nOverloading operator = of NhanVien is called.\n";
    if (this != &src) {
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
}
void NhanVien::setFullName(string _name)
{
    FullName = _name;
}
void NhanVien::setBirthdate(string _birthdate)
{
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
    return 0;   // virtual method
}
void NhanVien::enterInfo()
{
    // virtual method
}
void NhanVien::printInfo()
{
    // virtual method
}

int NhanVien :: getProduct_Day() {
    // virtual method
}
