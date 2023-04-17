#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <windows.h>
using namespace std;

class ATM
{
private:
    int n500k, n200k, n100k, n50k;
    int total;

public:
    ATM();
    ATM(int n500k, int n200k, int n100k, int n50k);
    void set(int n500k, int n200k, int n100k, int n50k);
    void check(int amount);
    void withdraw(int amount);
    void handleWithdraw(int amount);
};

#endif

// define

ATM::ATM()
{
    total = 10100000;
    n500k = 10;
    n200k = 20;
    n100k = 10;
    n50k = 2;
}

ATM::ATM(int n500k, int n200k, int n100k, int n50k)
{
    total = n500k * 500000 + n200k * 200000 + n100k * 100000 + n50k * 50000;
    this->n500k = n500k;
    this->n200k = n200k;
    this->n100k = n100k;
    this->n50k = n50k;
}

void ATM::set(int n500k, int n200k, int n100k, int n50k)
{
    total = n500k * 500000 + n200k * 200000 + n100k * 100000 + n50k * 50000;
    this->n500k = n500k;
    this->n200k = n200k;
    this->n100k = n100k;
    this->n50k = n50k;
}

void ATM::check(int amount)
{
    if (amount > total)
    {
        throw "ATM is not enough money to withdraw.";
    }
    if (!n500k || !n200k || !n100k || !n50k)
    {
        throw "ATM is not enough kind of denominations.";
    }
    if (amount % 50000)
    {
        throw "ATM can not withdraw this amount.";
    }
}

void ATM::withdraw(int amount)
{
    try
    {
        check(amount);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        return;
    }
    handleWithdraw(amount);
}

void ATM::handleWithdraw(int amount)
{
    int temp = amount;
    while (amount >= 500000 && this->n500k)
    {
        amount -= 500000;
        this->n500k--;
    }
    while (amount >= 200000 && this->n200k)
    {
        amount -= 200000;
        this->n200k--;
    }
    while (amount >= 100000 && this->n100k)
    {
        amount -= 100000;
        this->n100k--;
    }
    while (amount >= 50000 && this->n50k)
    {
        amount -= 50000;
        this->n50k--;
    }
    total -= temp;
    cout << "Withdraw " << temp << " successfully." << endl;
    cout << "Total: " << total << endl;
    cout << "500k : " << n500k << " 200k : " << n200k << " 100k : " << n100k << " 50k : " << n50k << endl;
}

int main()
{
    SetConsoleOutputCP(65001);
    ATM atm;
    int choice, amount;
    do
    {
        cout << "\n----------------------ATM----------------------" << endl;
        cout << "1. Rút theo mặc định" << endl;
        cout << "2. Rút theo số tiền" << endl;
        cout << "3. Thoát" << endl;
        cout << "-----------------------------------------------" << endl;
        fflush(stdin);
        cout << "\nChọn chức năng: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "\n\n-----Rút theo mặc định------" << endl;
                cout << "1. 500.000" << endl;
                cout << "2. 1.000.000" << endl;
                cout << "3. 2.000.000" << endl;
                cout << "4. 5.000.000" << endl;
                cout << "5. Trở về" << endl;
                cout << "--------------------------------" << endl;
                fflush(stdin);
                cout << "\nChọn chức năng: ";
                cin >> choice;
                switch (choice)
                {
                    case 1:
                        atm.withdraw(500000);
                        break;
                    case 2:
                        atm.withdraw(1000000);
                        break;
                    case 3:
                        atm.withdraw(2000000);
                        break;
                    case 4:
                        atm.withdraw(5000000);
                        break;
                    default:
                        break;
                }
                choice = 1;

                break;
            case 2:
                cout << "\n\n-----Rút theo số tiền cụ thể-----" << endl;
                fflush(stdin);
                cout << "Nhập số tiền: ";
                cin >> amount;
                atm.withdraw(amount);

                break;

            case 3:
                cout << "\nThoát chương trình." << endl;
                break;
            default:
                cout << "\nChức năng không tồn tại." << endl;
                break;
        }


    } while (choice != 3);
    return 225;
}