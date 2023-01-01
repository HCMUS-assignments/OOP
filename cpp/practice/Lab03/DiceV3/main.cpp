#include "Dice.hpp"

int main() {
    Dice d[3] = {Dice(), Dice(), Dice()};
    int count = 0;
    Random r = Random();
    int n = r.Next();
    for (int i = 0; i < n; i++) {
        int roll = d[i % 3].Roll();
        cout << "Roll " << i << ": " << roll << endl;
    }

    count = d[0].RollCount() + d[1].RollCount() + d[2].RollCount();

    cout << "Dice 1 rolls: " << d[0].RollCount() << endl;
    cout << "Dice 2 rolls: " << d[1].RollCount() << endl;
    cout << "Dice 3 rolls: " << d[2].RollCount() << endl;
    
    cout << "Total rolls: " << count << endl;

    return 0;
}