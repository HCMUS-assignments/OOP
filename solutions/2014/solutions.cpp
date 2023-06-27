/*
#include <bits/stdc++.h>
using namespace std;

class Bike {
    private:
    char* brand;
public:
    // ---------- a.bổ sung---------------
    // constructor
    Bike() {
        cout << "Bike constructor" << endl;
        brand = new char[10];
        strcpy(brand, "");
    }

    // destructor
    ~ Bike () {
        if (brand != NULL) {
            delete[] brand;
        }
    }

    // copy constructor
    Bike (const Bike &bike) {
        brand = new char[strlen(bike.brand) + 1];
        strcpy(brand, bike.brand);
    }

    // operator =
    Bike& operator= (const Bike &other) {
        if (this != &other) {
            if (brand != NULL) {
                delete[] brand;
            }
            brand = new char[strlen(other.brand) + 1];
            strcpy(brand, other.brand);
        }
        return *this;
    }

    // ----------------------

    virtual void move (int t1) {
        cout << brand << ":" << t1 * 12 << " ";
    }
};

class EBike : public Bike {
    public:
        void move(int t2) {
            Bike::move(t2 * 2);
        }
};

void display(Bike &a, EBike &b) {
    a.move(2);
    b.move(2);
}

int main() {
    EBike b1, b2;
    display(b1, b2);
    return 0;
}
*/

/*
a. Hãy cài đặt bổ sung các phương thức cần thiết để giải quyết các vấn đề về thuộc tính con trỏ cho lớp đối tượng Bike.
b. Cho biết kết quả xuất ra màn hình của chương trình trên (sau khi đã bổ sung code đầy đủ ở câu a.) Giải thích ngắn gọn

=>
:48 :48
Giải thích: vì lúc đầu gọi constructor các xe sẽ có brand là xâu rỗng,
- hai đối tượng b1, b2 có kiểu EBike
- Hàm display nhận tham số là tham chiếu đến đối tượng của lớp Bike hay các lớp con thông qua đối tượng a trong hàm display và tham chiếu đến đối tượng
của lớp Ebike thông qua đối tượng b trong hàm display. Tham chiếu cho ta truy cập và thao tác, có thể sử dụng các thuộc tính của lớp đó.
- Do đó, a và b tham chiếu đến EBike b1 và b2.
- a.move(2) sẽ gọi đến hàm move của lớp EBike: EBike::move(2) => Bike::move(4) => 48
- tương tự, b.move(2) sẽ gọi đến hàm move của lớp EBike: EBike::move(2) => Bike::move(4) => 48


c. Nêu sự khác biệt giữa lớp đối tượng (class) và đối tượng cụ thể (object, instance).
=>
- Lớp đối tượng (class) là một mô tả trừu tượng của 1 loại đối tượng, định nghĩa các thuộc tính và phương thức mà đối tượng của lớp đó có thể có.
Lớp cung cấp bản thiết kế cho đối tượng, mô tả các thuộc tính và phương thức chung mà tất cả các đối tượng thuộc lớp đó có thể sử dụng.

- Đối tượng cụ thể (object, instance) là phiên bản cụ thể của 1 lớp, là thực thể cụ thể có tồn tại trong chương trình, khi chúng ta khởi tạo 1 lớp,
ta tạo ra 1 bản sao của lớp đó, đối tượng thể hiện các trạng thái và hành vi cụ thể dựa trên mô tả trong lớp.

Liệt kê các lớp đối tượng và các đối tượng cụ thể trong đoạn mã nguồn trên.
=>
Các lớp đối tượng: Bike và EBike
Các đối tượng cụ thể: b1, b2, a, b, bike, other

*/

// câu 2
/*

#include <bits/stdc++.h>
using namespace std;

class IFace
{
public:
    virtual void show() = 0;
    virtual IFace *clone() = 0;
    virtual ~IFace()
    {
    }
};

class Face : public IFace
{
private:
    string shape;

protected:
    string getShape();

public:
    Face()
    {
        shape = "";
    }
    Face(string sh) : shape(sh)
    {
    }
    virtual void show()
    {
        cout << "Shape: " << shape << endl;
    }
    virtual IFace *clone()
    {
        return new Face(*this);
    }
};

// a. viết lớp EyedFace:
class EyedFace : public Face
{
    // cập nhật đếm số object/ instance của lớp EyedFace

private:
    int eyes;

public:
    static int countInstance;

public:
    EyedFace() : Face()
    {
        eyes = 0;
        countInstance++;
    }

    EyedFace(string sh, int eyes) : Face(sh), eyes(eyes)
    {
        countInstance++;
    }

    // destructor
    ~EyedFace()
    {
        countInstance--;
    }

    void show()
    {
        Face::show();
        cout << "Eyes: " << eyes << endl;
    }

    virtual IFace *clone()
    {
        return new EyedFace(*this);
    }
};

// b. cho đoạn mã nguồn nối tiếp
void testFace(IFace *fc)
{
    cout << "address of fc: " << fc << endl;
    IFace *a[3] = {fc, fc->clone(), fc->clone()};
    for (int i = 0; i < 3; i++)
    {
        a[i]->show();
    }
    cout << "The same 3 lines?";
    delete a[1], a[2];
}

// khởi tạo giá trị ban đầu cho EyedFace::countInstance
int EyedFace::countInstance = 0;

void count() {
    EyedFace efc;
    cout << "Number of EyedFace instances inside function: " << EyedFace::countInstance << endl;
}

int main()
{
    Face fc;
    Face fc1("Rectangle");
    cout << "address of fc1: " << &fc1 << endl;
    testFace(&fc1);

    cout << "\nNumber of EyedFace instances: " << EyedFace::countInstance << endl;
    count();
    cout << "Number of EyedFace instances: " << EyedFace::countInstance << endl;

    return 0;
}
*/

/*
a. Hãy viết lớp EyedFace có :
- Hai thuộc tính: Shape kiểu chuỗi và eyes kiểu só nguyên;
- Hai phương thức: show() xuất ra màn hình giá trị của cả hai thuộc tính, và clone() trả về 1 đối tượng EyedFace mới là bản sao của đối tượng này;
- Một bản tao constructor nhận hai tham số tương ứng với hai thuộc tính

*/

/*
b.
- Hàm main có lỗi kh thể chạy được. Hãy giải thích lý do lỗi đó.
=> Lỗi do class Face lúc này là abstract class bời vì nó chứa phương thức thuần ảo clone() không được định nghĩa.
Khi một lớp con không ghi đè (triền khai) các phương thức thuần ảo của lớp cơ sở thì nó sẽ kế thừa và trở thành
lớp abstract. Do đó, nó không thể tạo ra đối tượng cụ thể.
- Lỗi thứ 2 là hàm Face lúc này không có default constructor, nếu mặc định thì default constructor sẽ được tạo tự động
nhưng khi ta định nghĩa 1 constructor khác thì default constructor sẽ không được tạo tự động nữa.

- Hãy sữa lỗi của hàm main() để chạy được hàm testFace() và cho biết kết quả xuất ra màn hình của hàm main() đó.
=> Kết quả xuất ra màn hình:
Shape: Rectangle
Shape: Rectangle
Shape: Rectangle
The same 3 lines?

*/

/*
c. Hãy cải tiến chương trình bên trên :
- Hàm testFace quản lý bộ nhớ chưa hiệu quả, Hãy sửa lại lỗi bộ nhớ đó.
=> Ta cần thêm giải phóng bộ nhớ cho các đối tượng a[1], a[2] cuối hàm vì không cần dùng đến nữa

Hãy viết thêm mã vào lớp EyedFace để đếm tổng số đối tượng (object, instance) của lớp đó và cập nhật mỗi khi tạo/hủy
đối tượng. Sau đó hãy thêm mã vào cuối hàm main( ) để kiểm tra xem còn bao nhiêu đối tượng EyedFace trong bộ nhớ


*/

/*
Cau 3:

Gồm các lớp:
- Basic:
- DataFree
- DataFix
- KhachHang
- DanhSachKhachHang

*/

#include <bits/stdc++.h>
using namespace std;

class Basic
{
protected:
    int _ThoiGianGoi;
    int _DonGiaGoi;
    int _LuuLuongInternet;
    int _DonGiaInternet;

public:
    Basic();
    virtual ~Basic();
    virtual void Nhap();
    virtual void Xuat();
    virtual int CuocDienThoai();
    virtual int CuocInternet();
    virtual int CuocTong();
    void SuDung(int thoiGianGoi, int luuLuong);
};

// define
Basic::Basic()
{
    _ThoiGianGoi = 0;
    _DonGiaGoi = 1000;
    _LuuLuongInternet = 0;
    _DonGiaInternet = 200;
}

void Basic::Nhap()
{
}

void Basic::Xuat()
{
    cout << "Ten goi cuoc: Basic" << endl; 
    cout << "Don gia goi: " << _DonGiaGoi << endl;
    cout << "Don gia Internet: " << _DonGiaInternet << endl;
}

int Basic::CuocDienThoai()
{
    return _ThoiGianGoi * _DonGiaGoi;
}

int Basic::CuocInternet()
{
    return _LuuLuongInternet * _DonGiaInternet;
}

int Basic::CuocTong()
{
    return 1.1 * (CuocDienThoai() + CuocInternet());
}

void Basic::SuDung(int thoiGianGoi, int luuLuong)
{
    this->_ThoiGianGoi += thoiGianGoi;
    this->_LuuLuongInternet += luuLuong;
}

class DataFree : public Basic
{
private:
    int _CuocThueBao;

public:
    DataFree();
    void Nhap();
    void Xuat();
    int CuocInternet();
};

// define
DataFree::DataFree() : Basic()
{
    _CuocThueBao = 0;
}

void DataFree::Nhap() 
{
    cout << "Nhap cuoc thue bao: ";
    cin >> _CuocThueBao;
    cout << "Nhap nguong luu luong mien phi: ";
    cin >> _LuuLuongInternet;
    _LuuLuongInternet = -_LuuLuongInternet;
}

void DataFree::Xuat()
{
    cout << "Ten goi cuoc: Data Free" << endl;
    cout << "Cuoc thue bao: " << _CuocThueBao << endl;
    cout << "Luu luong mien phi: " << _LuuLuongInternet << endl;
}

int DataFree::CuocInternet()
{
    if (_LuuLuongInternet <= 0) {
        return _CuocThueBao;
    } else {
        return _CuocThueBao + _LuuLuongInternet * _DonGiaInternet;
    }
}

class DataFix : public Basic
{
public:
    int CuocDienThoai();
    int CuocInternet();
    void Xuat();
};

// define
int DataFix::CuocDienThoai()
{
    return 0.9 * Basic::CuocDienThoai();
}

int DataFix::CuocInternet()
{
    return 1000000;
}

void DataFix::Xuat()
{
    cout << "Ten goi cuoc: Data Fix" << endl;
}

class KhachHang
{
private:
    string _HoTen;
    string _CMND;
    string _DiaChi;
    Basic *_GoiCuoc;

public:
    KhachHang();
    ~KhachHang();
    void Nhap();
    void Xuat();
    int TinhCuocCuoiThang();
    void SuDung(int thoiGianGoi, int luuLuong);
};

// define
KhachHang::KhachHang()
{
    _HoTen = "";
    _CMND = "";
    _DiaChi = "";
    _GoiCuoc = NULL;

}

KhachHang::~KhachHang()
{
    if (_GoiCuoc != NULL) {
        delete _GoiCuoc;
     }
}

void KhachHang::Nhap()
{
        cout << "Nhap thong tin khach hang" << endl;
    cout << "Ho ten: ";
    fflush(stdin);
    getline(cin, _HoTen);
    
    cout << "Nhap CMND: ";
    getline(cin, _CMND);

    cout << "Nhap dia chi: ";
    getline(cin, _DiaChi);

    cout << "Goi cuoc su dung: (0: Basic | 1: Data Free | 2: Data Fix) : ";
    fflush(stdin);
    int choice;
    cin >> choice;
    if (choice == 0) {
        _GoiCuoc = new Basic();
    } else if (choice == 1) {
        _GoiCuoc = new DataFree();
    } else {
        _GoiCuoc = new DataFix();
    }
    _GoiCuoc->Nhap();
}

void KhachHang::Xuat()
{
    cout << "Thong tin khach hang " << endl;
    cout << "Ho ten: " << _HoTen << endl;
    cout << "CMND: " << _CMND << endl;
    cout << "Dia chi: " << _DiaChi << endl;
    cout << "Thong tin goi cuoc: ";
    _GoiCuoc->Xuat();
}

int KhachHang::TinhCuocCuoiThang()
{
    return _GoiCuoc->CuocTong();
}

void KhachHang::SuDung(int thoiGianGoi, int luuLuong)
{
    _GoiCuoc->SuDung(thoiGianGoi, luuLuong);
}

class DanhSachHopDong
{
private:
    vector<KhachHang *> _dsKhachHang;

public:
    DanhSachHopDong();
    ~DanhSachHopDong();
    void DangKy();
    void ThongBaoTienCuoc();
};

// define

DanhSachHopDong::DanhSachHopDong()
{
}

DanhSachHopDong::~DanhSachHopDong()
{
    if (_dsKhachHang.size() > 0) {
        for (int i = 0; i < _dsKhachHang.size(); i++) {
           delete _dsKhachHang[i];
        }
    }
}

void DanhSachHopDong::DangKy()
{
    cout << "So luong khach hang: ";
    fflush(stdin);
    int num = 0;
    cin >> num;
    _dsKhachHang.resize(num);
    for (int i = 0; i < num; i++) {
        KhachHang *temp = new KhachHang();
        temp->Nhap();
        _dsKhachHang.push_back(temp);
    }
}

void DanhSachHopDong::ThongBaoTienCuoc()
{
    cout << "Thong bao tien cuoc "<< endl;
    for (int i = 0; i < _dsKhachHang.size(); i++) {
        _dsKhachHang[i]->Xuat();
        cout << "Tong cuoc : " << _dsKhachHang[i]->TinhCuocCuoiThang() << endl;
    }
}