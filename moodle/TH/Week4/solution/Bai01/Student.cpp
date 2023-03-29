#include "Student.h"

Student::Student(long id, double GPA) : Person(id), gpa(GPA) {
    assert(GPA >= 0.0 && GPA <= 10.0);
}

// cài đặt các constructors và assignment operators
        // constructors
        Student::Student() {

        }

        // destructor
        Student::~Student() {

        }

        // copy constructor
        Student::Student(const Student&) {

        }

        // getter
        double Student:: getGPA() const {

        }

        // setter
        void Student::setGPA(double _gpa) {

        }

        // other methods
        void Student:: print() {

        }

        // assignment operator
       Student& Student :: operator= (const Student& s) {

       }