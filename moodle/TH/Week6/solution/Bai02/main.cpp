#include "CongTy.h"
#include <windows.h>
#include <iomanip>

string convertSalary(int);


int main()
{

    SetConsoleOutputCP(65001);

    // create object
    CongTy company;

    while (true)
    {
        // menu
        cout << endl;
        cout << setw(40) << setfill('_') << "MENU" << setw(40) << setfill('_') << "" << endl
             << endl;
        cout << "1. Đọc danh sách nhân viên từ tập tin (ds_NhanVien.dat)." << endl;
        cout << "2. Xuất danh sách nhân viên ra tập tin (ds_NhanVien.dat)." << endl;
        cout << "3. Xuất danh sách nhân viên ra màn hình." << endl;
        cout << "4. Tính tổng tiền lương của tất cả các nhân viên." << endl;
        cout << "5. Tìm nhân viên có lương cao nhất." << endl;
        cout << "6. Tính lương trung bình của công ty." << endl;
        cout << "7. Tìm nhân viên theo ID." << endl;
        cout << "8. Tìm nhân viên theo tên." << endl;
        cout << "9. Số nhân viên sinh trong tháng 5." << endl;
        cout << "10. Thêm 1 nhân viên vào danh sách." << endl;
        cout << "11. Xóa 1 nhân viên khỏi danh sách." << endl;
        cout << "12. Thoát." << endl;
        cout << setw(84) << setfill('_') << "" << endl;
        cout << "\nChọn chức năng: ";
        int choice;
        fflush(stdin);
        cin >> choice;

        switch (choice)
        {
        case 1:
            company.read();
            break;

        case 2:
            company.write();
            break;
        case 3:
            company.print();
            break;
        case 4:
            cout << "Tổng tiền lương của tất cả các nhân viên là: " << convertSalary(company.sumSalaryOfAll()) << endl;
            break;
        case 5:
            company.findMaxSalary();
            break;

        case 6:
            cout << "Lương trung bình của công ty là: " << convertSalary(int(company.avgSalaryOfAll())) << endl;
            break;
        case 7:
            company.findEmployeeById();
            break;
        case 8:
            company.findEmployeeByName();
            break;
        case 9:
            cout << "Số nhân viên sinh trong tháng 5 là: " << company.countEmployeeHasBirthdayInMay() << endl;
            break;
        case 10:
            company.addEmployee();
            break;

        case 11:
            company.deleteEmployee();
            break;

        case 12:
            cout << endl
                 << setw(40) << setfill('_') << "END" << setw(40) << setfill('_') << "" << endl;
            return 225;
        default:
            cout << "Chức năng chưa được cài đặt." << endl;
            break;
        }

    }

}
