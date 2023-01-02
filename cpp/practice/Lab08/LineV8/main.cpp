#include "Line.hpp"

int main() {
    // test parse string into object
    string s ;
    cout << "Enter an Line object in string : ";
    getline(cin, s);

    Line *line = Line::Parse(s);
    cout << line;

    return 0;
}