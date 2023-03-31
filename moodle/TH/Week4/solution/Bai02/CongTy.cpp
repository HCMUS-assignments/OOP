#include "CongTy.h"
// Constructor
CongTy::CongTy()
{
    dsNV = NULL;
    count = 0;
    sumSalary = 0;
    avgSalary = 0;
}

// Destructor
CongTy::~CongTy()
{
    if (dsNV != NULL)
    {
        delete[] dsNV;
        dsNV = NULL;
    }
}

// assignment operator
CongTy &CongTy::operator=(const CongTy &other)
{
    if (this != &other)
    {
        if (dsNV != NULL)
        {
            delete[] dsNV;
            dsNV = NULL;
        }
        count = other.count;
        sumSalary = other.sumSalary;
        avgSalary = other.avgSalary;
        dsNV = new NhanVien[count];
        for (int i = 0; i < count; i++)
        {
            dsNV[i] = other.dsNV[i];
        }
    }
    return *this;
}

// other methods

// 1. Nhập, xuất danh sách các nhân viên 

// lấy dữ liệu từ file input.txt: gồm:
// - thông tin của từng nhân viên được lưu trên mỗi dòng
// - NhanVienSanXuat phân biệt với NhanVienCongNhat bởi ID:
// - NhanVienSanXuat có ID bắt đầu bằng "SX"
// - NhanVienCongNhat có ID bắt đầu bằng "CN"
// Thông tin nhân viên sản xuất gồm: ID - Name - Birthdate - Address - number of products 
// Thông tin nhân viên công nhật gồm: ID - Name - Birthdate - Address - number of days

void Standardize(string s) {
    int i = s.length() - 1;
    while (s[i] == ' ') {
        s.erase(i, 1);
        i--;
    }
}

void CongTy::read()
{
    if (dsNV != NULL)
    {
        delete[] dsNV;
        dsNV = NULL;
    }
    count = 0;

    ifstream fin("input.txt", ios::in);
    if (fin.fail())
    {
        cout << "\nKhong mo duoc file input.txt";
        return;
    }
    string line;
    while (getline(fin, line)) {
        count ++;
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
        
        if (strncmp(_id.c_str(), "SX", 2) == 0) {
            int num = stoi(_num);
            NVSanXuat nvsx (_id, _name, _birthdate, _address, num);
            addEmployee(nvsx);
        }
        else {
            int num = stoi(_num);
            NVCongNhat nvcn(_id, _name, _birthdate, _address, num);
            addEmployee(nvcn);
        }
    }
    fin.close();
}

// xuất dữ liệu vào file output.txt: gồm:
// ID - Name - Birthdate - Address - Salary

void CongTy::write()
{
    ofstream fout("output.txt", ios::out);
    if (fout.fail())
    {
        cout << "\nKhong mo duoc file output.txt";
        return;
    }
    for (int i = 0; i < count ; i++) {
        fout << dsNV[i].getID() << " - " << dsNV[i].getFullName() << " - " << dsNV[i].getBirthdate() << " - " << dsNV[i].getAddress() << " - " << dsNV[i].getSalary() << endl;
    }
    fout.close();
}

// 2. Tính tổng tiền lương của tất cả các nhân viên
int CongTy::sumSalaryOfAll()
{
    for (int i = 0; i < count; i++)
    {
        sumSalary += dsNV[i].getSalary();
    }
    return sumSalary;
}

// 3. Tìm nhân viên có lương cao nhất
NhanVien* CongTy::findMaxSalary()
{
    int max = dsNV[0].getSalary();
    int index = 0;
    for (int i = 1; i < count; i++)
    {
        if (dsNV[i].getSalary() > max)
        {
            max = dsNV[i].getSalary();
            index = i;
        }
    }
    return dsNV + index;
}

// 4. Tính lương trung bình trong công ty
float CongTy::avgSalaryOfAll()
{
    avgSalary = (float)sumSalaryOfAll() / count;
    return avgSalary;
}

// 5. Nhập vào mã, tìm nhân viên tương ứng
NhanVien *CongTy::findEmployeeById()
{
    cout << "\nNhap ma nhan vien can tim: ";
    string id;
    fflush(stdin);
    getline(cin, id);
    for (int i = 0; i < count; i++)
    {
        if (dsNV[i].getID() == id)
        {
            return dsNV + i;
        }
    }
    cout << "\nKhong ton tai nhan vien ID: " << id << " trong cong ty...\n";
    return NULL;
}

// 6. Nhập vào tên, tìm nhân viên tương ứng
NhanVien *CongTy::findEmployeeByName()
{
    cout << "\nNhap ten nhan vien can tim: ";
    string name;
    fflush(stdin);
    getline(cin, name);

    for (int i = 0; i < count; i++)
    {
        if (dsNV[i].getFullName() == name)
        {
            return dsNV + i;
        }
    }
}

// 7. Có bao nhiêu nhân viên sinh trong tháng 5
int CongTy::countEmployeeHasBirthdayInMay()
{
    int num = 0;
    for (int i = 0; i < count; i++)
    {
        if (dsNV[i].getBirthdate().substr(3, 2) == "05")
        {
            num++;
        }
    }
    return num;
}

// 8. Thêm 1 nhân viên vào danh sách
void CongTy::addEmployee(NVSanXuat nvsx)
{
    if (dsNV == NULL)
    {
        dsNV = new NhanVien[1];
    }
    else
    {
        NhanVien *temp = new NhanVien[count + 1];
        for (int i = 0; i < count; i++)
        {
            temp[i] = dsNV[i];
        }
        delete[] dsNV;
        dsNV = temp;
    }
    count++;
    dsNV[count - 1] = nvsx;
}

void CongTy::addEmployee(NVCongNhat nvcn)
{
    if (dsNV == NULL)
    {
        dsNV = new NhanVien[1];
    }
    else
    {
        NhanVien *temp = new NhanVien[count + 1];
        for (int i = 0; i < count; i++)
        {
            temp[i] = dsNV[i];
        }
        delete[] dsNV;
        dsNV = temp;
    }
    count++;
    dsNV[count - 1] = nvcn;
}

// 9. Xóa 1 nhân viên khỏi danh sách
void CongTy::deleteEmployee()
{
    cout << "\nNhap ma nhan vien can xoa: ";
    string id;
    fflush(stdin);
    getline(cin, id);

    for (int i = 0; i < count; i++)
    {
        if (dsNV[i].getID() == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                dsNV[j] = dsNV[j + 1];
            }
            count--;
            cout << "\nDa xoa nhan vien ID: " << id  << " ra khoi ds ... " << endl;
            return;
        }
    }
}

// 10. Ghi tất cả các nhân viên có lương nhỏ hơn lương trung bình của công ty lên file 'emp_LowerAvgSalary.dat'
void CongTy::writeEmployeeLowerAvgSalaryToFile()
{
    ofstream fout("emp_LowerAvgSalary.dat", ios::out);
    if (fout.fail())
    {
        cout << "\nKhong mo duoc file emp_LowerAvgSalary.dat";
        return;
    }
    fout << avgSalaryOfAll() << endl;
    for (int i = 0; i < count; i++)
    {
        if (dsNV[i].getSalary() < avgSalaryOfAll())
        {
            fout << dsNV[i].getID() << " - " << dsNV[i].getFullName() << " - " << dsNV[i].getSalary() << endl;
        }
    }
}
