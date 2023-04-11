#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <string.h>
#include <string>
using namespace std;

struct Info {
    char* _id;
    char* _name;
};

class Roster {
    private:
        vector<Info> studentNames;
        int cap;    // max = 40
    public:
        // constructor
        Roster();
        Roster(const Roster& other);
        Roster& operator= (Roster &other);

        // getters
        int getSize();

        char* getSizeStr();




};

#endif