#include "Student.h"

// define
Student::Student()
{
    _id = NULL;
    _fullname = NULL;
    _birthday = NULL;
    _address = NULL;

    maxCourse = 5;
    numCourseRegistered = 0;
}

Student::Student(char *id, char *fullname, char *birthday, char *address)
{
    _id = new char[strlen(id) + 1];
    _fullname = new char[strlen(fullname) + 1];
    _birthday = new char[strlen(birthday) + 1];
    _address = new char[strlen(address) + 1];

    strcpy(_id, id);
    strcpy(_fullname, fullname);
    strcpy(_birthday, birthday);
    strcpy(_address, address);

    maxCourse = 5;
    numCourseRegistered = 0;
}

Student::Student(const Student &other)
{
    _id = new char[strlen(other._id) + 1];
    _fullname = new char[strlen(other._fullname) + 1];
    _birthday = new char[strlen(other._birthday) + 1];
    _address = new char[strlen(other._address) + 1];

    strcpy(_id, other._id);
    strcpy(_fullname, other._fullname);
    strcpy(_birthday, other._birthday);
    strcpy(_address, other._address);

    maxCourse = other.maxCourse;
    numCourseRegistered = other.numCourseRegistered;
}

Student &Student::operator=(Student &other)
{
    if (this != &other)
    {
        if (_id)
        {
            delete[] _id;
        }
        if (_fullname)
        {
            delete[] _fullname;
        }
        if (_birthday)
        {
            delete[] _birthday;
        }
        if (_address)
        {
            delete[] _address;
        }

        _id = new char[strlen(other._id) + 1];
        _fullname = new char[strlen(other._fullname) + 1];
        _birthday = new char[strlen(other._birthday) + 1];
        _address = new char[strlen(other._address) + 1];

        strcpy(_id, other._id);
        strcpy(_fullname, other._fullname);
        strcpy(_birthday, other._birthday);
        strcpy(_address, other._address);

        maxCourse = other.maxCourse;
        numCourseRegistered = other.numCourseRegistered;
    }

    return *this;
}

Student::~Student()
{
    if (_id)
    {
        delete[] _id;
    }
    if (_fullname)
    {
        delete[] _fullname;
    }
    if (_birthday)
    {
        delete[] _birthday;
    }
    if (_address)
    {
        delete[] _address;
    }
}

// setters
void Student::setTimeTable(char *timeTable)
{
    // timeTable format: {Mon: (Math, Physic), Tues: (Math, Physic), Wed: (Math, Physic), Thurs: (Math, Physic), Fri: (Math, Physic), Sat: (Math, Physic), Sun: (Math, Physic)}
    string timeTableStr = timeTable;
    // ignore { and }
    timeTableStr = timeTableStr.substr(1, timeTableStr.length() - 2);
    while (timeTableStr.length() > 0)
    {
        string name, sub1, sub2;
        int pos = timeTableStr.find_first_of(':');
        name = timeTableStr.substr(0, pos);
        // ignore space and (
        timeTableStr = timeTableStr.substr(pos + 2, timeTableStr.length() - 2 - pos);
        pos = timeTableStr.find_first_of(',');
        sub1 = timeTableStr.substr(0, pos);
        // ignore , and space
        timeTableStr = timeTableStr.substr(pos + 2, timeTableStr.length() - pos - 2);
        pos = timeTableStr.find_first_of(')');
        sub2 = timeTableStr.substr(0, pos);
        _timeTable.setDay((char*) name.c_str(), (char*) sub1.c_str(), (char*) sub2.c_str());
        // ignore )
        timeTableStr = timeTableStr.substr(pos + 1, timeTableStr.length() - pos - 1);
        // ignore , if have
        if (timeTableStr.length() > 0) {
        timeTableStr = timeTableStr.substr(1, timeTableStr.length() - 1);
        }
    }
}

void Student::printSchedule()
{
    _timeTable.print();
}

int Student::getNumCourseCanRegister()
{
    return maxCourse - numCourseRegistered;
}

int Student::getNumCourseJoined()
{
    return numCourseRegistered;
}

char *Student::getId()
{
    return _id;
}

char *Student::getFullname()
{
    return _fullname;
}

char *Student::getBirthday()
{
    return _birthday;
}

char *Student::getAddress()
{
    return _address;
}

// relate to schedule and timetable
char *Student::getScheduleStr()
{
    string str = "{";
    char dayOfWeeek[] = "Mon, Tues, Wed, Thurs, Fri, Sat, Sun";
    vector<char *> days = Utils::Split(dayOfWeeek);

    for (int i = 0; i < days.size(); i++)
    {
        str += days[i];
        str += ": (";
        Day day = _timeTable.getAt(days[i]);
        str += day.getSubMorning();
        str += ", ";
        str += day.getSubAfternoon();
        str += ")";
        ;
        if (i != days.size() - 1)
        {
            str += ", ";
        }
    }
    str += "}";
    return (char *)str.c_str();
}

Schedule Student::getTimeTable()
{
    return _timeTable;
}