#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Student {
    private:
        string _firstName;
        string _middleName;
        string _lastName;

    public:

        // constructors
        Student();
        Student(string firstName, string middleName, string lastName);

        // copy constructor
        Student(const Student& student);

        // destructor
        ~Student();

        // getters
        string getFirstName();
        string getMiddleName();
        string getLastName();

        // setters
        void setFirstName(string firstName);
        void setMiddleName(string middleName);
        void setLastName(string lastName);

        string toString() const;
};

#endif