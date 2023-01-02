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

void Student::setFirstName(string firstName) {
    _firstName = firstName;
}

void Student::setMiddleName(string middleName) {
    _middleName = middleName;
}

void Student::setLastName(string lastName) {
    _lastName = lastName;
}

string Student::toString() const {
    stringstream ss;
    ss << _firstName << " " << _middleName << " " << _lastName;
    return ss.str();
}

istream& operator >> (istream& is, Student* student) {
    cout << "Enter the first name: ";
    getline(is, student->_firstName);
    cout << "Enter the middle name: ";
    getline(is, student->_middleName);
    cout << "Enter the last name: ";
    getline(is, student->_lastName);
    return is;
}

ostream& operator << (ostream& os, const Student* student) {
    os << student->toString();
    return os;
}

