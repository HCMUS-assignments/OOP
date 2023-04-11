#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Day.h"
#include "Utils.h"
#include <vector>
using namespace std;

class Schedule {
    private:
        vector<Day> week;

    public:
    // constructor
    Schedule();
    Schedule(const Schedule& other);
    Schedule& operator= (Schedule &other);


    // getters
    Day& at(char* name) ;



};

#endif