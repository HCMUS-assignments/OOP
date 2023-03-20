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
            delete head;
            head = temp;
        }
    }
}

// methods

// 3.  write list of students in file
void QLSinhVien::write()
{

}

// 4. read list of students from file
void QLSinhVien::read()
{
}

// 5. find the students having the average score less than class's one, then write that list in file
void QLSinhVien::find()
{
}

// 6. add a new student in list and update file
void QLSinhVien::add()
{
    SinhVien sv;
    cin >> sv;
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
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = pNode;
    }
    size++;

    // update file
    fout.open("DSSV.txt", ios::app); // ios::app move to the end of file
    if (fout.fail()) {
        cout << "Can't open file DSSV.txt\n";
        return;
    }
    fout << sv;
    fout.close();
}

// 7. classify the students
void QLSinhVien::classify()
{
}

// 8. output list of students with classification inf
void QLSinhVien::output_classification()
{
}

// 9. find all students having the same birthday with the present day
void QLSinhVien::findSameBirthday()
{
}