#include "Schedule.h"

// define
Schedule::Schedule()
{
    char arrayNames[] = "Mon, Tues, Wed, Thurs, Fri, Sat, Sun";
    vector<char *> names = Utils::Split(arrayNames);

    for (auto i = 0; i < names.size(); i++)
    {
        char *mark = new char[2];
        strcpy(mark, "x");
        Day dayOfWeek(names[i], mark, mark);
        week.push_back(dayOfWeek);
    }

    for (auto i = 0; i < names.size(); i++)
    {
        delete names[i];
    }
}

Schedule::Schedule(const Schedule &other)
{
    for (auto i = 0; i < other.week.size(); i++)
    {
        week.push_back(other.week[i]);
    }
}

// getters
Day Schedule::getAt(char *name)
{
    for (auto i = 0; i < week.size(); i++)
    {
        if (strcmp(week[i].getNameDay(), name) == 0)
        {
            return week[i];
        }
    }
}

void Schedule::setAt(char *name, char *subject, char *time)
{
    for (auto i = 0; i < week.size(); i++)
    {
        cout << "\ncome here...\n";
        if (strcmp(week[i].getNameDay(), name) == 0)
        {
            cout << "\n...setting time table\n";
            if (strcmp(time, "morning") == 0)
            {
                week[i].setSubMorning(subject);
            }
            else
            {
                week[i].setSubAfternoon(subject);
            }
            break;
        }
    }
}

void Schedule::setDay(char *name, char *sub1, char *sub2)
{
    for (int i = 0; i < week.size(); i++)
    {
        if (strcmp(week[i].getNameDay(), name) == 0)
        {
            week[i].setSubMorning(sub1);
            week[i].setSubAfternoon(sub2);
            return;
        }
    }
}

void Schedule::print()
{
    // print the name day [Mon, Tues ,. ...]
    cout << endl
         << "|   ";
    for (int i = 0; i < week.size(); i++)
    {
        cout << setw(5) << setfill(' ') << week[i].getNameDay() << setw(5) << setfill(' ');
        cout << "|";
    }
    // print the subject of morning
    cout << endl
         << "|   ";
    for (int i = 0; i < week.size(); i++)
    {
        cout << setw(5) << setfill(' ') << week[i].getSubMorning() << setw(5) << setfill(' ');

        cout << "|";
    }

    // print the subject of afternoon
    cout << endl
         << "|   ";
    for (int i = 0; i < week.size(); i++)
    {
        cout << setw(5) << setfill(' ') << week[i].getSubAfternoon() << setw(5) << setfill(' ');

        cout << "|";
    }

    cout << endl
         << endl;
}
