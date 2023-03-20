#include "QLSinhVien.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    // create object
    QLSinhVien qlsv;

    while (true)
    {
        // menu
        cout << endl;
        cout << setw(40) << setfill('_') << "MENU" << setw(40) << setfill('_') << "" << endl << endl;
        cout << "1. Ghi danh sách sinh viên lên tập tin. (default: DSSV.txt)" << endl;
        cout << "2. Đọc danh sách sinh viên từ tập tin. (default: DSSV.txt)" << endl;
        cout << "3. Tìm các sinh viên có điểm trung bình nhỏ hơn điểm trung bình của lớp." << endl;
        cout << "4. Thêm sinh viên mới vào danh sách và cập nhật tập tin. (default: DSSV.txt)" << endl;
        cout << "5. Xếp loại sinh viên." << endl;
        cout << "6. Xuất thông tin sinh viên có thông tin xếp loại." << endl;
        cout << "7. Tìm tất cả sinh viên có cùng ngày sinh với ngày hiện tại." << endl;
        cout << "8. Thoát." << endl;
        cout << setw(84) << setfill('_') << "" << endl;
        cout << "\nChọn chức năng: ";
        int choice;
        fflush(stdin);
        cin >> choice;

        switch(choice) {
            case 1:
                qlsv.write();
                break;

            case 2:
                qlsv.read();
                break;
            case 3:
                qlsv.find();
                break;
            case 4:
                qlsv.add();
                break;

            case 5:
                qlsv.classify();
                break;
            case 6:
                qlsv.output_classification();
                break;
            case 7:
                qlsv.findSameBirthday();
                break;
            case 8:
                cout << endl << setw(40) << setfill('_') << "END" << setw(40) << setfill('_') << "" << endl;
                return 0;
            default:
                cout << "Chức năng chưa được cài đặt." << endl;
                break;
        }

    }
    return 225;
}