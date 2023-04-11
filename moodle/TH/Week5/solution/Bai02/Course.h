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
        int getSizeSchedule();
        vector<Day> getSchedule();



};

#endif