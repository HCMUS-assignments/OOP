#include "Utils.h"

// define
int Utils::Menu()
{
    cout << endl
         << endl;
    cout << setw(10) << setfill(' ') << "" << "CHƯƠNG TRÌNH ĐĂNG KÝ KHÓA HỌC" << setw(40) << setfill(' ');
    cout << endl << endl << endl;
    cout << setw(30) << setfill('-') << "MENU" << setw(30) << setfill('-') << "-" << endl;
    cout << "1. Đọc danh sách khóa học từ file. " << endl;
    cout << "2. Đọc danh sách sinh viên từ file." << endl;
    cout << "3. Đăng ký khóa học." << endl;
    cout << "4. Ghi danh sách sinh viên lên file." << endl;
    cout << "5. In danh sách sinh viên của một khóa học. " << endl;
    cout << "6. In thời khóa biểu của sinh viên." << endl;
    cout << "7. In danh sách khóa học. " << endl;
    cout << "8. In danh sách sinh viên. " << endl;
    cout << "9. In thông tin một khóa học." << endl;
    cout << "10. Thoát chương trình." << endl;
    cout << setw(60) << setfill('-')  << "-" ;

    cout << setfill(' ') << endl << endl;
    cout << "Nhập lựa chọn: ";
    int choice;
    fflush(stdin);
    cin >> choice;
    return choice;
}

vector<char *> Utils::Split(char *str)
{
    char *token;
    vector<char *> tokens;
    char *delim = new char[3];
    strcpy(delim, ",");
    token = strtok(str, delim);
    while (token != NULL)
    {
        token = standardized(token);
        tokens.push_back(token);
        token = strtok(NULL, delim);
    }
    return tokens;
}

char *Utils::standardized(char *src)
{
    int i = 0;
    while (src[i] == ' ')
    {
        i++;
    }
    strcpy(src, src + i);
    i = strlen(src) - 1;
    while (src[i] == ' ')
    {
        i--;
    }
    src[i + 1] = '\0';
    return src;
}