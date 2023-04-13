#include "Registrar.h"

// define
Registrar::Registrar()
{
}

// ------------------------------------------------

// 1. Đọc danh sách khóa học từ file
void Registrar::readCoursesFromFile(const char *fileName)
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
        // cout << "\n...here...";
        vector<char *> info;
        // cout << "\nline: " << line << endl;

        char *str = new char[line.length() + 1];
        strcpy(str, line.c_str());

        // start split string and set info to course
        // id
        char *token = strtok(str, ",");
        // cout << "\nToken: " << token ;
        info.push_back(Utils::standardized(token));
        // cout << "\npushed ... ";
        // name
        token = strtok(NULL, ",");
        info.push_back(Utils::standardized(token));
        // classes
        token = strtok(NULL, "}");

        // add } to end of string
        string temp = token;
        temp.append("}");
        // cout <<"\nToken: " << temp;
        info.push_back(Utils::standardized((char *)temp.c_str()));

        // list students
        // ignore ,
        // cout << "\nsplit dssv";
        token = strtok(NULL, ", ");
        // cout << "\nToken: " << token ;
        info.push_back(Utils::standardized(token));

        // add info to course
        // cout << "\nstart to add course ...";
        Course course(info[0], info[1], info[2], info[3]);
        _listOfCourses.push_back(course);
        // cout << "\nafter";
    }
    fin.close();
    cout << "\n...finished ...\n";
}

// 2. Sinh viên đăng ký khóa học
void Registrar::registerCourse()
{
    // 1. enter id of student
    string id;

    int indexStudent = 0;
    int indexCourse = 0;

    while (true)
    {
        cout << "\nEnter your ID: ";
        fflush(stdin);
        getline(cin, id);

        // find and return student info if have
        int i = 0;
        for (i = 0; i < _listOfStudents.size(); i++)
        {
            if (strcmp(_listOfStudents[i].getId(), id.c_str()) == 0)
            {
                indexStudent = i;
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

    cout << "\nNumber course you joined: " << _listOfStudents[indexStudent].getNumCourseJoined() << endl;
    if (_listOfStudents[indexStudent].getNumCourseCanRegister() == 0)
    {
        cout << "you can't register any course more ...\n";
        cout << "Do you want to see courses opening ? (y/n) : ";
        string line;
        getline(cin, line);
        if (line == "y")
        {
            cout << "\nList of courses bellow: \n\n";
            for (int i = 0; i < _listOfCourses.size(); i++)
            {
                cout << _listOfCourses[i].getId() << " - " << _listOfCourses[i].getName() << " - ";
                cout << _listOfCourses[i].getScheduleStr() << " - " << _listOfCourses[i].getRoster().getSizeStr() << endl;
            }
        }
        else
        {
            return;
        }
    }

    // 2. print list course that student can register: not yet register (ID - Name - Schedule - Size)
    cout << "\nList of courses bellow: \n\n";
    for (int i = 0; i < _listOfCourses.size(); i++)
    {
        cout << _listOfCourses[i].getId() << " - " << _listOfCourses[i].getName() << " - ";
        cout << _listOfCourses[i].getScheduleStr() << " - ";
        cout << _listOfCourses[i].getRoster().getSizeStr() << endl;
    }

    // 3. enter id of course that student want to register
    string idCourse;
    Course course;

    Schedule studentTimetable = _listOfStudents[indexStudent].getTimeTable();

    while (true)
    {
        cout << "\nEnter ID of course that you want to register: ";
        getline(cin, idCourse);

        // check if course is exist
        int i = 0;
        bool found = false;
        for (i = 0; i < _listOfCourses.size(); i++)
        {
            if (strcmp(_listOfCourses[i].getId(), idCourse.c_str()) == 0)
            {
                indexCourse = i;
                course = _listOfCourses[i];
                // 4.1 check if that course is full or not
                if (course.getSizeCourse() == course.getMaxSizeOfCourse())
                {
                    cout << "\nThis course is fulled. Let choose another course ...\n";
                    break;
                }
                else
                {
                    found = true;
                    break;
                }
            }
        }

        if (!found || i == _listOfCourses.size())
        {
            if (i == _listOfCourses.size())
            {
                cout << "\nNot exist course " << idCourse << " ... please enter again ...\n";
            }
        }
        else
        {
            // 4. check if student can register course that dont have same schedule with other course
            // go through schedule of course and check classes in timetable of student if have any course same time,

            bool hasSameSchedule = false;

            for (int i = 0; i < _listOfCourses[indexCourse].getSchedule().size(); i++)
            {
                Day day = studentTimetable.getAt(_listOfCourses[indexCourse].getSchedule()[i].getNameDay());
                bool exist[2] = {false, false};
                cout << "\nName day: " << day.getNameDay() << endl;
                cout << "\nSub morning: " << day.getSubMorning() << endl;
                cout << "\nSub afternoon: " << day.getSubAfternoon() << endl;
                if (strcmp(_listOfCourses[indexCourse].getSchedule()[i].getSubMorning(), "x") == 0)
                {
                    exist[0] = true;
                }
                if (strcmp(_listOfCourses[indexCourse].getSchedule()[i].getSubAfternoon(), "x") == 0)
                {
                    exist[1] = true;
                }
                cout << "\nexist: " << exist[0] << ", " << exist[1] <<  endl;
                if (exist[0] && strcmp(day.getSubMorning(), "x") != 0)
                {
                    cout << "\n!!! This course have same time with another course - " << day.getSubMorning() << endl;
                    cout << "\nLet choose another course ... !\n";
                    hasSameSchedule = true;
                    break;
                }
                if (exist[1] && strcmp(day.getSubAfternoon(), "x") != 0)
                {
                    cout << "\n!!! This course have same time with another course - " << day.getSubAfternoon() << endl;
                    cout << "\nLet choose another course ... !\n";
                    hasSameSchedule = true;
                    break;
                }
            }
            if (!hasSameSchedule)
            {
                break;
            }
        }
    }

    // --------------- handle register course------------------------

    // 4.2 add course into timetable of student

    // cout << "\nadd time table...\n";
    // cout << "Num classes: " << _listOfCourses[indexCourse].getSchedule().size() << endl;
    for (int i = 0; i < _listOfCourses[indexCourse].getSchedule().size(); i++)
    {
        char *subject = new char[strlen(_listOfCourses[indexCourse].getId()) + 1];
        strcpy(subject, _listOfCourses[indexCourse].getId());

        char *time;
        if (strcmp(_listOfCourses[indexCourse].getSchedule()[i].getSubMorning(), "x") == 0)
        {
            time = new char[strlen("morning") + 1];
            strcpy(time, "morning");
        }
        else
        {
            time = new char[strlen("afternoon") + 1];
            strcpy(time, "afternoon");
        }
        // cout << "\nstart to set time table...\n";
        // cout << "\nSubject: " << subject << endl;
        _listOfStudents[indexStudent].setTimeTable(_listOfCourses[indexCourse].getSchedule()[i].getNameDay(), subject, time);
    }
        // add student to course
        _listOfCourses[indexCourse].addStudent(_listOfStudents[indexStudent].getId(), _listOfStudents[indexStudent].getFullname());
        // for (int i = 0; i < _listOfCourses.size(); i++)
        // {
        //     if (strcmp(_listOfCourses[i].getId(), idCourse.c_str()) == 0)
        //     {
        //         cout << "\n...add student to course...";
        //         _listOfCourses[i].addStudent(student.getId(), student.getFullname());
        //         break;
        //     }
        // }

        cout << "\n...register course successfully....\n";
    }

    // 3. Ghi danh sách sinh viên lên file
    void Registrar::writeStudentsIntoFile(const char *fileName)
    {
        ofstream fout(fileName);
        // format: id, name, birthday, address, {course joined}
        for (int i = 0; i < _listOfStudents.size(); i++)
        {
            fout << _listOfStudents[i].getId() << "," << _listOfStudents[i].getFullname() << ", " << _listOfStudents[i].getBirthday() << ", " << _listOfStudents[i].getAddress() << ", ";
            fout << _listOfStudents[i].getScheduleStr() << endl;
        }
        fout.close();
        cout << "\n...finished...\n";
    }

    // 4. Đọc danh sách sinh viên từ file, xuất ra màn hình
    void Registrar::readStudents(const char *fileName)
    {
        _listOfStudents.clear();
        string line;
        ifstream fin(fileName);
        if (fin.fail())
        {
            cout << "\n...Error opening " << fileName << " ... \n";
            return;
        }
        int i = 1;
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
            // cout << "\nbefore add info...\n";
            Student student(Utils::standardized((char *)id.c_str()), Utils::standardized((char *)name.c_str()), Utils::standardized((char *)birthday.c_str()), Utils::standardized((char *)address.c_str()));
            // cout << "\nbefore set time table...\n";
            student.setTimeTable(Utils::standardized((char *)schedule.c_str()));

            // cout << "\nbefore push ...\n";
            _listOfStudents.push_back(student);
        }
        fin.close();

        cout << "\nfinished...\n";
    }

    // 5. In danh sách sinh viên của một khóa học
    void Registrar::printStudentsOfCourse()
    {
        string id;
        while (true)
        {
            cout << "enter id of course: ";
            fflush(stdin);
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
        cout << "\n...finished...\n";
    }

    // 6. In thời khóa biểu của sinh viên(ds khóa học sinh viên đã đăng ký)
    void Registrar::printSchedule()
    {
        string id;
        while (true)
        {
            cout << "Enter id of student: ";
            fflush(stdin);
            getline(cin, id);

            // check if student is exist
            int i = 0;
            for (i = 0; i < _listOfStudents.size(); i++)
            {
                if (strcmp(_listOfStudents[i].getId(), id.c_str()) == 0)
                {
                    cout << "\nSchedule of student " << _listOfStudents[i].getFullname() << ":\n";
                    _listOfStudents[i].printSchedule();
                    return;
                }
            }
            if (i == _listOfStudents.size())
            {
                cout << "\n...Student not found... please enter again ...\n";
            }
        }
        cout << "\n...finished...\n";
    }

    // 7. In danh sách khóa học
    void Registrar::printCourses()
    {
        for (int i = 0; i < _listOfCourses.size(); i++)
        {
            cout << _listOfCourses[i].getId() << " - " << _listOfCourses[i].getName() << " - ";
            cout << _listOfCourses[i].getScheduleStr() << " - ";
            cout << _listOfCourses[i].getRoster().getSizeStr() << endl;
        }
    }

    // 8. In danh sách sinh viên
    void Registrar::printListStudents()
    {
        for (int i = 0; i < _listOfStudents.size(); i++)
        {
            cout << i + 1 << ". " << _listOfStudents[i].getId() << ", " << _listOfStudents[i].getFullname() << ", ";
            cout << _listOfStudents[i].getBirthday() << ", " << _listOfStudents[i].getAddress() << endl;
        }
    }

    // 9. In thông tin 1 khóa học
    void Registrar::printInfoCourse()
    {
        cout << "Enter ID of course: ";
        string idCourse;
        fflush(stdin);
        getline(cin, idCourse);
        for (int i = 0; i < _listOfCourses.size(); i++)
        {
            if (strcmp(idCourse.c_str(), _listOfCourses[i].getId()) == 0)
            {
                cout << "ID: " << idCourse << endl;
                cout << "Name: " << _listOfCourses[i].getName() << endl;
                cout << "Schedule: " << _listOfCourses[i].getScheduleStr() << endl;
                break;
            }
        }
    }

    // -----------------------------------------------

    void Registrar::run()
    {
        int choice;
        do
        {
            choice = Utils::Menu();
            switch (choice)
            {
            case 1:
                readCoursesFromFile("listOfCourses.txt");
                break;
            case 2:
                readStudents("listOfStudents.txt");

                break;
            case 3:
                registerCourse();

                break;
            case 4:
                writeStudentsIntoFile("output3_dssv.txt");

                break;
            case 5:
                printStudentsOfCourse();
                break;
            case 6:
                printSchedule();
                break;
            case 7:
                printCourses();
                break;
            case 8:
                printListStudents();
                break;
            case 9:
                printInfoCourse();
                break;
            default:
                break;
            }

        } while (choice != 10);
        cout << "\n...Chương trình kết thúc...\n";
    }