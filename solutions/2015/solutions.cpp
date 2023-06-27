#include <bits/stdc++.h>
using namespace std;

// cau 1

/*
class A
{
public:
    virtual void f(int x) { cout << x << " "; }
};

class B : public A
{
public:
    void f(int y) { A::f(y + 1); }
};

void doSomething(A a, B b)
{
    a.f(3);
    b.f(3);
}

void main()
{
    B x, y;
    doSomething(x, y);
}

a. cho biết kết quả trên màn hình của đoạn mã nguồn tren, giải thích ngắn gọn.
=> 3 4
Giải thích:
- Trong hàm doSomething chúng ta truyền hai đối tượng x, y có kiểu B vào các tham số a (A) và b (B).
Tuy nhiên, khi truyền đối tượng kiểu B vào tham số có kiểu A, chỉ phần của A trong B được sao chép vào a.
Điều này dẫn đến mất mát thông tin của phần B.
- Khi gọi a.f(3) vì a có kiểu A nên hàm A::f được gọi và in ra 3
- Khi gọi a.f(3) vì b có kiểu B nên hàm B::f sẽ được gọi và hàm này gọi A::f(y+1) và in ra 4.

*/

/*
class A {
    public:
    A() {
        a = new int[3];
        for (int i = 0; i < 3; i++) {
            a[i] = i+1;
        }
    }

    A& operator= (const A& other) {
        if (this != &other) {
            delete[] a;
            a = new int[3];
            for (int i = 0; i < 3; i++) {
                a[i] = other.a[i];
            }
        }
        return *this;
    }

    A (const A& obj) {
        a = new int[3];
        for (int i = 0; i < 3; i++) {
            a[i] = obj.a[i];

        }

    }

    ~A () {
        delete[] a;
    }

    private:
    int *a;
};

void init(A &a) {
    A b;
    a = b;
}

void main() {
    A obj;
    init(obj);
}

b. Hãy cho biết đoạn mã nguồn trên gặp vấn đề gì? Cài đặt cụ thể cách giải quyết.
- Rò rỉ bộ nhớ: khi truyền tham chiếu hàm init đối tượng gốc obj (có tên mới trong hàm init là a),
sau khi thực hiện a = b thì thuộc tính con trỏ a của đối tượng a sẽ sao chép địa chỉ vùng nhớ của con trỏ a trong đối tượng b
điều này sẽ gây ra lỗi nếu thao tác thay đổi trên a sẽ ảnh hưởng đến b và ngược lại, hơn nữa thì giá trị của thuộc tính a chưa được giải phóng trước khi gán cho giá trị mới nên gây rò rĩ bộ nhớ
- Giải quyết:
+ Nạp chồng toán tử gán
+ Cài đặt toán tử sao chép


*/

/*

c. Cho lớp đối tượng class Singleton {};
- Hãy đề xuất một giải pháp để lớp đối tượng Singleton chỉ được phép tạo một thể hiện duy nhất.
Cài đặt cụ thể giải pháp và giải thích ngắn gọn những yếu tố nào đảm bảo tính duy nhất đó.


class Singleton {
    private:
        Singleton *obj = NULL;
        Singleton();
        public:
            static Singleton getInstance() {
                if (obj == NULL) {
                    obj = new Singleton();
                }
                return obj;
            }
};

- Lớp Singleton chỉ có thể tạo 1 đối tượng duy nhất do ta không thể tạo ra đối tượng của lớp Singleton qua việc gọi constructor hay khai báo biến
do constructor được khai báo là phương thức private. Ta chỉ có thể tạo ra đối tượng Singleton qua việc gọi Singleton::getObj() nhờ đó ta có thể quản lý đối tượng Singleton được tạo ra.
Nếu đã có đối tượng rồi thì ta sẽ không tạo ra nữa mà trả về đối tượng duy nhất đã được tạo ra.

*/

// Cau 2
//- Hãy cài đặt lớp BigInteger biểu diễn số nguyên lớn có những thuộc tính và phương thức cần thiết để đoạn mã nguofn biên dịch thành công và chạy đúng ngữ nghĩa:
/*
class BigInteger
{
private:
    string value;

public:
    BigInteger(string str = "0") : value(str)
    {
        standardize();
    }

    void standardize()
    {
        // chuan hoa xau, bo ki tu trang
        string temp = value;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == ' ') {
                temp.erase(i);
                i--;
            }
        }

        // xoa cac so 0 vo nghia o dau xau
        while (temp[0] == '0' && temp.length() > 1) {
            temp.erase(0);
        }
        value = temp;
    }

    bool operator==(const BigInteger &other) const
    {
        return value == other.value;
    }

    friend istream &operator>>(istream &in, BigInteger &obj)
    {
        in >> obj.value;
        obj.standardize();

        return in;
    }
};

void main()
{
    BigInteger n1(" 1234567891011 "); // Khoi tao tu chuoi
    BigInteger n2;                    // khoi tao mac dinh = 0
    cout << "Input an integer = ";
    cin >> n2; // nhap gia tri tu ban phim
    if (n1 == n2)
    {
        cout << "Equal.\n";
    }
    else
    {
        cout << "Not equal. \n";
    }
}

*/

// cau 3

class Sap {
    protected:
        int _DonGiaThue;
        int _STT;
        int _DienTich;
        int _DoanhThu;
        string _LoaiSap;

        public:
            Sap();
            virtual void Nhap();
            virtual void Xuat();
            virtual int TienThueSap() ;
            virtual int ThueDoanhThu() = 0;
            virtual int SoTienPhaiDong() ;

};
// define
Sap::Sap() {
    _LoaiSap = "";
    _DonGiaThue = 40000000;
    _STT = 0;
    _DienTich = 0;
    _DoanhThu = 0;
}

void Sap::Nhap() {
    cout << "Nhap STT: ";
    cin >> _STT;

    cout << "Nhap dien tich: ";
    cin >> _DienTich;

    cout << "Nhap doanh thu: ";
    cin >> _DoanhThu;
}

void Sap::Xuat() {
    cout << "Loai sap: " << _LoaiSap << endl;
    cout << "STT: " << _STT << endl;
    cout << "Dien tich: " << _DienTich << endl;
    cout << "Doanh thu: " << _DoanhThu << endl;
}

int Sap::TienThueSap() {
    return _DonGiaThue * _DienTich;
} 

int Sap::SoTienPhaiDong() {
    return TienThueSap() + ThueDoanhThu();
}

class SapThucPham : public Sap {
    protected:
        int _ThueDVDongLanh;
    public:
        SapThucPham();
        void Nhap();
        void Xuat();
        int ThueDoanhThu();
        int SoTienPhaiDong();

};

SapThucPham::SapThucPham() : Sap() {
    _ThueDVDongLanh = 0;
    _LoaiSap = "Thuc Pham";
}

void SapThucPham::Nhap()  {
    Sap::Nhap();
    cout << "Nhap tien su dung dich vu dong lanh: ";
    cin >> _ThueDVDongLanh;
}

void SapThucPham::Xuat() {
    cout << "Thue dich vu dong lanh: " << _ThueDVDongLanh << endl;
}

int SapThucPham::ThueDoanhThu() {
    return 5 * _DoanhThu / 100;
}

int SapThucPham::SoTienPhaiDong() {
    return Sap::SoTienPhaiDong() + _ThueDVDongLanh;
}

class SapQuanAo : public Sap {
    public:
    SapQuanAo();
        int ThueDoanhThu();

};

SapQuanAo::SapQuanAo() : Sap() {
    _LoaiSap = "Quan Ao";
}

int SapQuanAo::ThueDoanhThu() {
    return 10 * _DoanhThu / 100;
}

class SapTrangSuc : public Sap {
    public:
    SapTrangSuc();
    int ThueDoanhThu();

};

SapTrangSuc::SapTrangSuc() : Sap() {
    _LoaiSap = "Trang Suc";
}

int SapTrangSuc::ThueDoanhThu() {
    return _DoanhThu < 100000000 ? 0.2 * _DoanhThu : 0.3 * _DoanhThu;
}
class QuanLySap {
    private:
        vector<Sap*> _dsSap;
        int _SoSapDuocThue;

    public:
        QuanLySap();
        ~QuanLySap();

        void Nhap();
        void Xuat();

        int TongTienThueSap();

};

QuanLySap::QuanLySap() {
    
}

QuanLySap::~QuanLySap() {
    if (_dsSap.size() > 0) {
        for (int i = 0; i < _dsSap.size(); i++) {
            delete _dsSap[i];
        }
    }
}

void QuanLySap::Nhap() {
    cout << "Nhap so sap duoc thue: ";
    cin >> _SoSapDuocThue;

    _dsSap.resize(_SoSapDuocThue);
    for (int i = 0; i < _SoSapDuocThue; i++) {
        cout << "Nhap loai sap < 0: Thuc pham, 1: Quan ao, 2: Trang suc >: ";
        int choice;
        cin >> choice;
        if (choice == 0) {
            _dsSap[i] = new SapThucPham();
        } else if (choice == 1) {
            _dsSap[i] = new SapQuanAo();
        } else {
            _dsSap[i] = new SapTrangSuc();
        }
        _dsSap[i]->Nhap();
    }
}

void QuanLySap::Xuat() {
    for (int i = 0; i < _SoSapDuocThue; i++) {
        _dsSap[i]->Xuat();
        cout << "So tien phai dong: " << _dsSap[i]->SoTienPhaiDong() << endl;
    }
}

int QuanLySap::TongTienThueSap() {
    int sum = 0;
    for (int i = 0; i < _SoSapDuocThue; i++) {
        sum += _dsSap[i]->SoTienPhaiDong();
    }
    // tràn số: sử dụng BigInteger của bài 2
    return sum;

}


int main() {
    cout << "Quan ly sap : OOP-Market " << endl;
    QuanLySap qlSap;
    qlSap.Nhap();
    qlSap.Xuat();
    cout << "Tong tien thue sap: " << qlSap.TongTienThueSap() << endl;
    return 22;
}
