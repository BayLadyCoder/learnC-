#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int AB, BC, AC, num1, num2;
    string side1, side2;
    float area;
    AB = 0;
    BC = 0;
    AC = 0;

    cout << "Enter Sides and distances: ";
    cin >> side1 >> num1 >> side2 >> num2;

    if (side1 == "AB")
    {
        AB = num1;
        if (side2 == "BC")
        {
            BC = num2;
            AC = sqrt(pow(AB, 2) + pow(BC, 2));
            // cout << AC << endl;
            area = (AB * BC) / 2;
            cout << "AC: " << AC << ", Area: " << area << endl;
        }
        else
        {
            AC = num2;
            BC = sqrt(pow(AC, 2) - pow(AB, 2));
            // cout << BC << endl;
            area = (AB * BC) / 2;
            cout << "BC: " << BC << ", Area: " << area << endl;
        }
    }
    else if (side1 == "BC")
    {
        BC = num1;
        if (side2 == "AC")
        {
            AC = num2;
            AB = sqrt(pow(AC, 2) - pow(BC, 2));
            // cout << AB << endl;
            area = (AB * BC) / 2;
            cout << "AB: " << AB << ", Area: " << area << endl;
        }
        else
        {
            AB = num2;
            AC = sqrt(pow(AB, 2) + pow(BC, 2));
            // cout << AC << endl;
            area = (AB * BC) / 2;
            cout << "AC: " << AC << ", Area: " << area << endl;
        }
    }
    else
    {
        AC = num1;
        if (side2 == "BC")
        {
            BC = num2;
            AB = sqrt(pow(AC, 2) - pow(BC, 2));

            area = (AB * BC) / 2;
            cout << "AB: " << AB << ", Area: " << area << endl;
        }
        else
        {
            AB = num2;
            BC = sqrt(pow(AC, 2) - pow(AB, 2));

            area = (AB * BC) / 2;
            cout << "BC: " << BC << ", Area: " << area << endl;
        }
    }

    return 0;
}
