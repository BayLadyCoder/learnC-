//Author: Rachada Chairangsaris (Bay)
//Source file: project3.cpp
//Description: Calling Cost Calculator
//IDE used: Visual Studio Code
//Date: Saturday, September 15th, 2018

#include <iostream>
#include <string>
#include <ctype.h>
#include <locale>
using namespace std;

char dayName1, dayName2;
float rate040, rate025, rate015, costOfCall;
string timeCallStart;
int callTimeLength = 0;
string answer;
float timeCallStartFloat;

float timeCallStartFunction()
{
    cout << "What time does the call start? (24-hour format ex. 13:30 for 1:30pm): ";
    cin >> timeCallStart;

    for (int i = 0; i < timeCallStart.length(); i++)
    {
        if (timeCallStart[i] == ':')
            timeCallStart[i] = '.';
    }
    // testing to see the new String before converting to Float
    // cout << timeCallStart << endl;

    // Casting String to Float
    timeCallStartFloat = stof(timeCallStart);

    // testing to see the result after converting to Float
    // cout << timeCallStartFloat << endl;
    return timeCallStartFloat;
}

int main()
{
    rate040 = 0.40;
    rate025 = 0.25;
    rate015 = 0.15;

    do
    {
        cout << "Enter the day of the week (Ex. Mo = Monday, Tu = Tuesday, We = Wednesday etc.): ";
        cin >> dayName1 >> dayName2;
        // Check if the input day is Saturday or Sunday
        if ((dayName1 == 's' || dayName1 == 'S') && (dayName2 == 'a' || dayName2 == 'A' || dayName2 == 'u' || dayName2 == 'U'))
        {
            do
            {
                timeCallStartFunction();
            } while (timeCallStartFloat > 24.00 || timeCallStartFloat < 0.00);
            cout << "How long is the call in minutes? (ex. enter 5 for 5 minutes): ";
            cin >> callTimeLength;

            cout << "***********************************" << endl;
            costOfCall = callTimeLength * rate015;
            cout << "Total cost of this call is: $" << costOfCall << endl;
            cout << "***********************************" << endl;
        }
        // Check if the input day is within Monday-Friday
        else if (((dayName1 == 'm' || dayName1 == 'M') && (dayName2 == 'o' || dayName2 == 'O')) ||
                 ((dayName1 == 't' || dayName1 == 'T') && (dayName2 == 'u' || dayName2 == 'U')) ||
                 ((dayName1 == 'w' || dayName1 == 'W') && (dayName2 == 'e' || dayName2 == 'E')) ||
                 ((dayName1 == 't' || dayName1 == 'T') && (dayName2 == 'h' || dayName2 == 'H')) ||
                 ((dayName1 == 'f' || dayName1 == 'F') && (dayName2 == 'r' || dayName2 == 'R')))
        {
            do
            {
                timeCallStartFunction();
            } while (timeCallStartFloat > 24.00 || timeCallStartFloat < 0.00);

            cout << "How long is the call in minutes? (ex. enter 5 for 5 minutes): ";
            cin >> callTimeLength;

            if (timeCallStartFloat >= 8.00 && timeCallStartFloat <= 18.00)
            {
                cout << "***********************************" << endl;
                costOfCall = callTimeLength * rate040;
                cout << "Total cost of this call is: $" << costOfCall << endl;
                cout << "***********************************" << endl;
            }
            else
            {
                cout << "***********************************" << endl;
                costOfCall = callTimeLength * rate025;
                cout << "Total cost of this call is: $" << costOfCall << endl;
                cout << "***********************************" << endl;
            }
        }
        //  if input day doesn't match any day of the week
        else
        {
            cout << "Invalid Day Name" << endl;
        }

        cout << "Do you want to calculate again? (y/n): ";
        cin >> answer;
    } while (answer == "y" || answer == "Y" || answer == "Yes" || answer == "YES");

    cout << "" << endl;
    cout << "" << endl;
    cout << "***********************************************************" << endl;
    cout << "           Thank you for using my service." << endl;
    cout << "        Developer: Rachada Chairangsaris (Bay)" << endl;
    cout << "***********************************************************" << endl;
    cout << "" << endl;
    return 0;
}
