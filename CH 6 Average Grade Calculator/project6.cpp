//Author: Rachada Chairangsaris (Bay)
//Source file: project6.cpp
//Description: Average Scores I/O
//IDE used: Visual Studio Code
//Date: Monday, October 29th, 2018
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

double CalcAverage(int &q1, int &q2, int &q3, int &q4, int &q5, int &q6, int &q7, int &q8, int &q9, int &q10);

int main()
{
    double average;
    ifstream inFile;

    inFile.open("inputGrades.txt");

    if (inFile.fail())
    {
        cerr << "Cannot open file";
        exit(1);
    }

    int q1, q2, q3, q4, q5, q6, q7, q8, q9, q10;
    string firstName, lastName;

    ofstream outFile;
    outFile.open("outputGrades.txt");

    if (outFile.fail())
    {
        cerr << "Cannot open file";
        exit(1);
    }

    for (int i = 0; i < 6; i++)
    {

        inFile >> firstName >> lastName >> q1 >> q2 >> q3 >> q4 >> q5 >> q6 >> q7 >> q8 >> q9 >> q10;

        average = CalcAverage(q1, q2, q3, q4, q5, q6, q7, q8, q9, q10);

        cout << firstName << " " << lastName << " " << q1 << " " << q2 << " " << q3 << " " << q4 << " " << q5 << " " << q6 << " " << q7 << " " << q8 << " " << q9 << " " << q10 << " " << average << "\n";

        outFile << firstName << " " << lastName << " " << q1 << " " << q2 << " " << q3 << " " << q4 << " " << q5 << " " << q6 << " " << q7 << " " << q8 << " " << q9 << " " << q10 << " " << average << "\n";
    }

    inFile.close();

    outFile.close();

    return 0;
}

double CalcAverage(int &q1, int &q2, int &q3, int &q4, int &q5, int &q6, int &q7, int &q8, int &q9, int &q10)
{
    int total = q1 + q2 + q3 + q4 + q5 + q6 + q7 + q8 + q9 + q10;
    double average = total / 10.00;
    return average;
}
