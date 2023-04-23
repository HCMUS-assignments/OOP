#include "CongTy.h"
// Constructor
CongTy::CongTy()
{
    head = NULL;
    count = 0;
    sumSalary = 0;
    avgSalary = 0;
}

// Destructor
CongTy::~CongTy()
{
    if (head != NULL)
    {
        for (Node *p = head; p != NULL; p = p->pNext)
        {
            delete p->data;
        }
        head = NULL;
    }
}

// assignment operator
CongTy &CongTy::operator=(const CongTy &other)
{
    if (this != &other)
    {
        if (head != NULL)
        {
            for (Node *p = head; p != NULL; p = p->pNext)
            {
                delete p->data;
            }
            head = NULL;
        }
        count = other.count;
        sumSalary = other.sumSalary;
        avgSalary = other.avgSalary;
        for (Node *p = other.head; p != NULL; p = p->pNext)
        {
            if (p->data->getID().substr(0, 2) == "SX")
            {
                NVSanXuat *nvsx = new NVSanXuat();
                *nvsx = *(NVSanXuat *)p->data;
                addEmployee(nvsx);
            }
            else if (p->data->getID().substr(0, 2) == "CN")
            {
                NVCongNhat *nvcn = new NVCongNhat();
                *nvcn = *(NVCongNhat *)p->data;
                addEmployee(nvcn);
            }
        }
    }
    return *this;
}

// other methods

// 1. Nhập, xuất danh sách các nhân viên

// lấy dữ liệu từ file 'ds_NhanVien.dat': gồm:
// - thông tin của từng nhân viên được lưu trên mỗi dòng
// - NhanVienSanXuat phân biệt với NhanVienCongNhat bởi ID:
// - NhanVienSanXuat có ID bắt đầu bằng "SX"
// - NhanVienCongNhat có ID bắt đầu bằng "CN"
// Thông tin nhân viên sản xuất gồm: ID - Name - Birthdate - Address - number of products
// Thông tin nhân viên công nhật gồm: ID - Name - Birthdate - Address - number of days

void Standardize(string &s)
{
    int i = s.length() - 1;
    while (s[i] == ' ')
    {
        s.erase(i, 1);
        i--;
    }
}

void CongTy::read()
{
    if (head != NULL)
    {
        for (Node *p = head; p != NULL; p = p->pNext)
        {
            delete p->data;
        }
        head = NULL;
    }
    count = 0;

    ifstream fin("ds_NhanVien.dat", ios::in);
    if (fin.fail())
    {
        cout << "\nKhong mo duoc file ds_NhanVien.dat";
        return;
    }
    string line;
    while (getline(fin, line))
    {
        count++;
        string _id, _name, _birthdate, _address, _num;
        stringstream ss(line);
        getline(ss, _id, '-');
        ss.ignore();
        getline(ss, _name, '-');
        ss.ignore();
        getline(ss, _birthdate, '-');
        ss.ignore();
        getline(ss, _address, '-');
        ss.ignore();
        getline(ss, _num, '-');

        Standardize(_id);
        Standardize(_name);
        Standardize(_birthdate);
        Standardize(_address);
        Standardize(_num);

        if (strncmp(_id.c_str(), "SX", 2) == 0)
        {
            int num = stoi(_num);
            NVSanXuat *nvsx = new NVSanXuat(_id, _name, _birthdate, _address, num);
            addEmployee(nvsx);
        }
        else
        {
            int num = stoi(_num);
            NVCongNhat *nvcn = new NVCongNhat(_id, _name, _birthdate, _address, num);
            addEmployee(nvcn);
        }
    }
    fin.close();
    cout << "\nDa doc du lieu tu file ds_NhanVien.dat\n";
}

// xuất dữ liệu vào file ds_NhanVien.dat: gồm:
// ID - Name - Birthdate - Address - Salary

// chuyền tiền lương sang dạng chuỗi
string convertSalary(int salary)
{
    string str = to_string(salary);
    for (int i = str.length() - 3; i >= 0; i -= 3)
    {
        if (i > 0)
        {
            str.insert(i, ".");
        }
    }
    return str;
}

void CongTy::write()
{
    ofstream fout("ds_NhanVien.dat", ios::out);
    if (fout.fail())
    {
        cout << "\nKhong mo duoc file ds_NhanVien.dat";
        return;
    }
    for (Node *p = head; p != NULL; p = p->pNext)
    {
        fout << p->data->getID() << " - " << p->data->getFullName() << " - " << p->data->getBirthdate() << " - " << p->data->getAddress() << " - " << convertSalary(p->data->getSalary()) << endl;
    }
    fout.close();
    cout << "\nDa ghi du lieu vao file ds_NhanVien.dat\n";
}

// 3. Xuất danh sách nhân viên ra màn hình
void CongTy::print() {
    // ID - Fullname - Birthdate - Address - Salary
    cout <<"\n---------Thong tin nhan vien cua cong ty----------\n";
    for (Node *temp = head; temp != NULL; temp = temp->pNext) {
        cout << temp->data->getID() << ", " << temp->data->getFullName();
        cout << ", " << temp->data->getBirthdate() << ", " << temp->data->getAddress();
        cout << ", "  << temp->data->getNum() << endl;
      
    }
}

// 4. Tính tổng tiền lương của tất cả các nhân viên
int CongTy::sumSalaryOfAll()
{
    sumSalary = 0;
    for (Node *p = head; p != NULL; p = p->pNext)
        sumSalary += p->data->getSalary();

    return sumSalary;
}

// 5. Tìm nhân viên có lương cao nhất
void CongTy::findMaxSalary()
{
    int maxSalary = 0;
    int count = 0;
    for (Node *temp = head; temp != NULL; temp = temp->pNext)
    {
        if (temp == head)
        {
            maxSalary = temp->data->getSalary();
        }
        else
        {
            if (temp->data->getSalary() > maxSalary)
            {
                maxSalary = temp->data->getSalary();
                count = 1;
            }
            else if (temp->data->getSalary() == maxSalary)
            {
                count++;
            }
        }
    }

    if (count == 1) {
        cout << "\nNhan vien co luong cao nhat la: " << endl;
        for (Node *p = head; p != NULL; p = p->pNext) {
            if (p->data->getSalary() == maxSalary) {
                cout << p->data->getID() << " - " << p->data->getFullName() << " - " << convertSalary(p->data->getSalary()) << endl;
                return;
            }
        }
    }

    // ghi ra danh sách nhân viên có lương cao nhất file listEmployeeWithMaxSalary.txt
    ofstream fout("listEmployeeWithMaxSalary.txt", ios::out);
    if (fout.fail())
    {
        cout << "\nKhong mo duoc file listEmployeeWithMaxSalary.txt";
        return;
    }
    for (Node *p = head; p != NULL; p = p->pNext)
    {
        if (p->data->getSalary() == maxSalary)
        {
            fout << p->data->getID() << " - " << p->data->getFullName() << " - " << convertSalary(p->data->getSalary()) << endl;
        }
    }
    cout << "\n Da ghi dsnv co luong cao nhat ra file listEmployeeWithMaxSalary.txt\n";
}

// 6. Tính lương trung bình trong công ty
float CongTy::avgSalaryOfAll()
{
    if (count == 0)
    {
        cerr << "\nKhong co nhan vien nao trong cong ty...\n";
        return 0;
    }
    avgSalary = (float)sumSalaryOfAll() / count;
    return avgSalary;
}

// 7. Nhập vào mã, tìm nhân viên tương ứng
void CongTy::findEmployeeById()
{
    cout << "\nNhap ma nhan vien can tim: ";
    string id;
    fflush(stdin);
    getline(cin, id);
    for (Node *p = head; p != NULL; p = p->pNext)
    {
        if (p->data->getID() == id)
        {
            cout << "\nThong tin nhan vien: \n";
            cout << p->data->getID() << " - " << p->data->getFullName() << " - " << p->data->getBirthdate() << " - " << p->data->getAddress() << " - " << convertSalary(p->data->getSalary()) << endl;
            return;
        }
    }
    cout << "\nKhong ton tai nhan vien ID: " << id << " trong cong ty...\n";
}

// 8. Nhập vào tên, tìm nhân viên tương ứng
void CongTy::findEmployeeByName()
{
    cout << "\nNhap ten nhan vien can tim: ";
    string name;
    fflush(stdin);
    getline(cin, name);

    bool found = false;

    for (Node *p = head; p != NULL; p = p->pNext)
    {
        if (p->data->getFullName() == name)
        {
            cout << "\nThong tin nhan vien: \n";
            cout << p->data->getID() << " - " << p->data->getFullName() << " - " << p->data->getBirthdate() << " - " << p->data->getAddress() << " - " << convertSalary(p->data->getSalary()) << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "\nKhong ton tai nhan vien ten: " << name << " trong cong ty...\n";
    }
}

// 9. Có bao nhiêu nhân viên sinh trong tháng 5
int CongTy::countEmployeeHasBirthdayInMay()
{
    int num = 0;
    for (Node *p = head; p != NULL; p = p->pNext)
    {
        if (p->data->getBirthdate().substr(3, 2) == "05")
        {
            num++;
        }
    }
    return num;
}

// 10. Thêm 1 nhân viên vào danh sách
void CongTy::addEmployee()
{
    cout << "\nNhap thong tin nhan vien can them: ";
    cout << "\nID: ";
    string id;
    fflush(stdin);
    getline(cin, id);
    cout << "\nFullname: ";
    string name;
    fflush(stdin);
    getline(cin, name);

    cout << "\nBirthdate: ";
    string birthdate;
    fflush(stdin);
    getline(cin, birthdate);

    cout << "\nAddress: ";
    string address;
    fflush(stdin);
    getline(cin, address);

    int num;

    if (strncmp(id.c_str(), "SX", 2) == 0)
    {
        cout << "\nSo san pham: ";
        fflush(stdin);
        cin >> num;
        NVSanXuat *nvsx = new NVSanXuat(id, name, birthdate, address, num);
        addEmployee(nvsx);
    }
    else
    {
        cout << "\nSo ngay lam viec: ";
        fflush(stdin);
        cin >> num;
        NVCongNhat *nvcn = new NVCongNhat(id, name, birthdate, address, num);
        addEmployee(nvcn);
    }

    // ghi vào file ds_NhanVien.dat
    ofstream fout("ds_NhanVien.dat", ios::app);
    if (fout.fail())
    {
        cout << "\nKhong mo duoc file ds_NhanVien.dat";
        return;
    }
    fout << endl << id << " - " << name << " - " << birthdate << " - " << address << " - " << num << endl;

    cout << "\nDa them nhan vien vao danh sach va cap nhat file ds_NhanVien.dat\n";
}

void CongTy::addEmployee(NVSanXuat *&nvsx)
{
    Node *p = new Node;
    p->data = nvsx;
    p->pNext = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        for (Node *temp = head; temp != NULL; temp = temp->pNext)
        {
            if (temp->pNext == NULL)
            {
                temp->pNext = p;
                break;
            }
        }
    }
    count++;
}

void CongTy::addEmployee(NVCongNhat *&nvcn)
{
    Node *p = new Node;
    p->data = nvcn;
    p->pNext = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        for (Node *temp = head; temp != NULL; temp = temp->pNext)
        {
            if (temp->pNext == NULL)
            {
                temp->pNext = p;
                break;
            }
        }
    }
    count++;
}

// 11. Xóa 1 nhân viên khỏi danh sách
void CongTy::deleteEmployee()
{
    cout << "\nNhap ma nhan vien can xoa: ";
    string id;
    fflush(stdin);
    getline(cin, id);

    for (Node *temp = head; temp != NULL; temp = temp->pNext)
    {
        if (temp->data->getID() == id)
        {
            if (temp == head)
            {
                head = temp->pNext;
                delete temp;
                count--;
                break;
            }
            else
            {
                Node *p = head;
                while (p->pNext != temp)
                {
                    p = p->pNext;
                }
                p->pNext = temp->pNext;
                delete temp;
                count--;
                break;
            }
        }
    }

    // cap nhat file ds_NhanVien.dat
    ofstream fout("ds_NhanVien.dat", ios::out);
    if (fout.fail())
    {
        cout << "\nKhong mo duoc file ds_NhanVien.dat";
        return;
    }
    for (Node *p = head; p != NULL; p = p->pNext)
    {
        fout << p->data->getID() << " - " << p->data->getFullName() << " - " << p->data->getBirthdate() << " - " << p->data->getAddress() << " - " << p->data->getProduct_Day() << endl;
    }
    cout << "\nDa xoa nhan vien va cap nhat file ds_NhanVien.dat\n";
}

// 12. Ghi tất cả các nhân viên có lương nhỏ hơn lương trung bình của công ty lên file 'emp_LowerAvgSalary.dat'
void CongTy::writeEmployeeLowerAvgSalaryToFile()
{
    ofstream fout("emp_LowerAvgSalary.dat", ios::out);
    if (fout.fail())
    {
        cout << "\nKhong mo duoc file emp_LowerAvgSalary.dat";
        return;
    }
    fout << avgSalaryOfAll() << endl;
    for (Node *p = head; p != NULL; p = p->pNext)
    {
        if (p->data->getSalary() < avgSalaryOfAll())
        {
            fout << p->data->getID() << " - " << p->data->getFullName() << " - " << convertSalary(p->data->getSalary()) << endl;
        }
    }
    cout << "\nDa ghi file emp_LowerAvgSalary.dat\n";
}
