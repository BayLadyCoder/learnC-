//Author: Rachada Chairangsaris (Bay)
//Source file: project4.cpp
//Description: Time Difference Calculator
//IDE used: Visual Studio Code
//Date: Monday, October 1st, 2018

#include <iostream>
#include <string>
#include <ctype.h>
#include <locale>
using namespace std;

int startHours, startMinutes, futureHours, futureMinutes;
bool startIsAm, futureIsAm;
char aChar, bChar, futureAChar, futureBChar;


// Compute Difference Function
int computeDifference(int startHours, int startMinutes, bool startIsAm, int futureHours, int futureMinutes, bool futureIsAm)
{
   
    int futureTotalMinutes1 = (futureHours * 60) + futureMinutes;
    int futureTotalMinutes2 = ((futureHours + 12) * 60) + futureMinutes;
    int startTotalMinutes1 = (startHours * 60) + startMinutes;
    int startTotalMinutes2 = 0 + startMinutes;
    int totalDifference, timeExcluded;
    int totalMinutesPerDay = 24 * 60;


    // Condition when start time and future time are AM/AM or PM/PM
    if ((futureIsAm == true && startIsAm == true) || (futureIsAm == false && startIsAm == false))
    {
        if (futureHours == 12 && startHours != 12) 
        {
          totalDifference = futureTotalMinutes2 - startTotalMinutes1;
        }
        else if (futureHours != 12 && startHours == 12) 
        {
            totalDifference = futureTotalMinutes1 - startTotalMinutes2;
        }
        else if (futureHours < startHours || ((futureHours == startHours) && (futureMinutes <= startMinutes)))  
        {
            timeExcluded = startTotalMinutes1 - futureTotalMinutes1;
           totalDifference = totalMinutesPerDay - timeExcluded; 
        }
        else
        {
           totalDifference = futureTotalMinutes1 - startTotalMinutes1;
        }
    }

    // Condition when start time and future time are AM/PM or PM/AM
    else
    {
            if (futureHours == 12 && startHours == 12) 
            {
                totalDifference = futureTotalMinutes1 - startTotalMinutes2;
            }
            else if (futureHours == 12 && startHours != 12)
            {
                totalDifference = futureTotalMinutes1 - startTotalMinutes1;
            }
            else if (startHours == 12 && futureHours != 12) 
            {
                totalDifference = futureTotalMinutes2 - startTotalMinutes2;
            }
            else
            {
                totalDifference = futureTotalMinutes2 - startTotalMinutes1;
            }
    }
        
    return totalDifference;
}

int main()
{
    string answer = "";
    int totalMinutes;

    // This Do/While Loop is for the whole program to repeat 
    // when user answer "y" or "Y" or "yes" or "Yes" or "YES" at the end of the program
    do
    {
        // This Loop will repeat when user input wrong format in the first charactor
        //(anything that does not start with "a" or "A" or "p" or "P")
        do
        {
            cout << "Enter start time (hours minutes AM/PM. Example. 11 05 AM): ";
            cin >> startHours >> startMinutes >> aChar >> bChar;

        } while (aChar != 'a' && aChar != 'A' && aChar != 'p' && aChar != 'P');

        // This condition check if the second charactor is "m" or "M", 
        // if not then it will go to the end of the program 
        if (bChar == 'm' || bChar == 'M')
        {
            // determine if the start time is AM or PM
            if (aChar == 'a' || aChar == 'A')
            {
                startIsAm = true;
            }
            else
            {
                startIsAm = false;
            }

            // This Loop will repeat when user input wrong format in the first charactor
            //(anything that does not start with "a" or "A" or "p" or "P")
            do
            {
                cout << "Enter future time (hours minutes AM/PM. Example. 11 05 AM): ";
                cin >> futureHours >> futureMinutes >> futureAChar >> futureBChar;
            } while (futureAChar != 'a' && futureAChar != 'A' && futureAChar != 'p' && futureAChar != 'P');

            // This condition check if the second charactor is "m" or "M", if not then it will go to the end of the program 
                if (futureBChar == 'm' || futureBChar == 'M')
                {
                    // determine if the future time is AM or PM
                    if (futureAChar == 'a' || futureAChar == 'A')
                    {
                        futureIsAm = true;
                    }
                    else
                    {
                        futureIsAm = false;
                    }

                    // Store the return output from the function to a variable to use in the future
                    totalMinutes = computeDifference(startHours, startMinutes, startIsAm, futureHours, futureMinutes, futureIsAm);

                    //print the result
                    cout << "Total minutes: " << totalMinutes << endl;
                }
                else
                {
                    cout << "You've enter wrong format" << endl;
                }
        }
        else
        {
             cout << "You've enter wrong format" << endl;
        }

        
        cout << "Do you want to calculate again? (y/n): ";
        cin >> answer;
    } while (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES");

    cout << "" << endl;
    cout << "" << endl;
    cout << "***********************************************************" << endl;
    cout << "           Thank you for using my service." << endl;
    cout << "        Developer: Rachada Chairangsaris (Bay)" << endl;
    cout << "***********************************************************" << endl;
    cout << "" << endl;
    return 0;
}
