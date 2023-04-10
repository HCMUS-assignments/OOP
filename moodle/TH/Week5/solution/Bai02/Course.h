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
        char* _start;
        vector<Day> classes;

        Roster list;

    public:

};

#endif