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