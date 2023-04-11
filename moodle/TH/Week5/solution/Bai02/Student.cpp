#include "Student.h"

// define
Student::Student() {
    _id = NULL;
    _fullname = NULL;
    _birthday = NULL;
    _address = NULL;
    
    maxCourse = 5;
    numCourseRegistered = 0;

}

Student::~Student() {
    if (_id) {
        delete[] _id;
    }
    if (_fullname) {
        delete[] _fullname;
    }
    if (_birthday) {
        delete[] _birthday;
    }
    if (_address) {
        delete[] _address;
    }
}

int Student::getNumCourseCanRegister() {
    return maxCourse - numCourseRegistered;
}