#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Student.h"
#include "Course.h"
#include <vector>
using namespace std;


class Registrar {
private:
    vector<Student> _listOfStudents;
    vector<Course> _listOfCourse;

public:
    // 1. Đọc danh sách khóa học
    void readCourses();

    // 2. Sinh viên đăng ký khóa học
    void registerCourse();

    // 3. Ghi danh sách sinh viên lên file
    void writeStudents();

    // 4. Đọc danh sách sinh viên từ file, xuất ra màn hình
    void printStudents();

    // 5. In danh sách sinh viên của một khóa học
    void printStudentsOfCourse();

    // 6. In thời khóa biểu của sinh viên(ds khóa học sinh viên đã đăng ký)
    void printSchedule();

};

#endif