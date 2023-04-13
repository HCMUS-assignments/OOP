#include "Utils.h"

// define
int Utils::Menu()
{
    cout << endl
         << endl;
    cout << setw(35) << setfill(' ') << "CHƯƠNG TRÌNH ĐĂNG KÝ KHÓA HỌC" << setw(35);
    cout << endl;
    cout << setw(20) << setfill('-') << "MENU" << setw(20) << setfill('-');
    cout << "1. Đọc danh sách khóa học từ file. " << endl;
    cout << "2. Đăng ký khóa học." << endl;
    cout << "3. Ghi danh sách sinh viên lên file." << endl;
    cout << "4. Đọc danh sách sinh viên từ file, xuất ra màn hình." << endl;
    cout << "5. In danh sách sinh viên của một khóa học. " << endl;
    cout << "6. In thời khóa biểu của sinh viên." << endl;
    cout << "7. Thoát chương trình." << endl;
    cout << setw(20) << setfill('-') << "----" << setw(20) << setfill('-');

    cout << endl;
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