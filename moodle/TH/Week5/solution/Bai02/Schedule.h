#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Day.h"
#include "Utils.h"
#include <vector>
#include <iomanip>
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
    Day getAt(char* name) ;
    void setAt(char* name, char* subject, char* time);
    void setDay(char* name, char* sub1, char* sub2);

    // other methods
    void print();



};

#endif