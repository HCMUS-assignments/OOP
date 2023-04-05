#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <windows.h>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int d;
    int m;
    int y;

public:
    Date();
    Date(string);

            // operator
        bool operator==(const Date&);
        bool operator!=(const Date&);
        bool operator>(const Date&);
        bool operator>=(const Date&);
        bool operator<(const Date&);
        bool operator<=(const Date&);

    // getters
    int getDay();
    int getMonth();
    int getYear();

    string toStr();

};

#endif

Date::Date()
{
    d = 0;
    m = 0;
    y = 0;
}

Date::Date(string bd)
{
    // split the first /
    int pos = bd.find_first_of('/');
    d = stoi(bd.substr(0, pos));
    bd = bd.substr(pos + 1);
    pos = bd.find_first_of('/');
    m = stoi(bd.substr(0, pos));
    y = stoi(bd.substr(pos + 1));
}

// operator
bool Date::operator==(const Date &another)
{
    if (d == another.d && m == another.m && y == another.y)
        return true;
    return false;
}
bool Date::operator!=(const Date &another)
{
    if (d != another.d || m != another.m || y != another.y)
        return true;
    return false;
}
bool Date::operator>(const Date &another)
{
    if (y > another.y)
        return true;
    else if (y == another.y)
    {
        if (m > another.m)
            return true;
        else if (m == another.m)
        {
            if (d > another.d)
                return true;
        }
    }
    return false;
}
bool Date::operator>=(const Date &another)
{
    if (y > another.y)
        return true;
    else if (y == another.y)
    {
        if (m > another.m)
            return true;
        else if (m == another.m)
        {
            if (d >= another.d)
                return true;
        }
    }
    return false;
}
bool Date::operator<(const Date &another)
{
    if (y < another.y)
        return true;
    else if (y == another.y)
    {
        if (m < another.m)
            return true;
        else if (m == another.m)
        {
            if (d < another.d)
                return true;
        }
    }
    return false;
}
bool Date::operator<=(const Date &another)
{
    if (y < another.y)
        return true;
    else if (y == another.y)
    {
        if (m < another.m)
            return true;
        else if (m == another.m)
        {
            if (d <= another.d)
                return true;
        }
    }
    return false;
}

string Date::toStr()
{
    return to_string(d) + "/" + to_string(m) + "/" + to_string(y);
}

int Date::getDay()
{
    return d;
}
int Date::getMonth()
{
    return m;
}
int Date::getYear()
{
    return y;
}

#ifndef SINGER_H
#define SINGER_H

class Singer
{
protected:
    string fullname;
    string id;
    Date birthday;
    int numAlbum;
    int numShow;
    int numFollow;

public:
    // constructors
    Singer();
    Singer(string fn, string _id, string bd, int na, int ns, int nf);

    // copy constructor
    Singer(const Singer &other);

    // operator =
    Singer &operator=(const Singer &other);

    // other methods
    virtual int getSalary();

    // getters
    string getID();
    string getFullname();
    string getBirthday();
    int getNumAlb();
    int getNumShow();
    int getNumFollow();

    // overloading cin and cout
    virtual void input(istream &is);
    virtual void output(ostream &os);
    friend istream &operator>>(istream &is, Singer &p);
    friend ostream &operator<<(ostream &os, Singer &p);

    // check whether this singer is famous or not
    virtual bool isFamousSinger();
};

#endif

// define
Singer::Singer()
{
    fullname = "";
    id = "";
    birthday = Date();
    numAlbum = 0;
    numShow = 0;
    numFollow = 0;
}

Singer::Singer(string fn, string _id, string bd, int na, int ns, int nf)
{
    fullname = fn;
    id = _id;
    birthday = Date(bd);
    numAlbum = na;
    numShow = ns;
    numFollow = nf;
}

Singer::Singer(const Singer &other)
{
    fullname = other.fullname;
    id = other.id;
    birthday = other.birthday;
    numAlbum = other.numAlbum;
    numShow = other.numShow;
    numFollow = other.numFollow;
}

Singer &Singer ::operator=(const Singer &other)
{
    if (this != &other)
    {
        fullname = other.fullname;
        id = other.id;
        birthday = other.birthday;
        numAlbum = other.numAlbum;
        numShow = other.numShow;
        numFollow = other.numFollow;
    }

    return *this;
}

int Singer::getSalary()
{
    return 3000000 + 250000 * numShow;
}

string Singer::getID()
{
    return id;
}

string Singer::getFullname()
{
    return fullname;
}
string Singer::getBirthday()
{
    return birthday.toStr();
}
int Singer::getNumAlb()
{
    return numAlbum;
}
int Singer::getNumShow()
{
    return numShow;
}
int Singer::getNumFollow()
{
    return numFollow;
};

bool Singer::isFamousSinger()
{
    return false;
}

void Singer::input(istream &is)
{
}
void Singer::output(ostream &os)
{
}
istream &operator>>(istream &is, Singer &p)
{
    p.input(is);
    return is;
}
ostream &operator<<(ostream &os, Singer &p)
{
    p.output(os);
    return os;
}

#ifndef FAMOUSSINGER_H
#define FAMOUSSINGER_H

class FamousSinger : public Singer
{
private:
    int numGameShow;

public:
    // constructors
    FamousSinger();
    FamousSinger(string fn, string _id, string bd, int na, int ns, int nf, int ng);

    // copy constructor
    FamousSinger(const FamousSinger &other);

    // operator =
    FamousSinger &operator=(const FamousSinger &other);

    // other methods
    int getSalary();
    int getNumGameShow();

    // overloading cin and cout
    void input(istream &is);
    void output(ostream &os);

    bool isFamousSinger();
};

#endif

// define

FamousSinger::FamousSinger()
{
    fullname = "";
    id = "";
    birthday = Date();
    numAlbum = 0;
    numShow = 0;
    numFollow = 0;

    numGameShow = 0;
}
FamousSinger::FamousSinger(string fn, string _id, string bd, int na, int ns, int nf, int ng)
{
    fullname = fn;
    id = _id;
    birthday = Date(bd);
    numAlbum = na;
    numShow = ns;
    numFollow = nf;

    numGameShow = ng;
}

// copy constructor
FamousSinger::FamousSinger(const FamousSinger &other)
{
    fullname = other.fullname;
    id = other.id;
    birthday = other.birthday;
    numAlbum = other.numAlbum;
    numShow = other.numShow;
    numFollow = other.numFollow;
    numGameShow = other.numGameShow;
}

// operator =
FamousSinger &FamousSinger ::operator=(const FamousSinger &other)
{
    if (this != &other)
    {
        fullname = other.fullname;
        id = other.id;
        birthday = other.birthday;
        numAlbum = other.numAlbum;
        numShow = other.numShow;
        numFollow = other.numFollow;
        numGameShow = other.numGameShow;
    }
    return *this;
}

// other methods
int FamousSinger::getSalary()
{
    return 20000000 + 500000 * numShow + 5000000 * numGameShow;
}

int FamousSinger::getNumGameShow()
{
    return numGameShow;
}

void FamousSinger ::input(istream &is)
{
}
void FamousSinger ::output(ostream &os)
{
}

bool FamousSinger ::isFamousSinger()
{
    return true;
}

#ifndef LISTSINGER_H
#define LISTSINGER_H

class ListSinger
{
private:
    vector<Singer *> list;

public:
    // constructors
    ListSinger();

    // 2. Toán tử nhập xuất cho các ca sĩ
    void enterList();
    void outputList();

    // 3. Xóa một ca sĩ nào đó khi nhập vào mã số
    void del(string _id);

    // yêu cầu:
    // Khi người dùng nhập 1 con số, chương trình tạo ngẫu nhiên thông tin các ca sĩ
    void random(int num);

    // 4.  Thống kê xem công ty có bao nhiêu ca sĩ nổi tiếng và chưa nổi tiếng
    void countSingers();

    // 5. Nhập vào số tháng, hãy tính tổng tiền lương mà công ty phải trả cho từng ca sĩ
    int sumSalary(int month);

    // 6. Người dùng nhập ngày tháng năm sinh, hãy liệt kê 3 ca sĩ có khoảng cách gần ngày tháng năm sinh đó nhất
    void nearBirthday(string bd);
};

#endif

ListSinger ::ListSinger()
{
}

void ListSinger ::enterList()
{
    cout << "\nSố lượng ca sĩ: ";
    int num;
    fflush(stdin);
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "\n--- Nhập thông tin ca sĩ thứ  " << i + 1 << endl;
        cout << "Họ tên: ";
        string _fullname;
        fflush(stdin);
        getline(cin, _fullname);
        cout << "Mã số: ";
        string _id;
        fflush(stdin);
        getline(cin, _id);
        cout << "Ngày sinh (dd/mm/yyyy) : ";
        string bd;
        fflush(stdin);
        getline(cin, bd);
        cout << "Số lượng album đã phát hành: ";
        int _numAlb;
        cin.ignore();
        cin >> _numAlb;
        cout << "Số buổi trình diễn trong tháng: ";
        int _numShow;
        cin.ignore();
        cin >> _numShow;
        cout << "Số lượt theo dõi trên mạng xã hội: ";
        int _numFollow;
        cin.ignore();
        cin >> _numFollow;
        int _numGameShow;

        if (_numFollow > 1000000)
        {
            cout << "Số gameshow tham gia: ";
            cin.ignore();
            cin >> _numGameShow;
        }

        if (_numFollow > 1000000)
        {
            FamousSinger *temp = new FamousSinger(_fullname, _id, bd, _numAlb, _numShow, _numFollow, _numGameShow);
            list.push_back(temp);
        }
        else
        {
            Singer *temp = new Singer(_fullname, _id, bd, _numAlb, _numShow, _numFollow);
            list.push_back(temp);
        }
    }
}

void ListSinger::outputList()
{
    cout << "\n--- Thông tin danh sách ca sĩ\n\n";
    cout << setfill(' ') << setw(13) << left << "Mã số" << setw(30) << left <<  "Họ tên" << setw(20) << left << "Ngày sinh ";
    cout << setw(10) << left << "Album" << setw(17) << left << "Số show" << setw(15)  << left << "Follow";
    cout << setw(10) << left << "Số GShow" << endl << endl;

    for (int i = 0; i < list.size(); i++)
    {
        cout << setw(10) << left << list[i]->getID() << setw(27) << left << list[i]->getFullname() << setw(20) << left << list[i]->getBirthday();
        cout << setw(10) << left << list[i]->getNumAlb() << setw(15) << left << list[i]->getNumShow() << setw(17) << left << list[i]->getNumFollow();
        if (list[i]->isFamousSinger())
        {
            FamousSinger *p = (FamousSinger *)list[i];
            cout << setw(15) << left << p->getNumGameShow();
        }
        cout << endl;
    }
}

void ListSinger::del(string _id)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->getID() == _id)
        {
            list.erase(list.begin() + i);
        }
    }
}

void ListSinger::countSingers()
{
    int normal = 0;
    int famous = 0;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->isFamousSinger())
        {
            famous++;
        }
        else
        {
            normal++;
        }
    }
    cout << "\n--- Thống kê ca sĩ\n\n";
    cout << "Số ca sĩ nổi tiếng: " << famous << endl;
    cout << "Số ca sĩ chưa nổi tiếng: " << normal << endl;
}

int ListSinger::sumSalary(int month)
{
    int sum = 0;
    for (int i = 0; i < list.size(); i++)
    {
        sum += list[i]->getSalary() * month;
    }
    return sum;
}

void ListSinger::nearBirthday(string bd)
{
    // danh sách 3 người có ngày sinh gần bd nhất
    vector<Singer *> temp;

    // copy list to temp and sort by birthday
    for (int i = 0; i < list.size(); i++)
    {
        temp.push_back(list[i]);
    }

    for (int i = 0; i < temp.size() - 1; i++)
    {
        for (int j = i + 1; j < temp.size(); j++)
        {
            if (temp[i]->getBirthday() > temp[j]->getBirthday())
            {
                Singer *p = temp[i];
                temp[i] = temp[j];
                temp[j] = p;
            }
        }
    }

    // find 3 people near birthday
    int count = 0;
    Date birthday(bd);

    // ... not yet finish


}

void ListSinger::random(int num)
{
    // reset list
    list.clear();

    for (int i = 0; i < num; i++) {
        int _numAlb = rand() % 100;
        int _numShow = rand() % 100;
        int _numGameShow = rand() % 100;

        // random follow
        int type = rand() % 100;
        int _numFollow = 0;
        if (type % 2 == 0) {
            _numFollow = rand() % 1000000;
        } else {
            _numFollow = rand() % 1000000 + 1000000;
        }

        // random fullname
        string _fullname = "";
        string firstName[] = {"Nguyen", "Vo", "Bui", "Tran", "Le", "Pham", "Hoang", "Phan", "Dang", "Do", "Ngo", "Phung", "Truong"};
        string lastName[] = {"Anh", "Bao", "Chau", "Dung", "Hai", "Khanh", "Linh", "Minh", "Nga", "Phuong", "Quynh", "Thao", "Thuy", "Trang", "Van", "Yen"};
        string midName[] = {"", "Thi", "Thanh", "Thuy", "Manh", "Hong", "Son", "Ngoc", "Duc", "Hai", "Huong", "Tuan", "Trung", "Thien"};
        _fullname += firstName[rand() % 13] + " ";
        _fullname += midName[rand() % 14] + " ";
        _fullname += lastName[rand() % 16];
        
        // random id dạng CS00001, CS00002, CS00003, ...
        string _id = "CS";
        // số chữ số của i
        int n = 0;
        int temp = i;
        while (temp > 0) {
            temp /= 10;
            n++;
        }
        for (int j = 0; j < 5 - n; j++) {
            _id += "0";
        }
        if (i != 0) {
            _id += to_string(i);
        }

        // random bỉthday
        int day = rand() % 30 + 1;
        int month = rand() % 12 + 1;
        int year = rand() % 35 + 1970;
        if (month == 2 && day > 28)
            day = 28;
        string _bd = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        
        if (_numFollow > 1000000)
        {
            FamousSinger *temp = new FamousSinger(_fullname, _id, _bd, _numAlb, _numShow, _numFollow, _numGameShow);
            list.push_back(temp);
        }
        else
        {
            Singer *temp = new Singer(_fullname, _id, _bd, _numAlb, _numShow, _numFollow);
            list.push_back(temp);
        }
    }
}

int main()
{

    SetConsoleOutputCP(65001);

    // create object
    ListSinger qlcs;

    while (true)
    {
        // menu
        cout << endl;
        cout << setw(40) << right << setfill('_') << "MENU" << setw(40) << setfill('_') << "" << endl
             << endl;
        cout << "1. Nhập danh sách ca sĩ." << endl;
        cout << "2. Xuất danh sách ca sĩ." << endl;
        cout << "3. Xóa ca sĩ từ mã số." << endl;
        cout << "4. Random danh sách ca sĩ." << endl;
        cout << "5. Thống kê ca sĩ." << endl;
        cout << "6. Tính tổng lương ca sĩ trong n tháng." << endl;
        cout << "7. Tìm 3 ca sĩ có ngày sinh gần nhất." << endl;
        cout << "8. Thoát." << endl;
        cout << setw(84) << setfill('_') << "" << endl;
        cout << "\nChọn chức năng: " << setfill(' ');
        int choice;
        fflush(stdin);
        cin >> choice;

        string id, bd;

        switch (choice)
        {
        case 1:
            qlcs.enterList();
            break;

        case 2:
            qlcs.outputList();
            break;
        case 3:
            cout << "\nNhập mã số ca sĩ cần xóa: ";
            fflush(stdin);
            getline(cin, id);
            qlcs.del(id);
            break;
        case 4:
            int num;
            cout << "\nNhập số lượng ca sĩ cần random: ";
            cin.ignore();
            cin >> num;
            qlcs.random(num);
            break;

        case 5:
            qlcs.countSingers();
            break;
        case 6:
            int m;
            cout << "\nNhập số tháng: ";
            cin.ignore();
            cin >> m;
            cout << "\nTổng lương ca sĩ trong " << m << " tháng là: " << qlcs.sumSalary(m) << endl;
            break;
        case 7:
            cout << "\nNhập ngày sinh: ";
            fflush(stdin);
            getline(cin, bd);
            cout << "\n3 ca sĩ có ngày sinh gần nhất:\n";
            qlcs.nearBirthday(bd);
            break;
        case 8:
            cout << endl
                 << setw(40) << setfill('_') << "END" << setw(40) << setfill('_') << "" << endl;
            return 0;
        default:
            cout << "Chức năng chưa được cài đặt." << endl;
            break;
        }
    }
    return 225;
}