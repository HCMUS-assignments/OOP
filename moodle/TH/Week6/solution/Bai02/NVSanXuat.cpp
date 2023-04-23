#include "NVSanXuat.h"

// constructor
NVSanXuat::NVSanXuat() : NhanVien()
{
    numProduct = 0;
}
NVSanXuat::NVSanXuat(string _id, string _name, string _birthdate, string _address, int _numProduct) : NhanVien(_id, _name, _birthdate, _address)
{
    // cout << "\nConstructor of NVSanXuat is called.\n";
    numProduct = _numProduct;
    assert(numProduct >= 10 && numProduct <= 15);
}

// destructor
NVSanXuat::~NVSanXuat() 
{
    numProduct = 0;
}

// copy constructor
NVSanXuat::NVSanXuat(const NVSanXuat &src)
{
    // cout << "\nCopy constructor of NVSanXuat is called.\n";
    ID = src.ID;
    FullName = src.FullName;
    Birthdate = src.Birthdate;
    Address = src.Address;
    numProduct = src.numProduct;
}

// overloading operator =
NVSanXuat &NVSanXuat::operator=(const NVSanXuat &src)
{
    // cout << "\nOverloading operator = of NVSanXuat is called.\n";
    if (this != &src) {
        ID = src.ID;
        FullName = src.FullName;
        Birthdate = src.Birthdate;
        Address = src.Address;
        numProduct = src.numProduct;
    }
    return *this;
}

// setters
void NVSanXuat::setNumProduct(int _numProduct)
{
    numProduct = _numProduct;
    assert(numProduct >= 10 && numProduct <= 15);

}

// getters
int NVSanXuat::getNumProduct()
{
    return numProduct;
}

// other methods
int NVSanXuat::getSalary()
{
    return numProduct * 50000;
}

void NVSanXuat::enterInfo()
{
    cout << "\nEnter ID: ";
    getline(cin, ID);
    cout << "Enter full name: ";
    getline(cin, FullName);
    cout << "Enter birthdate: ";
    getline(cin, Birthdate);
    cout << "Enter address: ";
    getline(cin, Address);
    cout << "Enter number of products: ";
    cin >> numProduct;

}
void NVSanXuat::printInfo()
{
    cout << "\nID: " << ID << ", Full name: " << FullName 
    << "\nBirthdate: " << Birthdate << ", Address: " << Address 
    << "\nNumber of products: " << numProduct << ", Salary: " << getSalary() << endl;
}

int NVSanXuat::getProduct_Day()
{
    return numProduct;
}

string NVSanXuat::getTypeNV() {
    return "NVSanXuat";
}

int NVSanXuat::getNum() {
    return numProduct;
}