#include "Roster.h"

// define
Roster::Roster() {  
    _cap = 40;   // _capacity default
}

Roster::Roster(int capacity) {
    _cap = capacity;
}

Roster::Roster(const Roster& other) {
    _cap = other._cap;
    int size = other.studentNames.size();
    for (int i = 0; i < size; i++) {
        Info info;
        info._id = new char[strlen(other.studentNames[i]._id) + 1];
        info._name = new char[strlen(other.studentNames[i]._name) + 1];

        strcpy(info._id, other.studentNames[i]._id);
        strcpy(info._name, other.studentNames[i]._name);

        studentNames.push_back(info);
    }
}

Roster& Roster::operator=(Roster &other) {
    if (this != &other) {
        _cap = other._cap;
        int size = other.studentNames.size();
        for (int i = 0; i < size; i++) {
            Info info;
            info._id = new char[strlen(other.studentNames[i]._id) + 1];
            info._name = new char[strlen(other.studentNames[i]._name) + 1];

            strcpy(info._id, other.studentNames[i]._id);
            strcpy(info._name, other.studentNames[i]._name);

            studentNames.push_back(info);
        }
    }
    return *this;
} 


// setters
void Roster::reSize(int max) {
    _cap = max;
}

// getters
int Roster::getSize() {
    return studentNames.size();
}

char* Roster::getSizeStr() {
    string res = to_string(getSize()) + "/" + to_string(_cap);
    char* str = NULL;
    strcpy(str, res.c_str());
    return str;
}

void Roster::addStudent(char* id, char* name) {
    Info info;
    info._id = new char[strlen(id) + 1];
    info._name = new char[strlen(name) + 1];

    strcpy(info._id, id);
    strcpy(info._name, name);

    studentNames.push_back(info);
}

void Roster::print() {
    for (int i = 0; i < studentNames.size(); i++) {
        cout << i + 1 << ". " << studentNames[i]._id << " - " << studentNames[i]._name << endl;
    }
}

// other methods
int Roster::getMaxSize() {
    return _cap;
}