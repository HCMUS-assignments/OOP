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

        // 1. Ghi danh sách nhân viên vào file 'ds_NhanVien.dat'
        void write();

        // 2. Đọc danh sách nhân viên từ file 'ds_NhanVien.dat'
        void read();

        // 3. Xuất danh sách nhân viên ra màn hình
        void print();

        // 4. Tính tổng tiền lương của tất cả các nhân viên
        int sumSalaryOfAll();

        // 5. Tìm nhân viên có lương cao nhất
        void findMaxSalary();

        // 6. Tính lương trung bình trong công ty
        float avgSalaryOfAll();

        // 7. Nhập vào mã, tìm nhân viên tương ứng
        void findEmployeeById();

        // 8. Nhập vào tên, tìm nhân viên tương ứng
        void findEmployeeByName();

        // 9. Có bao nhiêu nhân viên sinh trong tháng 5
        int countEmployeeHasBirthdayInMay();

        // 10. Thêm 1 nhân viên vào danh sách
        void addEmployee();
        void addEmployee(NVSanXuat  *&nvsx);
        void addEmployee(NVCongNhat *&nvcn);

        // 11. Xóa 1 nhân viên khỏi danh sách
        void deleteEmployee();

        // 12. Ghi tất cả các nhân viên có lương nhỏ hơn lương trung bình của công ty lên file 'emp_LowerAvgSalary.dat'
        void writeEmployeeLowerAvgSalaryToFile();


        // ----------- 


};

#endif