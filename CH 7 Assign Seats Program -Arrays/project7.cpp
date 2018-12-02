//Author: Rachada Chairangsaris (Bay)
//Source file: project7.cpp
//Description: Assign passenger seats Program
//IDE used: Visual Studio Code
//Date: Saturday December 1st, 2018

#include <iostream>
#include <cstring>
using namespace std;

void createSeats(char arr[][4]);
void displaySeats(char arr[][4]);
bool bookASeat(char arr[][4], int row, char column);
bool isNotFullFunction(char arr[][4]);
void checkTheSeat(char arr[][4], int row, int col);

int main()
{
    bool isNotFull;
    string answer = "";
    char arr[7][4]; // create two dimensional array
    createSeats(arr);

    do
    {

        int row;
        char column;
        cout << "Please enter a row number(1-7) and a seat(A, B ,C, or D) that you want to reserve." << endl;
        do
        {
            cout << "Row number (1-7): ";
            cin >> row;
        } while (row < 1 || row > 7);

        cout << "Desire Seat (A, B, C, or D): ";
        cin >> column;

        isNotFull = bookASeat(arr, row, column);

        if (!(isNotFull))
        {
            cout << "All seats are booked." << endl;
            break;
        }

        cout << "Do you want to book more seats? (y/n)";
        cin >> answer;

    } while (answer == "yes" || answer == "y" || answer == "Y" || answer == "Yes");

    cout << "Thank you for using our service. Have a good day!" << endl;

    return 0;
}

void displaySeats(char arr[][4])
{
    for (int i = 0; i < 7; i++)
    {
        int row = i + 1;
        cout << row;
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j];
        }

        cout << endl;
    }
}

void createSeats(char arr[][4])
{
    // char arr[7][4]; // create two dimensional array

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            switch (j)
            {
            case 0:
                arr[i][j] = 'A';
                break;
            case 1:
                arr[i][j] = 'B';
                break;
            case 2:
                arr[i][j] = 'C';
                break;
            default:
                arr[i][j] = 'D';
            }
        }
    }
    displaySeats(arr);
}

bool isNotFullFunction(char arr[][4])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] != 'X')
                return true;
        }
    }
    return false;
}

void checkTheSeat(char arr[][4], int row, int col)
{
    // Check if this seat is booked
    if (arr[row][col] == 'X')
        cout << "This seat is already reserved." << endl;
    else // Book the seat if it's available
    {
        arr[row][col] = 'X';
        displaySeats(arr);
    }
}

bool bookASeat(char arr[][4], int row, char column)
{
    row = row - 1;
    switch (column)
    {
    case 'A':
    case 'a':
        checkTheSeat(arr, row, 0);
        break;
    case 'B':
    case 'b':
        checkTheSeat(arr, row, 1);
        break;
    case 'C':
    case 'c':
        checkTheSeat(arr, row, 2);
        break;
    case 'D':
    case 'd':
        checkTheSeat(arr, row, 3);
        break;
    default:
        cout << "You've entered an invalid seat" << endl;
    }

    return isNotFullFunction(arr);
}
