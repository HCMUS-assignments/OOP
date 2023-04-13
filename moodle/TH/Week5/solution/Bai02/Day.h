#ifndef DAY_H
#define DAY_H

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Day
{
private:
    char *_name;
    char *_subMorning;
    char *_subAfternoon;
public:
    // constructor
    Day();
    Day(char* name, char* subMorning, char* subAfternoon);
    Day(const Day &other);
    Day& operator= (Day& other);

    // destructure
    ~Day();

    // setters
    void setNameDay(char* name);
    void setSubMorning(char* subject);
    void setSubAfternoon(char* subject);

    // getters
    char* getNameDay();
    char* getSubMorning();
    char* getSubAfternoon();

};

#endif

