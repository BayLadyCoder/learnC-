//Author: Rachada Chairangsaris (Bay)
//Source file: project8.cpp
//Description: Extracting Info from a String
//IDE used: Visual Studio Code
//Date: Saturday December 1st, 2018

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    string str = "Jenny 28 Programmer";
    string space = " ";

    string name, age, title, str2, str3;
    int ageInt;
    int location;

    for (int i = 0; i < str.length(); i++)
    {
        string aChar = str.substr(i, 1);
        location = space.find(aChar, 0);
        if (location != 0)
            name += aChar;
        else
        {
            int length = i + 1;
            // cout << length;
            str2 = str.erase(0, length); // remove name and a space
            // cout << str2 << endl;

            stringstream ss;
            ss << str;
            ss >> ageInt;            // get age (integer)
            age = to_string(ageInt); // casting to string

            length = age.length() + 1;    // length of age and a space
            str3 = str2.erase(0, length); // remove age and a space

            title = str3;
            break;
        }
    }

    cout << "Name: " << name << ", Age: " << age << ", Title: " << title << endl;

    return 0;
}
