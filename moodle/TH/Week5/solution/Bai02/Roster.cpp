#include "Roster.h"

// define
Roster::Roster() {
    cap = 40;
}

Roster::Roster(const Roster& other) {
    cap = other.cap;
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
        cap = other.cap;
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

int Roster::getSize() {
    return studentNames.size();
}

char* Roster::getSizeStr() {
    string res = to_string(getSize()) + "/" + to_string(cap);
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