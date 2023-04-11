#include "Day.h"

// define
// constructors
Day::Day()
{
    _name = NULL;
    _subMorning = NULL;
    _subAfternoon = NULL;
}

Day::Day(char *name, char *subMorning, char *subAfternoon)
{
    _name = new char[strlen(name) + 1];
    _subMorning = new char[strlen(subMorning) + 1];
    _subAfternoon = new char[strlen(subAfternoon) + 1];

    strcpy(_name, name);
    strcpy(_subMorning, subMorning);
    strcpy(_subAfternoon, subAfternoon);
}

Day::Day(const Day &other)
{
    _name = new char[strlen(other._name) + 1];
    _subMorning = new char[strlen(other._subMorning) + 1];
    _subAfternoon = new char[strlen(other._subAfternoon) + 1];

    strcpy(_name, other._name);
    strcpy(_subMorning, other._subMorning);
    strcpy(_subAfternoon, other._subAfternoon);
}

Day &Day::operator=(Day &other)
{
    if (this != &other)
    {
        if (_name)
        {
            delete[] _name;
        }
        if (_subMorning)
        {
            delete[] _subMorning;
        }
        if (_subAfternoon)
        {
            delete[] _subAfternoon;
        }

        _name = new char[strlen(other._name) + 1];
        _subMorning = new char[strlen(other._subMorning) + 1];
        _subAfternoon = new char[strlen(other._subAfternoon) + 1];

        strcpy(_name, other._name);
        strcpy(_subMorning, other._subMorning);
        strcpy(_subAfternoon, other._subAfternoon);
    }

    return *this;
}

// destructure
Day::~Day()
{
    if (_name != NULL)
    {
        delete[] _name;
    }
    if (_subMorning != NULL)
    {
        delete[] _subMorning;
    }
    if (_subAfternoon != NULL)
    {
        delete[] _subAfternoon;
    }
}

// setters
void Day::setNameDay(char *name)
{
    if (_name != NULL)
    {
        delete[] _name;
    }
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
}

void Day::setSubMorning(char *subject)
{
    if (_subMorning != NULL)
    {
        delete[] _subMorning;
    }
    _subMorning = new char[strlen(subject) + 1];
    strcpy(_subMorning, subject);
}

void Day::setSubAfternoon(char *subject)
{
    if (_subAfternoon != NULL)
    {
        delete[] _subAfternoon;
    }
    _subAfternoon = new char[strlen(subject) + 1];
    strcpy(_subAfternoon, subject);
}

// getters
char *Day::getNameDay()
{
    return _name;
}

char *Day::getSubMorning()
{
    return _subMorning;
}

char *Day::getSubAfternoon()
{
    return _subAfternoon;
}