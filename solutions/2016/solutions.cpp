// cau 1
/*
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;
const double PI = 3.1415928;
class Shape
{
public:
    Shape() { cerr << "construct Shape" << endl; }
    virtual string Description()
    {
        stringstream ss;
        ss << "Shape(area=" << this->Area() << ")";
        return ss.str();
    }
    virtual float Area() = 0;
    virtual void Scale(float scaleFactor) = 0;
    const type_info &InterfaceType()
    {
        return typeid(Shape);
    }
    const type_info &ImplementationType()
    {
        return typeid(*this);
    }
    virtual ~Shape()
    {
        cerr << "destruct Shape" << endl;
    }
};
class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r) : Shape(), radius(r)
    {
        cerr << "construct Circle" << endl;
    }
    string Description()
    {
        stringstream ss;
        ss << "Circle(r=" << this->radius << ")";
        return ss.str();
    }
    float Area() { return PI * radius * radius; }
    void Scale(float scaleFactor)
    {
        this->radius *= scaleFactor;
    }
    const type_info &InterfaceType()
    {
        return typeid(Circle);
    }
    ~Circle() { cerr << "destruct Circle" << endl; }
};

class Ellipse : public Shape
{
private:
    float majorR, minorR;

public:
    Ellipse(float a, float b)
        : Shape(), majorR(a), minorR(b)
    {
        cerr << "construct Ellipse" << endl;
    }
    string Description()
    {
        stringstream ss;
        ss << "Ellipse(a=" << this->majorR
           << ", b=" << this->minorR << ")";
        return ss.str();
    }
    float Area() { return PI * majorR * minorR; }
    void Scale(float scaleFactor)
    {
        this->majorR *= scaleFactor;
        this->minorR *= scaleFactor;
    }
    void Scale(float sa, float sb)
    {
        this->majorR *= sa;
        this->minorR *= sb;
    }
    const type_info &InterfaceType()
    {
        return typeid(Ellipse);
    }
    ~Ellipse()
    {
        cerr << "destruct Ellipse" << endl;
    }
};

int main()
{
    Ellipse ellipse(2.0 / 3, 6);
    Shape *shape = &ellipse;
    shape->Scale(1.0 / 2);
    // shape->Scale(3, 1.0/3);
    cout << "ellipse: " << endl;
    cout << ellipse.Description() << endl;
    cout << ellipse.Area() << endl;
    cout << ellipse.InterfaceType().name() << endl;
    cout << ellipse.ImplementationType().name() << endl;
    cout << "shape = &ellipse: " << endl;
    cout << shape->Description() << endl;
    cout << shape->Area() << endl;
    cout << shape->InterfaceType().name() << endl;
    cout << shape->ImplementationType().name() << endl;
    // Shape ashape;
    // cout << ashape.Description() << endl;

    return 0; // no error
}

*/

/*
a. Hãy viết kết quả xuất ra màn hình sau khi chương trình chạy xong
=>
construct Shape
construct Ellipse
ellipse:
Ellipse(a=0.333333, b=3)
3.14159
Ellipse
Ellipse
shape = &ellipse:
Ellipse(a=0.333333, b=3)
3.14159
Shape
Ellipse
destruct Ellipse
destruct Shape

b. Trong chương trình, có nhiều hàm cùng tên, chúng có quan hệ gì với nhau (hay không có quan hệ gì hết)?
=> Các hàm cùng tên có quan hệ kế thừa, override


Hãy giải thích quan hệ giữa 2 hàm trong những cặp trùng tên sau (nêu tên quan hệ nếu có, nêu ý nghĩa và ứng dụng của quan hệ đó)

- Shape::Description() và Circle::Description()
=> Quan hệ override, hàm Description() của lớp Circle override hàm Description() của lớp Shape

- Ellipse::Scale(float) và Ellipse::Scale(float, float)
=> Quan hệ overload, hàm Scale(float) và hàm Scale(float, float) đều là hàm của lớp Ellipse, nhưng có cách thức hoạt động khác nhau
nhận các tham số khác nhau

- Shape::InterfaceType() và Circle::InterfaceType()
=> Quan hệ override, nhưng không phải hàm ảo nên khi gọi sẽ gọi đúng phương thức của đối tượng đó.

- Circle::InterfaceType() và Eclipse::InterfaceType()
=> Không có quan hệ gì

c. Nếu bỏ dấu comment // của các dòng 88 và 102, 103 ra thì chương trình gặp lỗi gì?
- Dòng 88: lớp đối tượng Shape không có phương thức Scale(float, float), nên không thể đa hình dùng phương thức này thông qua con trỏ shape có kiểu đối tượng Shape
- Dòng 102: Shape là lớp trừu tượng (có phương thức thuần ảo) nên không thể tạo ra thể hiện cụ thể.
- Dòng 103: Đối tượng ashape không được tạo ra ở dòng 102 nên không thể dùng đến phương thức ở dòng 103 được

d. [*] Phải thay thế vào chỗ của các dòng bị comment (88, 102, 103) những dòng code như thế nào để thực hiện
được ý đồ của các dòng code đó.
- Ở dòng 88 muốn gọi phương thức Eclipse::Scale(float, float) thông qua con trỏ shape (chứ không phải thông qua biến ellipse)
=> Thêm phương thức ảo Shape::Scale(float, float) ở lớp Shape

- Ở dòng 102, 103 muốn gọi phương thức Shape::Description()
=> Thay phương thức thuần ảo Shape::Area() = 0 bằng phương thức ảo và cài đặt chúng
Hoặc gọi trực tiếp: shape->Shape::Description()

*/

// cau 2

#include <bits/stdc++.h>
using namespace std;

class BenhNhan
{
private:
    int _msbn;

public:
    BenhNhan();
    BenhNhan(int msbn) : _msbn(msbn) {}

    int getMSBN() { return _msbn; }
    virtual double VPTL(int ngay) = 0;
};

BenhNhan::BenhNhan()
{
    _msbn = 0;
}

// ---------------------------

class BNNoiTru : public BenhNhan
{
private:
    int _soNgayNamVien;
    int _phiKhamBenhMoiNgay;
    string _loaiPhong;
    int _ngayNV;
    int _ngayXV;

public:
    BNNoiTru();
    BNNoiTru(int msbn, int phiKBMN, string loaiPhong, int ngayNV);

    void updateInfo(int ngayXV);
    double VPTL(int ngay);
};

BNNoiTru::BNNoiTru() : BenhNhan()
{
    _soNgayNamVien = 0;
    _phiKhamBenhMoiNgay = 0;
    _loaiPhong = "";
    _ngayNV = 0;
    _ngayXV = 0;
}

BNNoiTru::BNNoiTru(int msbn, int phiKBMN, string loaiPhong, int ngayNV) : BenhNhan(msbn)
{
    _phiKhamBenhMoiNgay = phiKBMN;
    _loaiPhong = loaiPhong;
    _ngayNV = ngayNV;
    _ngayXV = 0;

}

double BNNoiTru::VPTL(int ngay)
{
    if (_ngayXV == 0)
    {
        _soNgayNamVien = ngay - _ngayNV ;
    }
    else
    {

        _soNgayNamVien = _ngayXV - _ngayNV ;
    }
    int donGiaPhong = 0;
    if (_loaiPhong == "A")
        donGiaPhong = 1400000;
    else if (_loaiPhong == "B")
        donGiaPhong = 900000;
    else if (_loaiPhong == "C")
        donGiaPhong = 600000;
    else
        donGiaPhong = 0;
    cout << "So ngay nam vien: " << _soNgayNamVien << endl;
    cout << "Don gia phong: " << donGiaPhong << endl;
    cout << "Phi kham benh moi ngay: " << _phiKhamBenhMoiNgay << endl;
    return _soNgayNamVien * (_phiKhamBenhMoiNgay + donGiaPhong);
}

void BNNoiTru::updateInfo(int ngayXV)
{
    _ngayXV = ngayXV;
}

// ---------------------------

class BNNgoaiTru : public BenhNhan
{
private:
    vector<int> _ngayKham;
    vector<int> _phiKhamBenh;

public:
    BNNgoaiTru(int msbn, int ngayKham, int phiKhamBenh);

    void updateInfo(int ngayKham, int phiKhamBenh);
    double VPTL(int ngay);
};

BNNgoaiTru::BNNgoaiTru(int msbn, int ngayKham, int phiKhamBenh) : BenhNhan(msbn)
{
    _ngayKham.push_back(ngayKham);
    _phiKhamBenh.push_back(phiKhamBenh);
}

void BNNgoaiTru::updateInfo(int ngayKham, int phiKhamBenh)
{
    _ngayKham.push_back(ngayKham);
    _phiKhamBenh.push_back(phiKhamBenh);
}

double BNNgoaiTru::VPTL(int ngay)
{
    double tongPhiKhamBenh = 0;
    for (int i = 0; i < _ngayKham.size(); i++)
    {
        if (_ngayKham[i] <= ngay)
            tongPhiKhamBenh += _phiKhamBenh[i];
    }
    return tongPhiKhamBenh;
}

// ---------------------------

class BenhVien
{
private:
    vector<BenhNhan *> _dsBenhNhan;
    int _tongSoBenhNhan;
    int _ngayTKVP;

public:
    BenhVien();
    ~BenhVien();

    double TKVP();

    // doc file
    void Nhap(string filename);
};

BenhVien::BenhVien()
{
    _tongSoBenhNhan = 0;
}

BenhVien::~BenhVien()
{
    for (int i = 0; i < _dsBenhNhan.size(); i++)
    {
        delete _dsBenhNhan[i];
    }
}

void BenhVien::Nhap(string filename)
{
    freopen(filename.c_str(), "r", stdin);
    string line;
    while (getline(cin, line))
    {
        // cout << "Thong tin dong: " << line << endl;
        stringstream ss(line);

        int ngay;
        string msbn;
        string hoatDong;
        int chiPhi;
        string loaiPhong;

        ss >> ngay >> msbn;
        if (stoi(msbn) == -1)
        {
            // tong ket vien phi
            this->_ngayTKVP = ngay;
        }
        else
        {
            ss >> hoatDong >> chiPhi;
            if (stoi(msbn) <= _tongSoBenhNhan)
            {
                // update thong tin
                if (hoatDong == "XV")
                {
                    for (int i = 0; i < _dsBenhNhan.size(); i++)
                    {
                        if (_dsBenhNhan[i]->getMSBN() == stoi(msbn))
                        {
                            ((BNNoiTru *)_dsBenhNhan[i])->updateInfo(ngay);
                        }
                    }
                }
                else if (hoatDong == "KB")
                {
                    for (int i = 0; i < _dsBenhNhan.size(); i++)
                    {
                        if (_dsBenhNhan[i]->getMSBN() == stoi(msbn))
                        {
                            ((BNNgoaiTru *)_dsBenhNhan[i])->updateInfo(ngay, chiPhi);
                        }
                    }
                }

                continue;
            }

            if (hoatDong == "NV")
            {
                ss >> loaiPhong;
                BNNoiTru *bn = new BNNoiTru(stoi(msbn), chiPhi, loaiPhong, ngay);
                _dsBenhNhan.push_back(bn);
                _tongSoBenhNhan++;
            }
            else if (hoatDong == "KB")
            {
                BenhNhan *bn = new BNNgoaiTru(stoi(msbn), ngay, chiPhi);
                _dsBenhNhan.push_back(bn);
                _tongSoBenhNhan++;
            }
        }
    }
    cout << "Tong so benh nhan: " << _tongSoBenhNhan << endl;
    fclose(stdin);
    freopen("CON", "r", stdin);
}

double BenhVien::TKVP()
{
    double tongChiPhi = 0;
    cout << "Ngay TKVP: " << _ngayTKVP << endl;
    for (int i = 0; i < _dsBenhNhan.size(); i++)
    {
        tongChiPhi += _dsBenhNhan[i]->VPTL(_ngayTKVP);
        cout << "VPTL cua benh nhan thu " << i + 1 << ": " << _dsBenhNhan[i]->VPTL(_ngayTKVP) << endl;
    }
    return tongChiPhi;
}

int main()
{
    BenhVien bv;
    bv.Nhap("input.txt");
    cout << bv.TKVP();
    return 0;
}
