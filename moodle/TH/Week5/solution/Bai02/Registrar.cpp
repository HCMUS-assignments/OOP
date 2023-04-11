#include "Registrar.h"

// define
Registrar::Registrar()
{
}

// ------------------------------------------------

// 1. Đọc danh sách khóa học từ file
void Registrar::readCoursesFromFile(char *fileName)
{
    // file courses:
    // id, name, classes, list students
    _listOfCourses.clear();

    string line;
    ifstream fin(fileName);
    if (fin.fail())
    {
        cout << "\n...Error opening " << fileName << " ... \n";
        return;
    }
    while (getline(fin, line))
    {
        vector<char *> info;

        char *str = new char[line.length() + 1];
        strcpy(str, line.c_str());

        // start split string and set info to course
        // id
        char *token = strtok(str, ",");
        info.push_back(token);
        // name
        token = strtok(NULL, ",");
        info.push_back(token);
        // classes
        token = strtok(NULL, "},");

        // add } to end of string
        strcat(token, "}");
        info.push_back(token);

        // list students
        token = strtok(NULL, "}");
        // add } to end of string
        strcat(token, "}");
        info.push_back(token);

        // add info to course
        Course course(info[0], info[1], info[2], info[3]);
        _listOfCourses.push_back(course);
    }
    fin.close();
}

// 2. Sinh viên đăng ký khóa học
void Registrar::registerCourse()
{
    // 1. enter id of student
    Student student;
    string id;

    while (true)
    {
        cout << "\nEnter your ID: ";
        getline(cin, id);

        // find and return student info if have
        int i = 0;
        for (i = 0; i < _listOfStudents.size(); i++)
        {
            if (strcmp(_listOfStudents[i].getId(), id.c_str()) == 0)
            {
                student = _listOfStudents[i];
                break;
            }
        }
        if (i == _listOfStudents.size())
        {
            cout << "\n...Student not found... please enter again ...\n";
        }
        else
        {
            break;
        }
    }

    cout << "\nNumber course you joined: " << student.getNumCourseJoined() << endl;
    cout << "\nYou can register " << student.getNumCourseCanRegister() << " course(s)\n";

    // 2. print list course that student can register: not yet register (ID - Name - Schedule - Size)
    cout << "\nList of courses bellow: \n";
    for (int i = 0; i < _listOfCourses.size(); i++)
    {
        cout << _listOfCourses[i].getId() << " - " << _listOfCourses[i].getName() << " - ";
        cout << _listOfCourses[i].getScheduleStr() << " - " << _listOfCourses[i].getRoster().getSizeStr() << endl;
    }

    // 3. enter id of course that student want to register
    string idCourse;
    Course course;
    while (true)
    {
        cout << "\nEnter ID of course that you want to register: ";
        getline(cin, idCourse);

        // check if course is exist
        int i = 0;
        for (i = 0; i < _listOfCourses.size(); i++)
        {
            if (strcmp(_listOfCourses[i].getId(), idCourse.c_str()) == 0)
            {
                course = _listOfCourses[i];
                break;
            }
        }
        if (i == _listOfCourses.size())
        {
            cout << "\n...Course not found... please enter again ...\n";
        }
        else
        {
            break;
        }
    }

    // --------------- handle register course------------------------
    // 4. check if student can register course
}

// 3. Ghi danh sách sinh viên lên file
void Registrar::writeStudentsIntoFile(char *fileName)
{
    ofstream fout(fileName);
    // format: id, name, birthday, address, {course joined}
    for (int i = 0; i < _listOfStudents.size(); i++)
    {
        fout << _listOfStudents[i].getId() << "," << _listOfStudents[i].getFullname() << ", " << _listOfStudents[i].getBirthday() << ", " << _listOfStudents[i].getAddress() << ", ";
        fout << _listOfStudents[i].getScheduleStr() << endl;
    }
    fout.close();
}

// 4. Đọc danh sách sinh viên từ file, xuất ra màn hình
void Registrar::printStudents(char *fileName)
{
    _listOfStudents.clear();
    string line;
    ifstream fin(fileName);
    if (fin.fail())
    {
        cout << "\n...Error opening " << fileName << " ... \n";
        return;
    }
    while (getline(fin, line))
    {
        // handle reading line
        string id, name, birthday, address, schedule;
        int pos = 0;
        // id
        pos = line.find(",");
        id = line.substr(0, pos);
        line.erase(0, pos + 1);
        // name
        pos = line.find(",");
        name = line.substr(0, pos);
        line.erase(0, pos + 1);
        // birthday
        pos = line.find(",");
        birthday = line.substr(0, pos);
        line.erase(0, pos + 1);
        // address
        pos = line.find(",");
        address = line.substr(0, pos);
        line.erase(0, pos + 1);
        // schedule
        schedule = line;

        // add info to student
        Student student((char*) id.c_str(), (char*) name.c_str(), (char*) birthday.c_str(), (char*) address.c_str());
        student.setTimeTable((char*) schedule.c_str());

        _listOfStudents.push_back(student);
    }
    fin.close();
}

// 5. In danh sách sinh viên của một khóa học
void Registrar::printStudentsOfCourse()
{
    string id;
    while (true) {
        cout << "enter id of course: ";
        getline(cin, id);

        // check if course is exist
        int i = 0;
        for (i = 0; i < _listOfCourses.size(); i++)
        {
            if (strcmp(_listOfCourses[i].getId(), id.c_str()) == 0)
            {
                Roster list = _listOfCourses[i].getRoster();
                cout << "\nList of students of course " << _listOfCourses[i].getName() << ":\n";
                list.print();
                return;
            }
        }
        if (i == _listOfCourses.size())
        {
            cout << "\n...Course not found... please enter again ...\n";
        }
    }
}

// 6. In thời khóa biểu của sinh viên(ds khóa học sinh viên đã đăng ký)
void Registrar::printSchedule()
{
}

// -----------------------------------------------