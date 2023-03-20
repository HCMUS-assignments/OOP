#include "QLSinhVien.h"

// default constructor
QLSinhVien::QLSinhVien()
{
    size = 0;
    avgMarkClass = 0;
    head = NULL;
}

// destructor
QLSinhVien::~QLSinhVien()
{
    if (head != NULL)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            temp = head->next;
            delete head->classification;
            head->data.~SinhVien();
            head = temp;
        }
    }
}

// methods

// 3.  write list of students in file
void QLSinhVien::write()
{
    if (head == NULL)
    {
        cout << "\nDon't have any student in list ...\n";
        return;
    }

    fout.open("DSSV.txt", ios::out);
    if (fout.fail())
    {
        cout << "\nCan't open file DSSV.txt...\n";
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        fout << temp->data;
        temp = temp->next;
    }

    fout.close();
}

// 4. read list of students from file: mặc định đọc theo định dạng có cả đtb do đề kh đề cập rõ
void QLSinhVien::read()
{
    fin.open("DSSV.txt", ios::in);
    if (fin.fail())
    {
        cout << "Can't open file DSSV.txt ...\n";
        return;
    }
    if (head != NULL)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
        if (size != 0)
        {
            size = 0;
        }
        if (avgMarkClass != 0)
        {
            avgMarkClass = 0;
        }
    }

    SinhVien temp;
    while (fin >> temp)
    {
        Node *pNode = new Node;
        pNode->data = temp;
        pNode->next = NULL;

        if (head == NULL)
        {
            head = pNode;
        }
        else
        {
            Node *tail = head;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = pNode;
        }
        avgMarkClass = avgMarkClass + pNode->data.avg_mark();
        size++;
    }
    // calculate avg score of class
    avgMarkClass = avgMarkClass / size;
    fin.close();
}

// 5. find the students having the average score less than class's one, then write that list in file
void QLSinhVien::find()
{
    if (avgMarkClass == 0)
    { // trường hợp chưa tính đtb
        Node *temp = head;
        while (temp->next != NULL)
        {
            avgMarkClass += temp->data.avg_mark();
        }
    }
    avgMarkClass = avgMarkClass / size;

    fout.open("DSSV_YC5.txt", ios::out);
    if (fout.fail())
    {
        cout << " Can't open DSSV_YC5.txt ...\n";
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.avg_mark() < avgMarkClass)
        {
            fout << temp->data;
        }
        temp = temp->next;
    }
    fout.close();
}

// 6. add a new student in list and update file
void QLSinhVien::add()
{
    SinhVien sv;
    cin >> sv;
    sv.calcAvg();

    Node *pNode = new Node;
    pNode->data = sv;
    pNode->next = NULL;

    if (head == NULL)
    {
        head = pNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pNode;
    }
    size++;

    // update file
    fout.open("DSSV.txt", ios::app); // ios::app move to the end of file
    if (fout.fail())
    {
        cout << "Can't open file DSSV.txt\n";
        return;
    }
    fout << sv;
    fout.close();
}

// 7. classify the students
void QLSinhVien::classify()
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.avg_mark() >= 8)
        {
            strcpy(temp->classification, "Gioi\0");
        }
        else
        {
            if (temp->data.avg_mark() < 8 && temp->data.avg_mark() >= 6)
            {
                strcpy(temp->classification, "Kha\0");
            }
            else
            {
                strcpy(temp->classification, "Trung binh\0");
            }
        }
        temp = temp->next;
    }
}

// 8. output list of students with classification inf
void QLSinhVien::output_classification()
{
    fout.open("DSSV_classification.txt", ios::out);
    if (fout.fail())
    {
        cout << "Can't open file DSSV_classification.txt ... \n";
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        fout << temp->data.id() << " " << temp->data.fullname() << " " << temp->data.birthday() << " " << temp->data.avg_mark() << " -> "
             << temp->classification << endl;
        temp = temp->next;
    }
    fout.close();
}

// 9. find all students having the same birthday with the present day
void QLSinhVien::findSameBirthday()
{
    // đề không yêu cầu ghi hay xuất rõ ràng nên mặc định ghi file

    // get the present day
    time_t t = time(0); // get time now
    struct tm *now = localtime(&t);
    int d = now->tm_mday;
    int m = now->tm_mon + 1;
    int y = now->tm_year + 1900;

    // convert dd/mm/yy -> string
    char *presentDay = new char[50];
    if (d < 10)
    {
        sprintf(presentDay, "%c%d", '0', d);
    }
    else
    {
        sprintf(presentDay, "%d", d);
    }
    sprintf(presentDay + 2, "/");

    if (m < 10)
    {
        sprintf(presentDay + 3, "%c%d", '0', m);
    }
    else
    {
        sprintf(presentDay + 3, "%d", m);
    }
    sprintf(presentDay + 5, "/");
    sprintf(presentDay + 6, "%d", y);

    fout.open("DSSV_happyBirthday.txt", ios::out);
    if (fout.fail()) {
        cout << "Can't open file DSSV_happyBirthday.txt ...\n";
        return ;
    }
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.birthday(), presentDay) == 0) {
            fout << temp->data;
        }
        temp = temp->next;
    }
    fout.close();
}