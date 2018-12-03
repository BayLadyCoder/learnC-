//Author: Rachada Chairangsaris (Bay)
//Source file: project10.cpp
//Description: CDAccount Class
//IDE used: Visual Studio Code
//Date: Saturday December 2nd, 2018

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

class CDAccount
{

  public:
    CDAccount(double setBalance, double setRate, int setTerm);
    CDAccount();
    double get_balance();
    double get_balanceAtMaturity();
    double get_interestRate();
    int get_term();
    void output();
    double balanceAtMaturity;

  private:
    double balance;
    double interestRate;
    int term; // months until maturity
};

int main()
{

    CDAccount account1(200.00, 100.00, 6), account2;
    account1.output();
    account2.output();
    return 0;
}

CDAccount::CDAccount(double setBalance, double setRate, int setTerm) // constructor
{
    balance = setBalance;
    interestRate = setRate;
    term = setTerm;

    balanceAtMaturity = balance + (balance * ((interestRate / 100) * (term / 12.00)));
    balanceAtMaturity = balance + (balance * ((interestRate / 100) * (term / 12.00)));
    cout << balanceAtMaturity;
}

CDAccount::CDAccount() : balance(0.0), interestRate(0.0), term(0)
{
}

double CDAccount::get_balance()
{
    return balance;
}

double CDAccount::get_balanceAtMaturity()
{

    return balanceAtMaturity;
}

double CDAccount::get_interestRate()
{
    return interestRate;
}

int CDAccount::get_term()
{
    return term;
}

void CDAccount::output()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Account balance: $" << balance << endl;
    cout << "Interest rate: " << interestRate << "%" << endl;
    cout << "Term: " << term << endl;
    cout << "Balance after maturity: "
         << balanceAtMaturity << endl;
    cout << "---------------------------------------------" << endl;
}
