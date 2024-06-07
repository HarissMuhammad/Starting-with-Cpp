#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream thiswrite("file.txt");
    thiswrite << "Hello this is file that is being called to read";

    thiswrite.close();

    ifstream thisRead("file.txt");

    string text;
    while (getline(thisRead, text))
    {
        cout << text;
    }

    thisRead.close();
}