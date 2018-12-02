//Author: Rachada Chairangsaris (Bay)
//Source file: project9.cpp
//Description: Average in Pointer Array of double
//IDE used: Visual Studio Code
//Date: Saturday December 1st, 2018

#include <iostream>
#include <cstring>
using namespace std;

void output(double *arr, int size);
void calcAverage(double *arr, int size);

int main()
{

    int numDoubles;
    cout << "Enter an integer number (not too big number, recommend between 1-3): ";
    cin >> numDoubles;
    numDoubles = numDoubles * 2;
    typedef double *DoublePtr;
    DoublePtr arrPtr;
    arrPtr = new double[numDoubles];
    double userInput;

    cout << "Array size is: " << numDoubles << endl;
    cout << "Enter " << numDoubles << " number type double with decimals. (Example, 19.098)" << endl;

    for (int i = 0; i < numDoubles; i++)
    {
        cout << "Enter a double number " << i + 1 << ": ";
        cin >> userInput;
        arrPtr[i] = userInput;
    }

    output(arrPtr, numDoubles);
    calcAverage(arrPtr, numDoubles);

    delete[] arrPtr;

    return 0;
}

void output(double *arr, int size)
{
    cout << "your array elements are ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void calcAverage(double *arr, int size)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    double sum, average;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    average = sum / size;
    cout << "The average of this array is " << average << endl;
}