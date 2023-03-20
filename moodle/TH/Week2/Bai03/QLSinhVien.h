#include "SinhVien.h"
#include <time.h>

#ifndef _QLSINHVIEN_H
#define _QLSINHVIEN_H

struct Node
{
    SinhVien data;
    Node *next;
    char *classification;

    Node () {
        next = NULL;
        classification = NULL;
    }

};

class QLSinhVien
{
private:
    Node *head;
    int size;
    float avgMarkClass;

    ifstream fin;
    ofstream fout;

public:
    // default constructor
    QLSinhVien();

    // destructor
    ~QLSinhVien();

    // methods

    // 3.  write list of students in file: viết hàm ghi danh sách sinh viên lên tập tin
    void write();

    // 4. read list of students from file: đọc danh sách sinh viên từ tập tin
    void read();

    // 5. find the students having the average score less than class's one, then write that list in file
    //      : tìm các sinh viên có đtb nhỏ hơn đtb của cả lớp, ghi dssv vào tập tin
    void find();

    // 6. add a new student in list and update file: thêm sv mới vào ds, cập nhật tập tin
    void add();

    // 7. classify the students: xếp loại sinh viên
    void classify();

    // 8. output list of students with classification inf: xuất thông tin sinh viên có thông tin xếp loại
    void output_classification();

    // 9. find all students having the same birthday with the present day
    //      : tìm tất cả sv có cùng ngày sinh trong ngày hiện tại
    void findSameBirthday();

};

#endif