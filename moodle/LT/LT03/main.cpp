#include "QLEBook.h"

int main() {


    QLEBook qlebook;
    ifstream fin("input.txt");
    cout << "\nreading file input.txt\n";
    fin >> qlebook;
    fin.close();
    ofstream fout("output.txt");
    cout << "\nwriting file output.txt\n";
    fout << qlebook;
    fout.close();
    cout << "\nwriting file output1.txt\n";
    qlebook.sortPrice();
    cout << "\nwriting file output2.txt\n";
    qlebook.stat();
    cout << "\nwriting file output3.txt\n";
    qlebook.sortDate();

    return 225;
}