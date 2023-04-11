#include "Registrar.h"

// define
Registrar::Registrar() {

}


// ------------------------------------------------

    // 1. Đọc danh sách khóa học từ file
    void Registrar:: readCoursesFromFile(char* fileName) {
        // file courses:
        // id, name, classes, list students 

        string line;
        ifstream fin(fileName);
        if (fin.fail()) {
            cout << "\n...Error opening " << fileName << " ... \n";
            return ;
        }
        vector <char*> info;
        while (getline(fin, line)) {
            char* str = new char[line.length() + 1];
            strcpy(str, line.c_str());
            
            // start split string and set info to course

        }
        
    }

    // 2. Sinh viên đăng ký khóa học
    void Registrar:: registerCourse() {
        
    }

    // 3. Ghi danh sách sinh viên lên file
    void Registrar:: writeStudentsIntoFile(char* fileName) {
        
    }

    // 4. Đọc danh sách sinh viên từ file, xuất ra màn hình
    void Registrar:: printStudents(char* fileName) {
        
    }

    // 5. In danh sách sinh viên của một khóa học
    void Registrar:: printStudentsOfCourse() {
        
    }

    // 6. In thời khóa biểu của sinh viên(ds khóa học sinh viên đã đăng ký)
    void Registrar:: printSchedule() {
        
    }


// -----------------------------------------------