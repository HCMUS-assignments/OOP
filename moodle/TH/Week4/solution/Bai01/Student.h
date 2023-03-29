#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"


class Student : public Person { 
    private:
        double gpa;
    public:
        // constructors
        Student();
        Student(long id, double gpa);

        // destructor
        ~Student();

        // copy constructor
        Student(const Student&);

        // getter
        double getGPA() const;

        // setter
        void setGPA(double _gpa);

        // other methods
        void print();

        // assignment operator
        Student& operator= (const Student&);

};

#endif