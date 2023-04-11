#include "Course.h"
#include "Student.h"
#include "Utils.h"

#include <bits/stdc++.h>

void randomCourses(int size, char *fileName)
{
    // id, name, schedule, Roster(arrayStudentNames: NULL)
    // list ids
    char IDs[] = "ADD00031, ADD00032, ADD00033, BAA00003, BAA00004, BAA00005, BAA00006, BAA00007, BAA00008, BAA00101, BAA00102, BAA00103, BAA00104, CSC10001, CSC10002, CSC10003, CSC10004, CSC10006, CSC10008, CSC10009, CSC13102, MTH00030, MTH00040, MTH00051, MTH00052, MTH00053";

    // list name courses
    char nameCourses[] = "Anh van 1, Anh van 2, Anh van 3, Tu tuong Ho Chi Minh, Phap luat dai cuong, Kinh te dai cuong, Tam ly dai cuong, Phuong phap luan sang tao, Ky nang lam viec nhom va hoc tap, Triet hoc Mac-LeNin, Kinh te chinh tri Mac-LeNin, Chu nghia xa hoi khoa hoc, Lich su Dang Cong san Viet Nam, Nhap mon lap trinh, Ky thuat lap trinh, Phuong phap lap trinh huong doi tuong, Cau truc du lieu va giai thuat, Co so du lieu, Mang may tinh, He thong may tinh, Lap trinh ung dung Java, Dai so tuyen tinh, Xac suat thong ke, Toan ung dung va thong ke, Phuong phap tinh, Ly thuyet so";

    // list day of week
    char days[] = "Mon, Tues, Wed, Thurs, Fri, Sat, Sun";

    // list time
    char time[] = "Morning, Afternoon";

    // convert into vector string
    vector<char *> listIDs = Utils::Split(IDs);
    vector<char *> listCourses = Utils::Split(nameCourses);
    vector<char *> listDays = Utils::Split(days);
    vector<char *> listClasses = Utils::Split(time);

    cout << "course:\n";
    for (int i = 0; i < listCourses.size(); i++)
    {
        cout << listCourses[i] << endl;
    }

    vector<Course> list;
    for (int count = 0; count < size; count++)
    {
        // max classes a week
        int maxClasses = 2;

        // max courses
        int maxCourses = listCourses.size();
        cout << "list size" << listCourses.size() << endl;
        Course newCourse;

        while (true)
        {
            newCourse.clearSchedule();
            int numRan = rand() % maxCourses;
            newCourse.setId(listIDs[numRan]);
            newCourse.setName(listCourses[numRan]);

            int numTime = rand() % maxClasses + 1;
            vector<vector<int>> listTime;
            cout << "....huhu44\n";
            cout << "num time: " << numTime << endl;
            for (int d = 0; d < numTime;)
            {
                // random i classes a week
                int ranDay = rand() % 7;
                int ranTime = rand() % 2;

                // check whether this time exist before or not
                int i = 0;
                for (i = 0; i < listTime.size(); i++)
                {
                    if (listTime[i][0] == ranDay && listTime[i][1] == ranTime)
                    {
                        break;
                    }
                }
                if (listTime.size() > 0 && i < listTime.size())
                {
                    continue;
                }

                // push time into list to check whether following random time is same or not
                vector<int> newTime;
                newTime.push_back(ranDay);
                newTime.push_back(ranTime);
                listTime.push_back(newTime);

                // set schedule
                cout << "\nSet schedule...\n";

                char *nameDay = new char[strlen(listDays[ranDay]) + 1];
                char *nameTime = new char[strlen(listClasses[ranTime]) + 1];
                strcpy(nameDay, listDays[ranDay]);
                strcpy(nameTime, listClasses[ranTime]);

                newCourse.setSchedule(nameDay, nameTime);
                cout << "\nsuccess 70 \n";
                // increase count
                d++;
            }

            // check if this course is exist before or not
            cout << "....huhu76\n";

            int i = 0;
            cout << "list size: " << list.size() << endl;

            for (i = 0; i < list.size(); i++)
            {
                // if exist, continue to loop
                if (strcmp(list[i].getId(), newCourse.getId()) == 0 && strcmp(list[i].getName(), newCourse.getName()) == 0)
                {
                    // check schedule
                    if (list[i].getSizeSchedule() == newCourse.getSizeSchedule())
                    {
                        break;
                    }
                }
            }
            cout << "list size: " << list.size() << endl;
            if (i < list.size())
            {
                continue;
            }

            // add to list and break
            cout << "\n...start to push...\n";
            list.push_back(newCourse);
            break;
            cout << "\n...come here\n";
        }
    }

    // write to file
    ofstream fout(fileName);
    if (fout.fail())
    {
        cout << "\nError opening file ... \n";
        return;
    }
    cout << "\n...come here...\n";
    for (int count = 0; count < size; count++)
    {
        string timeTable = "{";
        int numClasses = list[count].getSizeSchedule();
        vector<Day> schedule = list[count].getSchedule();

        for (int d = 0; d < numClasses - 1; d++)
        {
            timeTable.append(schedule[d].getNameDay());
            timeTable.append(": ");
            timeTable.append("(");
            timeTable.append(schedule[d].getSubMorning());
            timeTable.append(", ");
            timeTable.append(schedule[d].getSubAfternoon());
            timeTable.append("), ");
        }
        timeTable.append(schedule[numClasses - 1].getNameDay());
        timeTable.append(": ");
        timeTable.append("(");
        timeTable.append(schedule[numClasses - 1].getSubMorning());
        timeTable.append(", ");
        timeTable.append(schedule[numClasses - 1].getSubAfternoon());
        timeTable.append(")");

        timeTable.append("}");

        fout << list[count].getId() << ", " << list[count].getName() << ", " << timeTable << ", "
             << "{}" << endl;
    }
    fout.close();
}

void randomStudents(int size, char *fileName)
{
    // id, fullname, birthday, address, Schedule(arrayCourseNames)
    vector<Student> list;
    for (int i = 0; i < size; i++)
    {
        // random id
        string _id = "2112";
        int randID = rand() % 600 + 1000;
        _id.append(to_string(randID));

        // find in list if this id is exist before or not
        int j = 0;
        for (j = 0; j < list.size(); j++)
        {
            if (strcmp(list[j].getId(), _id.c_str()) == 0)
            {
                break;
            }
        }
        if (j < list.size())
        {
            i--;
            continue;
        }

        // random fullname
        string _fullname = "";
        string firstName[] = {"Nguyen", "Vo", "Bui", "Tran", "Le", "Pham", "Hoang", "Phan", "Dang", "Do", "Ngo", "Phung", "Truong"};
        string lastName[] = {"Anh", "Bao", "Chau", "Dung", "Hai", "Khanh", "Linh", "Minh", "Nga", "Phuong", "Quynh", "Thao", "Thuy", "Trang", "Van", "Yen"};
        string midName[] = {"", "Thi", "Thanh", "Thuy", "Manh", "Hong", "Son", "Ngoc", "Duc", "Hai", "Huong", "Tuan", "Trung", "Thien"};
        _fullname += firstName[rand() % 13] + " ";
        _fullname += midName[rand() % 14] + " ";
        _fullname += lastName[rand() % 16];

        for (j = 0; j < list.size(); j++)
        {
            if (strcmp(list[j].getFullname(), _fullname.c_str()) == 0)
            {
                break;
            }
        }
        if (j < list.size())
        {
            i--;
            continue;
        }

        // random bỉthday
        int day = rand() % 30 + 1;
        int month = rand() % 12 + 1;
        int year = rand() % 35 + 1970;
        if (month == 2 && day > 28)
            day = 28;
        string _bd = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

        // random address
        string _address = "";
        string listAdd[] = {"Quang Ngai", "Quang Nam", "Quang Binh", "Quang Tri", "Quang Ninh", "Da Nang", "Hue", "Hai Phong", "Ha Noi", "Ho Chi Minh", "Can Tho", "Vinh Long", "Binh Dinh", "Binh Thuan", "Binh Phuoc", "Binh Duong"};
        _address += listAdd[rand() % 16];

        // add to list
        Student newStudent((char*) _id.c_str(),(char*) _fullname.c_str(), (char*) _bd.c_str(), (char*) _address.c_str());
        list.push_back(newStudent);
    }

    // write to file
    ofstream fout(fileName);
    if (fout.fail())
    {
        cout << "\nError opening file ... \n";
        return;
    }

    for (int count = 0; count < size; count++)
    {
        fout << list[count].getId() << ", " << list[count].getFullname() << ", " << list[count].getBirthday() << ", "
             << list[count].getAddress() << ", " << "{}" << endl;
    }
    fout.close();
}

int main()
{
    // random data courses -> file listOfCourses.txt
    char fileCourse[] = "listOfCourses.txt";
    randomCourses(50, fileCourse);

    // random date students -> file listOfStudents.txt
    char fileStudents[] = "listOfStudents.txt";
    randomStudents(400, fileStudents);

    return 225;
}