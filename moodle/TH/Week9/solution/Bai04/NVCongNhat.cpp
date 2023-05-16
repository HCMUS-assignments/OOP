#include "NVCongNhat.h"

// constructor
NVCongNhat::NVCongNhat() : NhanVien()
{
    numDay = 0;
}
NVCongNhat::NVCongNhat(string _id, string _name, string _birthdate, string _address, int _numDay) : NhanVien(_id ,_name, _birthdate, _address)
{
    // cout << "\nConstructor of NVCongNhat is called.\n";
    numDay = _numDay;
    assert(numDay >= 22 && numDay <= 26);
}

// destructor
NVCongNhat::~NVCongNhat() 
{
    numDay = 0;
}

// copy constructor
NVCongNhat::NVCongNhat(const NVCongNhat &src)
{
    // cout << "\nCopy constructor of NVCongNhat is called.\n";
    ID = src.ID;
    FullName = src.FullName;
    Birthdate = src.Birthdate;
    Address = src.Address;
    numDay = src.numDay;
}

// overloading operator =
NVCongNhat &NVCongNhat::operator=(const NVCongNhat &src)
{
    // cout << "\nOverloading operator = of NVCongNhat is called.\n";
    if (this != &src) {
        ID = src.ID;
        FullName = src.FullName;
        Birthdate = src.Birthdate;
        Address = src.Address;
        numDay = src.numDay;
    }
    return *this;
}

// setters
void NVCongNhat::setNumDay(int _numDay)
{
    numDay = _numDay;
    assert(numDay >= 22 && numDay <= 26);
}

// getters
int NVCongNhat::getNumDay()
{
    return numDay;
}

// other methods
int NVCongNhat::getSalary()
{
    return numDay * 500000;
}

void NVCongNhat::enterInfo()
{
    cout << "\nEnter ID: ";
    getline(cin, ID);
    cout << "Enter full name: ";
    getline(cin, FullName);
    cout << "Enter birthdate: ";
    getline(cin, Birthdate);
    cout << "Enter address: ";
    getline(cin, Address);
    cout << "Enter number of days: ";
    cin >> numDay;

}
void NVCongNhat::printInfo()
{
    cout << "\nID: " << ID << ", Full name: " << FullName 
    << "\nBirthdate: " << Birthdate << ", Address: " << Address 
    << "\nNumber of days: " << numDay << ", Salary: " << getSalary() << endl;
}

int NVCongNhat :: getProduct_Day()
{
    return numDay;
}

string NVCongNhat::getTypeNV() {
    return "NVCongNhat";
}


int NVCongNhat::getNum() {
    return numDay;
}