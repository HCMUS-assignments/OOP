#include "Student.hpp"

Student::Student() {
    _firstName = "";
    _middleName = "";
    _lastName = "";
}

Student::Student(string firstName, string middleName, string lastName) {
    _firstName = firstName;
    _middleName = middleName;
    _lastName = lastName;
}

Student::Student(const Student& student) {
    _firstName = student._firstName;
    _middleName = student._middleName;
    _lastName = student._lastName;
}

Student::~Student() {
    // nothing to do
}

string Student::getFirstName() {
    return _firstName;
}

string Student::getMiddleName() {
    return _middleName;
}

string Student::getLastName() {
    return _lastName;
}

string Student::getFullName() {
    return _firstName + " " + _middleName + " " + _lastName;
}

void Student::setFirstName(string firstName) {
    _firstName = firstName;
}

void Student::setMiddleName(string middleName) {
    _middleName = middleName;
}

void Student::setLastName(string lastName) {
    _lastName = lastName;
}

ostream& operator<<(ostream& os, const Student student) {
    os << student._firstName << " " << student._middleName << " " << student._lastName;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    cout << "Enter first name: ";
    getline(is, student._firstName);
    cout << "Enter middle name: ";
    getline(is, student._middleName);
    fflush(stdin);
    cout << "Enter last name: ";
    getline(is, student._lastName);
    return is;
}