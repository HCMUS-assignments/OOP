#include "Course.h"

// define

Course::Course()
{
    _id = NULL;
    _name = NULL;
}

Course::Course(char *id, char *name, char *schedule, char *list)
{
    _id = new char[strlen(id) + 1];
    _name = new char[strlen(name) + 1];

    strcpy(_id, id);
    strcpy(_name, name);

    // schedule
    string schedule_str = schedule;
    // ignore { and }
    schedule_str = schedule_str.substr(1, schedule_str.length() - 2);

    // declare variables
    string dayName_str = "";
    string morning = "";
    string afternoon = "";
    
    while (schedule_str.length() > 0)
    {
        // get day name
        int pos = schedule_str.find(":");
        dayName_str = schedule_str.substr(0, pos);
        schedule_str = schedule_str.substr(pos + 1, schedule_str.length() - pos - 1);

        // get morning and afternoon
        // ignore ( 
        schedule_str = schedule_str.substr(1, schedule_str.length() - 1);
        pos = schedule_str.find(",");
        morning = schedule_str.substr(0, pos);
        schedule_str = schedule_str.substr(pos + 1, schedule_str.length() - pos - 1);

        pos = schedule_str.find(")");
        afternoon = schedule_str.substr(0, pos);
        schedule_str = schedule_str.substr(pos + 1, schedule_str.length() - pos - 1);

        // add day to schedule
        Day day((char*) dayName_str.c_str(), (char*) morning.c_str(), (char*) afternoon.c_str());
        _schedule.push_back(day);

        // ignore , and space if have
        if (schedule_str.length() > 0)
        {
            schedule_str = schedule_str.substr(2, schedule_str.length() - 2);
        }
    }

    // split list student if have
    // format: {1. (id, name), 2. (id, name), ...}
    // ignore { and }
    string roster_str = list;
    roster_str = roster_str.substr(1, roster_str.length() - 2);
    while (roster_str.length() > 0) {
        // ignore number order
        int pos = roster_str.find("(");
        roster_str = roster_str.substr(pos + 1, roster_str.length() - pos - 1);
        pos = roster_str.find(",");
        string id_str = roster_str.substr(0, pos);
        roster_str = roster_str.substr(pos + 2, roster_str.length() - pos - 2); // ignore space
        pos = roster_str.find(")");
        string name_str = roster_str.substr(0, pos);

        // add student to roster
        _list.addStudent((char*) id_str.c_str(), (char*) name_str.c_str());

        // ignore )
        roster_str = roster_str.substr(pos + 1, roster_str.length() - pos - 1);

        // ignore , and space if have
        if (roster_str.length() > 0)
        {
            roster_str = roster_str.substr(2, roster_str.length() - 2);
        }
    }
}

Course::Course(const Course &other)
{
    _id = new char[strlen(other._id) + 1];
    _name = new char[strlen(other._name) + 1];

    strcpy(_id, other._id);
    strcpy(_name, other._name);

    // list day
    _schedule.clear();
    cout << "add schedule course...\n";
    for (int i = 0; i < other._schedule.size(); i++)
    {
        _schedule.push_back(other._schedule[i]);
    }
    cout << "add schedule course success...\n";
}

Course &Course::operator=(Course &other)
{
    if (this != &other)
    {
        if (_id)
        {
            delete[] _id;
        }
        if (_name)
        {
            delete[] _name;
        }
        _id = new char[strlen(other._id) + 1];
        _name = new char[strlen(other._name) + 1];

        strcpy(_id, other._id);
        strcpy(_name, other._name);

        // list day
        for (int i = 0; i < other._schedule.size(); i++)
        {
            _schedule.push_back(other._schedule[i]);
        }
    }

    return *this;
}

// setters
void Course::setId(char *id)
{
    _id = new char[strlen(id) + 1];
    strcpy(_id, id);
}

void Course::setName(char *name)
{
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
}

void Course::setSchedule(char *nameDay, char *time)
{
    cout << "... start set _schedule...\n";
    cout << "size: " << getSizeSchedule() << endl;
    cout << "\nName day: " << nameDay << endl;
    cout << "\nTime: " << time << endl;

    Day newDay;
    char *exist = new char[2];
    char *notExist = new char[2];

    strcpy(exist, "x");
    strcpy(notExist, " ");
    newDay.setNameDay(nameDay);
    cout << "\n...set name succces...\n";

    if (strcmp(time, "Morning") == 0)
    {
        newDay.setSubMorning(exist);
        newDay.setSubAfternoon(notExist);
    }
    else
    {
        newDay.setSubMorning(notExist);
        newDay.setSubAfternoon(exist);
    }
    _schedule.push_back(newDay);

    cout << "... end set _schedule...\n";
    cout << "size: " << getSizeSchedule() << endl;
    cout << "Schedule: \n";
    for (int i = 0; i < _schedule.size(); i++)
    {
        cout << "Day " << i + 1 << " : " << _schedule[i].getNameDay() << " " << _schedule[i].getSubMorning() << " " << _schedule[i].getSubAfternoon() << endl;
    }
}

void Course::clearSchedule()
{
    _schedule.clear();
}

// getters
char *Course::getId()
{
    return _id;
}

char *Course::getName()
{
    return _name;
}

int Course::getSizeSchedule()
{
    return _schedule.size();
}

vector<Day> Course::getSchedule()
{
    return _schedule;
}

string Course::getScheduleStr() {
    string res = "";
    for (int i = 0; i < _schedule.size(); i++) {
        res += _schedule[i].getNameDay();
        res += "(";
        if (strcmp(_schedule[i].getSubMorning(), "x") == 0) {
            res += "1-4";
        } else {
            res += "6-9";
        }
        res += ")";
        if (i < _schedule.size() - 1) {
            res += ", ";
        }
    }
}

Roster Course::getRoster() {
    return _list;
}