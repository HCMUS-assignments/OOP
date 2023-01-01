#include "Student.hpp"

int main() {
    Student student1;
    Student student2("Bui", "Thi Thanh", "Ngan");
    Student student3("Bui", "Thanh", "Quy");
    Student student4("Bui", "Thanh", "Tien");

    cout << "Student 1: " << student1 << endl;
    cout << "Student 2: " << student2 << endl;
    cout << "Student 3: " << student3 << endl;
    cout << "Student 4: " << student4 << endl;

    cout << "fullname of student 2: " << student2;

    // getters
    cout << "First name of student 3: " << student3.getFirstName() << endl;
    cout << "Middle name of student 3: " << student3.getMiddleName() << endl;
    cout << "Last name of student 3: " << student3.getLastName() << endl;

    cin >> student1;
    cout << "Student 1: " << student1 << endl;

    return 0;
}