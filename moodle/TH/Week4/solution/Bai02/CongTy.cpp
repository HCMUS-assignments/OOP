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

// 1. Nhập, xuất danh sách các nhân viên (file)
void CongTy::input()
{


}
void CongTy::output()
{
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
void CongTy::addEmployee()
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
    // --------------------
}

// 9. Xóa 1 nhân viên khỏi danh sách
void CongTy::deleteEmployee()
{
}

// 10. Ghi tất cả các nhân viên có lương nhỏ hơn lương trung bình của công ty lên file 'emp_LowerAvgSalary.dat'
void CongTy::writeEmployeeLowerAvgSalaryToFile()
{
}
