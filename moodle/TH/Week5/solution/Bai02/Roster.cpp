#include "Roster.h"

// define
Roster::Roster() {
    cap = 40;
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