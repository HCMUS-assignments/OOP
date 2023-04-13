#ifndef STUDENT_H
#define STUDENT_H

#include "Schedule.h"
#include "Utils.h"

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
    Student(char* id, char* fullname, char* birthday, char* address);
    Student(const Student& other);
    Student& operator= (Student &other);

    // destructor
    ~Student();

    // setters
    void setTimeTable(char* timeTable);

    // getters
    int getNumCourseJoined();
    int getNumCourseCanRegister();

    char* getId();
    char* getFullname();
    char* getBirthday();
    char* getAddress();

    // relate to schedule
    char* getScheduleStr();
    void printSchedule();
    Schedule getTimeTable();
    


};

#endif