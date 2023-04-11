#ifndef STUDENT_H
#define STUDENT_H

#include "Schedule.h"

class Student {
private:
    char* _id;
    char* _fullname;
    char* _birthday;
    char* _address;
    Schedule _timeTable;

    int maxCourse;
    int numCourseRegistered;

public:
    // constructor
    Student();

    // destructor
    ~Student();

    // getters
    int getNumCourseCanRegister();
    


};

#endif