#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Person
{
    int age;
    string name;
    string gender;

public:
    Person(int ta, string nm, string gd) : age(ta), name(nm), gender(gd) {}

    void menu();
    void displayMenu(); // Change the return type to void
    void setAge(int ta);
    int getAge();
    void setName(string nm);
    string getName();
    void setGender(string g);
    string getGender();
    void savePersonsToFile();
    void loadPersonsFromFile();
};

void Person::setAge(int ta)
{
    age = ta;
}

int Person::getAge()
{
    return age;
}

void Person::setName(string nm)
{
    name = nm;
}

string Person::getName()
{
    return name;
}

void Person::setGender(string g)
{
    gender = g;
}

string Person::getGender()
{
    return gender;
}

vector<Person> obj;
void Person::menu()
{
    string name, gender;
    int age, it;

    do
    {
        cout << "Enter name of person";
        getline(cin, name);

        cout << "Enter gender\n";
        getline(cin, gender);
        cout << "Enter age\n";
        cin >> age;
        cin.ignore();

        Person obj1(age, name, gender);

        obj.push_back(obj1);

        cout << "Enter 1 or 0";
        cin >> it;
        cin.ignore();

    } while (it);
}

void Person::displayMenu()
{
    for (auto &obj1 : obj)
    {
        cout << "Age: " << obj1.getAge() << ", Name: " << obj1.getName() << ", Gender: " << obj1.getGender() << endl;
    }
}

void Person::savePersonsToFile()
{
    ofstream file("PersonFile.txt");
    if (!file.is_open())
    {
        cout << "File is not open\n";
    }

    for (auto &obj1 : obj)
    {
        file << obj1.getAge() << "," << obj1.getGender() << "," << obj1.getName() << "\n";
    }
    file.close();
}

void Person::loadPersonsFromFile()
{
    ifstream file("PersonFile.txt");
    if (!file.is_open())
    {
        cerr << "File could not be opened\n";
    }

    string line;
    while (getline(file, line))
    {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        if (pos1 != string::npos && pos2 != string::npos)
        {
            int age = stoi(line.substr(0, pos1));
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string gender = line.substr(pos2 + 1);

            Person obj3(age, name, gender);
            obj.push_back(obj3);
        }
    }
    file.close();
}

int main()
{
    Person newObj(0, "da", "s");

    newObj.menu();
    newObj.loadPersonsFromFile();
    newObj.displayMenu();
    return 0;
}
