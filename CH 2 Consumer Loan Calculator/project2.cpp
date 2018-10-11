//Author: Rachada Chairangsaris (Bay)
//Source file: project2.cpp
//Description: Consumer Loan Calculator
//IDE used: Visual Studio Code
// Date: Septemeber 7th, 2018

#include <iostream>
using namespace std;

int main()
{
    string answer;
    do
    {

        float interestYear, totalInterest, interestMonth, totalLoan, consumerReceive, monthlyPayment;
        int months;

        cout << "" << endl;
        cout << "Enter amount that you want to receive: ";
        cin >> consumerReceive;
        cout << "" << endl;
        do
        {
            cout << "************** Interest rate per year MUST BE between 0-1 (ex. enter 0.15 for 15\%) **************" << endl;
            cout << "Enter interest rate per year: ";

            cin >> interestYear;
            cout << "" << endl;
        } while (interestYear <= 0 || interestYear >= 1);

        cout << "How many months for the installation? : ";
        cin >> months;
        cout << "------------------------------------------------------" << endl;

        interestMonth = (interestYear / 12) * months;
        totalLoan = consumerReceive / (1 - interestMonth);

        totalInterest = totalLoan - consumerReceive;
        monthlyPayment = totalLoan / months;
        cout << "" << endl;
        cout << "Your total loan is: " << totalLoan << endl;
        cout << "Total interest is: " << totalInterest << endl;
        cout << "You will receive: " << consumerReceive << endl;
        cout << "Your monthly payment is: " << monthlyPayment << endl;
        cout << "" << endl;
        cout << "------------------------------------------------------" << endl;

        cout << "Do you want to calculate again? (y/n): ";
        cin >> answer;
    } while (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes");
    cout << "" << endl;
    cout << "" << endl;
    cout << "***********************************************************" << endl;
    cout << "           Thank you for using my service." << endl;
    cout << "        Developer: Rachada Chairangsaris (Bay)" << endl;
    cout << "***********************************************************" << endl;
    cout << "" << endl;

    return 0;
}
