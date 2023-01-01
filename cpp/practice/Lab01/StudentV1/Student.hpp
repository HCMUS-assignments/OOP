#ifndef _STUDENT_HPP
#define _STUDENT_HPP

#include <string>
#include <iostream>
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

        // getters
        string getFirstName();
        string getMiddleName();
        string getLastName();

        // setters
        void setFirstName(string firstName);
        void setMiddleName(string middleName);
        void setLastName(string lastName);

        // other methods
        friend ostream& operator<<(ostream& os, const Student student);
        friend istream& operator>>(istream& is, Student& student);
};

#endif