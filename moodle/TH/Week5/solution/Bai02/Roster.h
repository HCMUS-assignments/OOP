#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

struct Info {
    char* _id;
    char* _name;
};

class Roster {
    private:
        vector<Info> studentNames;
        int _cap;    // max = 40
    public:
        // constructor
        Roster();
        Roster(int capacity);
        Roster(const Roster& other);
        Roster& operator= (Roster &other);


        // setters
        // resize of course (change max cap) 
        void reSize(int max) ;

        // getters
        int getSize();
        char* getSizeStr();

        void addStudent(char* id, char* name);
        void print();

        // methods
        int getMaxSize();

        // add student
        void push(char* id, char* name);





};

#endif