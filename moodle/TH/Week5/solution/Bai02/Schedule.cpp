#include "Schedule.h"

// define
Schedule::Schedule() {
    char *arrayNames = "Mon, Tues, Wed, Thurs, Fri, Sat, Sun";
    vector<char*> names = Utils::Split(arrayNames);

    for (auto i = 0; i < names.size(); i++) {
        Day dayOfWeek(names[i], "x", "x");
        week.push_back(dayOfWeek);
    }

    if (arrayNames != NULL) {
        delete arrayNames;
    }

    for (auto i = 0; i < names.size(); i++ ) {
        delete names[i];
    }
}


// getters
Day& Schedule::at(char* name) {
    for (auto i = 0; i < week.size(); i++) {
        if (strcmp(week[i].getNameDay(), name) == 0) {
            return week[i];
        }
    }
}


