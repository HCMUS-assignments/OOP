#include "QLPhim.h"
#include <string>

int main()
{
    QLPhim ql;
    do
    {
        cout << "\n--------------------MENU--------------------" << endl;
        cout << "1. Them phim vao danh sach." << endl;
        cout << "2. Doc danh sach phim tu file." << endl;
        cout << "3. Ghi danh sach phim ra file." << endl;
        cout << "4. Xoa cac phim co nha san xuat la HBO." << endl;
        cout << "5. Thoat." << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Nhap lua chon: ";
        int choice;
        fflush(stdin);
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Phim phim;
            cin >> phim;
            ql.addPhim(phim);
        }
        break;

        case 2:
            ql.readFromFile();
            break;
        case 3:
            ql.writeToFile();
            break;
        case 4:
            ql.deleteHBO();
            break;
        case 5:
            return 225;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    } while (true);

    return 225;
}