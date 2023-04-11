#include "Course.h"

// define

Course::Course()
{
    _id = NULL;
    _name = NULL;
}

Course::Course(const Course &other)
{
    _id = new char[strlen(other._id) + 1];
    _name = new char[strlen(other._name) + 1];

    strcpy(_id, other._id);
    strcpy(_name, other._name);

    // list day
    schedule.clear();
    cout << "add schedule course...\n";
    for (int i = 0; i < other.schedule.size(); i++)
    {
        schedule.push_back(other.schedule[i]);
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
        for (int i = 0; i < other.schedule.size(); i++)
        {
            schedule.push_back(other.schedule[i]);
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
    cout << "... start set schedule...\n";
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
    schedule.push_back(newDay);

    cout << "... end set schedule...\n";
    cout << "size: " << getSizeSchedule() << endl;
    cout << "Schedule: \n";
    for (int i = 0; i < schedule.size(); i++)
    {
        cout << "Day " << i + 1 << " : " << schedule[i].getNameDay() << " " << schedule[i].getSubMorning() << " " << schedule[i].getSubAfternoon() << endl;
    }
}

void Course::clearSchedule() {
    schedule.clear();
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
    return schedule.size();
}

vector<Day> Course::getSchedule()
{
    return schedule;
}
