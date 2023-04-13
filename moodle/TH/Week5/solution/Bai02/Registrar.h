#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Student.h"
#include "Course.h"
#include "Utils.h"

#include <string.h>
#include <vector>
#include <fstream>
using namespace std;


class Registrar {
private:
    vector<Student> _listOfStudents;
    vector<Course> _listOfCourses;

public:

    // constructor
    Registrar();
    

    // ------------------------------------------------------

    // 1. Đọc danh sách khóa học từ file
    void readCoursesFromFile(const char* fileName);

    // 2. Sinh viên đăng ký khóa học
    void registerCourse();

    // 3. Ghi danh sách sinh viên lên file
    void writeStudentsIntoFile(const char* fileName);

    // 4. Đọc danh sách sinh viên từ file, xuất ra màn hình
    void printStudents(const char* fileName);

    // 5. In danh sách sinh viên của một khóa học
    void printStudentsOfCourse();

    // 6. In thời khóa biểu của sinh viên(ds khóa học sinh viên đã đăng ký)
    void printSchedule();

    // --------------------------------------------------------


    // other methods
    void run();



};

#endif