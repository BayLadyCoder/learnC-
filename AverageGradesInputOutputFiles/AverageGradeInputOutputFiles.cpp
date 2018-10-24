/*
Name: Rachada Chairangsaris (Bay)
Description: I/O Files, average grade functions
IDE used: Visual Studio Code
Date: Tuesday, October 23rd, 2018
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double AvgCalc(int &q1, int &q2, int &q3, int &t1, int &t2, int &t3);

char Display(double &average);

int main()
{
    int q1, q2, q3, t1, t2, t3;
    double average;
    char letterGrade;

    ifstream inFile;

    inFile.open("inputGrade.txt");

    if (inFile.fail())
    {
        cerr << "Cannot open file";
        exit(1);
    }

    ofstream outFile;
    outFile.open("outputGrade.txt");

    if (outFile.fail())
    {
        cerr << "Cannot open file";
        exit(1);
    }

    for (int i = 0; i < 7; i++)
    {
        inFile >> q1 >> q2 >> q3 >> t1 >> t2 >> t3;

        average = AvgCalc(q1, q2, q3, t1, t2, t3);
        letterGrade = Display(average);

        cout << q1 << " " << q2 << " " << q3 << " " << t1 << " " << t2 << " " << t3 << " " << average << " " << letterGrade << "\n";

        outFile << q1 << " " << q2 << " " << q3 << " " << t1 << " " << t2 << " " << t3 << " " << average << " " << letterGrade << "\n";
    }

    inFile.close();

    outFile.close();

    return 0;
}

double AvgCalc(int &q1, int &q2, int &q3, int &t1, int &t2, int &t3)
{
    double average, qAvg, tAvg, q40, t60;

    qAvg = (q1 + q2 + q3) / 3;
    tAvg = (t1 + t2 + t3) / 3;
    q40 = qAvg * 0.4;
    t60 = tAvg * 0.6;
    average = q40 + t60;

    return average;
}

char Display(double &average)
{
    char letterGrade;
    if (average < 60)
    {
        letterGrade = 'F';
    }
    else if (average >= 60 && average < 70)
    {
        letterGrade = 'D';
    }
    else if (average >= 70 && average < 80)
    {
        letterGrade = 'C';
    }
    else if (average >= 80 && average < 90)
    {
        letterGrade = 'B';
    }
    else
    {
        letterGrade = 'A';
    }
    return letterGrade;
}