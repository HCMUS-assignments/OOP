#ifndef COURSE_H
#define COURSE_H

#include "Day.h"
#include "Roster.h"
#include <vector>
using namespace std;

class Course {
    private:
        char* _id;
        char* _name;

        vector<Day> _schedule;
        Roster _list;

    public:
        // constructor
        Course() ;
        Course(char* id, char* name, char* schedule, char* list);
        Course(const Course& other);
        Course& operator= (Course &other);

        // setters
        void setId(char* id);
        void setName(char* name);
        void setSchedule(char* nameDay, char* time);
        void clearSchedule();

        // getters
        char* getId();
        char* getName();

        // methods with schedule
        int getSizeSchedule();
        vector<Day> getSchedule();
        string getScheduleStr();

        // list of students joined this course
        Roster getRoster();

        // get size of this course
        // number of student currently
        int getSizeCourse();    

        // capacity of course
        int getMaxSizeOfCourse();




};

#endif