#include "Schedule.h"

// define
Schedule::Schedule() {
    char arrayNames[] = "Mon, Tues, Wed, Thurs, Fri, Sat, Sun";
    vector<char*> names = Utils::Split(arrayNames);

    for (auto i = 0; i < names.size(); i++) {
        char *mark = new char[2];
        strcpy(mark, "x");
        Day dayOfWeek(names[i], mark, mark);
        week.push_back(dayOfWeek);
    }

    for (auto i = 0; i < names.size(); i++ ) {
        delete names[i];
    }
}

Schedule::Schedule(const Schedule& other) {
    for (auto i = 0; i < other.week.size(); i++) {
        week.push_back(other.week[i]);
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


