#include "SinhVien.h"

#ifndef _QLSINHVIEN_H
#define _QLSINHVIEN_H

struct Node
{
    SinhVien data;
    Node *next;

    float avgMarkClass;
};

class QLSinhVien
{
private:
    Node *head;
    int count;

public:
    // default constructor
    QLSinhVien();

    // destructor
    ~QLSinhVien();

    // methods

    // 3.  write list of students in file
    void write();

    // 4. read list of students from file
    void read();

    // 5. find the students having the average score less than class's one, then write that list in file
    void find();

    // 6. add a new student in list and update file
    void add(SinhVien &);

    // 7. classify the students
    void classify();

    // 8. output list of students with classification inf
    void output_classification();

    // 9. find all students having the same birthday with the present day
    void findSameBirthday();

};

#endif