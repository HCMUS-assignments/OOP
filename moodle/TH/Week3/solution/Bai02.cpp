// phân số, mảng các phân số
#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo
{
private:
    int _t;
    int _m;

public:
    // default constructor
    PhanSo();

    // parameters constructor
    PhanSo(int, int);

    // destructor
    ~PhanSo();

    // getters
    int tu();
    int mau();

    // setters
    void setTu(int);
    void setMau(int);

    // methods
    // nhập phân số
    friend istream &operator>>(istream &, PhanSo &);

    // Xuất phân số
    friend ostream &operator<<(ostream &, PhanSo src);

    //  Tối giản phân số
    void ToiGian();

    // Cộng, trừ, nhân, chia phân số
    PhanSo &operator+(const PhanSo);
    PhanSo &operator-(const PhanSo);
    PhanSo &operator*(const PhanSo);
    PhanSo &operator/(const PhanSo);

    PhanSo &operator+=(const PhanSo);
    PhanSo &operator-=(const PhanSo);
    PhanSo &operator*=(const PhanSo);
    PhanSo &operator/=(const PhanSo);
};

#endif

// define methods

// default constructor
PhanSo::PhanSo()
{
    _t = 0;
    _m = 1;
}

// parameters constructor
PhanSo::PhanSo(int tu, int mau)
{
    _t = tu;
    _m = mau;
}

// destructor
PhanSo::~PhanSo()
{
}

// getters
int PhanSo::tu()
{
    return _t;
}
int PhanSo::mau()
{
    return _m;
}

// setters
void PhanSo ::setTu(int tu)
{
    _t = tu;
}
void PhanSo::setMau(int mau)
{
    if (mau == 0) {
        cout << "\nMau so phai khac 0 ... \n";
    }
}

// methods
// nhập phân số
istream &operator>>(istream &is, PhanSo &src)
{
    cout << "\n Nhap phan so (tu mau): ";
    is >> src._t >> src._m;
    if (is.fail()) {
        cerr << "\nNhap sai...\n";
    } 
    return is;
}

// Xuất phân số
ostream &operator<<(ostream &os, PhanSo src)
{
    os << src._t << "/" << src._m;
    return os;
}

//  Tối giản phân số
void PhanSo::ToiGian()
{
    // tìm uc của tử và mẫu nếu có

    // chia cả tử và mẫu cho uc

}

// Cộng, trừ, nhân, chia phân số
PhanSo &PhanSo ::operator+(const PhanSo src)
{
    _t = _t * src._m + src._t * _m;
    _m = _m * src._m;
    ToiGian();
    return *this;
}
PhanSo &PhanSo ::operator-(const PhanSo src)
{
    _t = _t * src._m - src._t * _m;
    _m = _m * src._m;
    ToiGian();
    return *this;
}
PhanSo &PhanSo ::operator*(const PhanSo src)
{
    _t = _t * src._t;
    _m = _m * src._m;
    ToiGian();
    return *this;
}
PhanSo &PhanSo ::operator/(const PhanSo src)
{
    
}

PhanSo &PhanSo ::operator+=(const PhanSo src)
{
}
PhanSo &PhanSo ::operator-=(const PhanSo src)
{
}
PhanSo &PhanSo ::operator*=(const PhanSo src)
{
}
PhanSo &PhanSo ::operator/=(const PhanSo src)
{
}


// Mảng phân số
#ifndef MANGPHANSO_H
#define MANGPHANSO_H

class MANGPHANSO {
    private:
        PhanSo *arrPS;
        int size;

    public:
    // nhập mảng phân số

    // xuất mảng phân số

    // tính tổng của các mảng phân số

    // sắp xếp mảng phân số tăng dần

    // ghi mảng phân số lên file

    // đọc mảng phân số từ file, sau đó xuất ra màn hình
};

#endif

int main() {

}