#ifndef CONGTY_H
#define CONGTY_H

#include "NhanVien.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"
#include <fstream>
#include <sstream>
#include <string.h>

struct Node {
    NhanVien *data;
    Node *pNext;
};

class CongTy {
    private:
        Node *head;
        int count;
        int sumSalary;
        float avgSalary;

    public:
        // Constructor
        CongTy();

        // Destructor
        ~CongTy();

        // assignment operator
        CongTy& operator=(const CongTy& other);


        // other methods

        // 1. Nhập, xuất danh sách các nhân viên
        void read();
        void write();

        // 2. Tính tổng tiền lương của tất cả các nhân viên
        int sumSalaryOfAll();

        // 3. Tìm nhân viên có lương cao nhất
        void findMaxSalary();

        // 4. Tính lương trung bình trong công ty
        float avgSalaryOfAll();

        // 5. Nhập vào mã, tìm nhân viên tương ứng
        NhanVien* findEmployeeById();

        // 6. Nhập vào tên, tìm nhân viên tương ứng
        NhanVien* findEmployeeByName();

        // 7. Có bao nhiêu nhân viên sinh trong tháng 5
        int countEmployeeHasBirthdayInMay();

        // 8. Thêm 1 nhân viên vào danh sách
        void addEmployee();
        void addEmployee(NVSanXuat  *&nvsx);
        void addEmployee(NVCongNhat *&nvcn);

        // 9. Xóa 1 nhân viên khỏi danh sách
        void deleteEmployee();

        // 10. Ghi tất cả các nhân viên có lương nhỏ hơn lương trung bình của công ty lên file 'emp_LowerAvgSalary.dat'
        void writeEmployeeLowerAvgSalaryToFile();

};

#endif