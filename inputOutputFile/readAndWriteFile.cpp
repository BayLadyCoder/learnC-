#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream in_stream;

    in_stream.open("numbers.txt");

    if (in_stream.fail())
    {
        cerr << "Cannot open file";
        exit(1);
    }

    int x, y, z;
    string a, b, c, d;

    in_stream >> x >> y >> z >> a >> b >> c >> d;

    cout << x << " " << y << " " << z << " " << a << " " << b << " " << c << " " << d << endl;

    in_stream.close();

    ofstream outFile;
    outFile.open("doc.txt");

    if (outFile.fail())
    {
        cerr << "Cannot open file";
        exit(1);
    }

    outFile << "Sample writing data to an empty document" << endl;

    outFile.close();

    return 0;
}
