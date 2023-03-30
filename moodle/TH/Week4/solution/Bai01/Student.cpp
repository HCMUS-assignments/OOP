#include "Student.h"

Student::Student(long id, double GPA) : Person(id), gpa(GPA)
{
    assert(GPA >= 0.0 && GPA <= 10.0);
}

// cài đặt các constructors và assignment operators
// constructors
Student::Student()
{
    cout << "\nconstructor student called\n";
    gpa = 0;
}

// destructor
Student::~Student()
{
}

// copy constructor
Student::Student(const Student &another)
{
    identity = another.identity;
    gpa = another.gpa;
    cout << "\ncopy constructor student called\n";
}

// getter
double Student::getGPA() const
{
    return gpa;
}

// setter
void Student::setGPA(double _gpa)
{
    gpa = _gpa;
}

// other methods
void Student::print()
{
    cout << "\nStudent [ID, GPA] :  " << identity << ", " << gpa << endl; 
}

// assignment operator
Student &Student ::operator=(const Student &s)
{
    cout << "\nassignment operator student called\n";
    if (this != &s) {
        identity = s.identity;
        gpa = s.gpa;
    }
    return *this;
}