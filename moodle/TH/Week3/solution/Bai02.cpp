// phân số, mảng các phân số
#ifndef Fraction_H
#define Fraction_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Fraction
{
private:
    int _t;
    int _m;

public:
    // default constructor
    Fraction();

    // parameters constructor
    Fraction(int, int);

    // destructor
    ~Fraction();

    // getters
    int tu();
    int mau();

    // setters
    void setTu(int);
    void setMau(int);

    // methods
    // nhập phân số
    friend istream &operator>>(istream &, Fraction &);

    // Xuất phân số
    friend ostream &operator<<(ostream &, Fraction src);

    //  Tối giản phân số
    void ToiGian();

    // Cộng, trừ, nhân, chia phân số
    Fraction &operator+(const Fraction);
    Fraction &operator-(const Fraction);
    Fraction &operator*(const Fraction);
    Fraction &operator/(const Fraction);

    Fraction &operator+=(const Fraction);
    Fraction &operator-=(const Fraction);
    Fraction &operator*=(const Fraction);
    Fraction &operator/=(const Fraction);

    // overloading operator>
    bool operator> (const Fraction dest);

    // xuất phân số ra file
    friend ofstream& operator<< (ofstream& fout, Fraction src);
};

#endif

// define methods

// default constructor
Fraction::Fraction()
{
    _t = 0;
    _m = 1;
}

// parameters constructor
Fraction::Fraction(int tu, int mau)
{
    _t = tu;
    _m = mau;
}

// destructor
Fraction::~Fraction()
{
}

// getters
int Fraction::tu()
{
    return _t;
}
int Fraction::mau()
{
    return _m;
}

// setters
void Fraction ::setTu(int tu)
{
    _t = tu;
}
void Fraction::setMau(int mau)
{
    if (mau == 0)
    {
        cout << "\nMau so phai khac 0 ... \n";
        return;
    }
    _m = mau;
}

// methods
// nhập phân số
istream &operator>>(istream &is, Fraction &src)
{
    cout << "\n Nhap phan so (tu/mau): ";
    // tách chuỗi nhập vào thành 2 phần tử
    string str;
    getline(is, str, '/');
    src._t = stoi(str);
    getline(is, str);
    src._m = stoi(str);

    return is;
}

// Xuất phân số
ostream &operator<<(ostream &os, Fraction src)
{

    if (src._t < 0 && src._m < 0 || src._t > 0 && src._m < 0)
    {
        src._t *= -1;
        src._m *= -1;
    }
    if (src._t == 0)
    {
        os << "0";
        return os;
    }

    if (src._m == 1)
    {
        os << src._t;
        return os;
    }
    os << src._t << "/" << src._m;
    return os;
}

// hàm tìm ucln
int UCLN(int a, int b)
{
    if (a == 0 || b == 0) return 1;
    if (a < 0)
    {
        a *= -1;
    }
    if (b < 0)
    {
        b *= -1;
    }

    if (a > b)
    {
        if (a % b == 0)
        {
            return b;
        }
        else
        {
            return UCLN(b, a % b);
        }
    }
    else
    {
        if (b % a == 0)
        {
            return a;
        }
        else
        {
            return UCLN(a, b % a);
        }
    }
}

//  Tối giản phân số
void Fraction::ToiGian()
{
    // tìm uc của tử và mẫu nếu có
    int uc = UCLN(_t, _m);

    // chia cả tử và mẫu cho uc
    _t = _t / uc;
    _m = _m / uc;
}

// Cộng, trừ, nhân, chia phân số
Fraction &Fraction ::operator+(const Fraction src)
{
    Fraction *temp = new Fraction();
    temp->_t = _t * src._m + src._t * _m;
    temp->_m = _m * src._m;
    temp->ToiGian();

    return *temp;
}
Fraction &Fraction ::operator-(const Fraction src)
{
    Fraction *temp = new Fraction();
    temp->_t = _t * src._m - src._t * _m;
    temp->_m = _m * src._m;
    temp->ToiGian();
    return *temp;
}
Fraction &Fraction ::operator*(const Fraction src)
{
    Fraction *temp = new Fraction();
    temp->_t = _t * src._t;
    temp->_m = _m * src._m;
    temp->ToiGian();
    return *temp;
}
Fraction &Fraction ::operator/(const Fraction src)
{
    Fraction *temp = new Fraction();
    temp->_t = _t * src._m;
    temp->_m = _m * src._t;
    temp->ToiGian();
    return *temp;
}

Fraction &Fraction ::operator+=(const Fraction src)
{
    _t = _t * src._m + src._t * _m;
    _m = _m * src._m;
    ToiGian();
    return *this;
}
Fraction &Fraction ::operator-=(const Fraction src)
{
    _t = _t * src._m - src._t * _m;
    _m = _m * src._m;
    ToiGian();
    return *this;
}
Fraction &Fraction ::operator*=(const Fraction src)
{
    _t = _t * src._t;
    _m = _m * src._m;
    ToiGian();
    return *this;
}
Fraction &Fraction ::operator/=(const Fraction src)
{
    _t = _t * src._m;
    _m = _m * src._t;
    ToiGian();
    return *this;
}

// overloading operator>
bool Fraction::operator> (const Fraction dest) {
    int bc = _m * dest._m / (UCLN(_m, dest._m));
    if (_t * bc/_m > dest._t * bc / dest._m) {
        return true;
    } else {
        return false;
    }
}

ofstream& operator<< (ofstream& fout, Fraction src) {
    string str = to_string(src.tu()) + "/" + to_string(src.mau());
    fout << str;
    return fout;
}


// Mảng phân số
#ifndef LISTFRACTION_H
#define LISTFRACTION_H

class ListFraction
{
private:
    Fraction *list_of_fraction;
    int size;

public:
    // constructor
    ListFraction();
    ListFraction(int sz);

    // destructor
    ~ListFraction();

    // overload operator =
    ListFraction &operator=(const ListFraction &src);

    // copy constructor
    ListFraction(const ListFraction &src);

    // nhập mảng phân số
    friend istream &operator>>(istream &is, ListFraction &src);

    // xuất mảng phân số
    friend ostream &operator<<(ostream &os, ListFraction src);

    // tính tổng của mảng phân số
    Fraction sum();

    // sắp xếp mảng phân số tăng dần
    void sortAsc();

    // ghi mảng phân số lên file
    friend ofstream &operator<<(ofstream &fout, ListFraction src);

    // đọc mảng phân số từ file, sau đó xuất ra màn hình
    friend ifstream &operator>>(ifstream &fin, ListFraction &src);
};

#endif

// define
ListFraction::ListFraction()
{
    list_of_fraction = NULL;
    size = 0;
}
ListFraction::ListFraction(int sz)
{
    size = sz;
    list_of_fraction = new Fraction[sz * sizeof(Fraction)];
}

ListFraction::~ListFraction()
{
    delete[] list_of_fraction;
}
// overloading operator=
ListFraction &ListFraction::operator=(const ListFraction &src)
{
    if (this == &src)
    {
        return *this;
    }
    size = src.size;
    list_of_fraction = new Fraction[size * sizeof(Fraction)];
    for (int i = 0; i < size; i++)
    {
        list_of_fraction[i] = src.list_of_fraction[i];
    }
}
// copy constructor
ListFraction::ListFraction(const ListFraction &src)
{
    size = src.size;
    list_of_fraction = new Fraction[size * sizeof(Fraction)];
    for (int i = 0; i < size; i++)
    {
        list_of_fraction[i] = src.list_of_fraction[i];
    }
}

// nhập mảng phân số
istream &operator>>(istream &is, ListFraction &src) {
    if (src.size > 0 && src.list_of_fraction != NULL) {
        cout << "Nhap " << src.size << " phan so: ";
        for (int i = 0; i < src.size; i++) {
            is >> src.list_of_fraction[i];
        }
    } else {
        cout << "Nhap so phan so cua mang: ";
        is >> src.size;
        src.list_of_fraction = new Fraction[src.size * sizeof(Fraction)];
        for (int i = 0; i < src.size; i++) {
            is >> src.list_of_fraction[i];
        }
    }
    return is;
}

// xuất mảng phân số
ostream &operator<<(ostream &os, ListFraction src) {
    if (src.size == 0 && src.list_of_fraction == NULL) {
        cout << "\nKhong co phan so nao ... \n";
        return os;
    }
    cout << "\nMang phan so: ";
    for (int i = 0; i < src.size; i++) {
        os << src.list_of_fraction[i] << "  ";
    }
    return os;
}

// tính tổng của mảng phân số
Fraction ListFraction::sum() {
    Fraction sum;
    for (int i = 0; i < size; i++) {
        sum += list_of_fraction[i];
    }
    return sum;
}

// sắp xếp mảng phân số tăng dần
void ListFraction :: sortAsc() {
    if (list_of_fraction == NULL) {
        cout << "\nKhong co phan so de sap xep ...\n";
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list_of_fraction[i] > list_of_fraction[j]) {
                Fraction temp(list_of_fraction[i]);
                list_of_fraction[i] = list_of_fraction[j];
                list_of_fraction[j] = temp;
            }
        }
    }

}

// ghi mảng phân số lên file
ofstream &operator<<(ofstream &fout, ListFraction src) {
    if (src.list_of_fraction == NULL) {
        cout << "\nMang phan so null ... \n";
        return fout;
    }

    for (int i = 0; i < src.size; i++) {
        fout << src.list_of_fraction[i];
        fout << endl;
    }
    return fout;
}

// đọc mảng phân số từ file, sau đó xuất ra màn hình
ifstream &operator>>(ifstream &fin, ListFraction &src) {
    string line;
    getline(fin, line);
    src.size = atoi(line.c_str());
    // cout << "size: " << src.size << endl;
    src.list_of_fraction = new Fraction[src.size * sizeof(Fraction)];
    int count = 0;
    while (getline(fin, line ) && count != src.size) {
        string temp = line.substr(0, line.find_first_of("/") );
        src.list_of_fraction[count].setTu(atoi(temp.c_str()));
        // cout << "  tu so: " << atoi(temp.c_str()) << endl;
        temp = line.substr(line.find_first_of("/") + 1);
        src.list_of_fraction[count].setMau(atoi(temp.c_str()));
        // cout << "  mau so: " << atoi(temp.c_str()) << endl;
        // cout << "  mau so: " << src.list_of_fraction[count].mau() << endl;
        count ++;
    }
    cout << "\nDanh sach phan so doc tu file: ";
    cout << src;
    return fin;
}

int main()
{
    // test phan so
    Fraction a, b;
    cin >> a;
    cin >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    Fraction c(a + b);
    cout << "c = a + b = " << c << endl;
    c += a;
    cout << "c += a = " << c << endl;
    c *= b;
    cout << "c *= b = " << c << endl;

    // test mang phan so
    ifstream fin("INPUT_BAI2.txt", ios::in);
    ofstream fout("OUTPUT_BAI2.txt", ios::out);
    if (fin.fail() || fout.fail()) {
        cerr << "\nCan't open files ...\n";
        return 225;
    }

    ListFraction head, tail;
    cin >> head;
    cout << head;
    fout << head;
    cout << "\nSap xep mang phan so tang dan: ";
    head.sortAsc();
    cout << head;
    cout << "Tong cac phan so: ";
    cout << head.sum() << endl;

    cout << "\nDoc file input va xuat ra man hinh ... \n";
    fin >> tail;


    _fcloseall();

    return 0;
}