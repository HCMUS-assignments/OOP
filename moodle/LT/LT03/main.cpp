#include "QLEBook.h"

int main() {
    QLEBook qlebook;
    ifstream fin("input.txt");
    fin >> qlebook;
    fin.close();
    ofstream fout("output.txt");
    fout << qlebook;
    fout.close();
    qlebook.sortPrice();
    qlebook.stat();
    qlebook.sortDate();

    return 225;
}