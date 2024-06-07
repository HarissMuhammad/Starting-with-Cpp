#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int numPlate;
    string color;
    string company;

public:
    Vehicle(const int &tmpNum, const string &tmpColor, const string &tmpCompany)
        : numPlate(tmpNum), color(tmpColor), company(tmpCompany) {}

    Vehicle() : numPlate(0), color("null"), company("null") {}

    void setNumPlate(int tmpNumPlate)
    {
        numPlate = tmpNumPlate;
    }

    string getNumPlate()
    {
        return to_string(numPlate);
    }

    void setColor(string tmpColor)
    {
        color = tmpColor;
    }

    string getColor()
    {
        return color;
    }

    void setCompany(string tmpCompany)
    {
        company = tmpCompany;
    }

    string getCompany()
    {
        return company;
    }

    void display()
    {
        getNumPlate();
        getColor();
        getCompany();
    }

    void setAttributes(int x, string y, string z)
    {
        numPlate = x;
        color = y;
        company = z;
    }

    string showAttributes()
    {
        string result = "\n\n\tThe Number Plate is: " + to_string(numPlate);
        result += "\n\tThe Color is: " + color;
        result += "\n\tThe Company Name is: " + company;
        return result;
    }
};

class Car : public Vehicle
{
private:
    string shape;
    int noOfDoors;

public:
    Car(const int &tmpNum, const string &tmpColor, const string &tmpCompany, const string &tmpShape, const int &tmpNoOfDoors)
        : Vehicle(tmpNum, tmpColor, tmpCompany), shape(tmpShape), noOfDoors(tmpNoOfDoors) {}

    Car() : Vehicle(), shape("null"), noOfDoors(0) {}

    void setShape(string tmpShape)
    {
        tmpShape = shape;
    }

    string getShape()
    {
        return shape;
    }

    void setNoOfDoor(int tmpNoOfDoor)
    {
        tmpNoOfDoor = noOfDoors;
    }

    int getNoOfDoors()
    {
        return noOfDoors;
    }
    void display()
    {
        Vehicle::display();
        cout << "Shape: " << getShape();
        cout << "\nno Of Doors: " << getNoOfDoors();
    }

    void setAttributes(string x, int y)
    {
        shape = x;
        noOfDoors = y;
    }

    string showAttributes()
    {
        string result = "\n\tThe Shape of Car is: " + shape;
        result += "\n\tThe Number of Doors are: " + to_string(noOfDoors);
        return result;
    }
};

class SportsCar : public Car
{
private:
    int horsePower;
    int zeroToHundered;

public:
    SportsCar(const int &tmpNum, const string &tmpColor, const string &tmpCompany, const string &tmpShape, const int &tmpNoOfDoors, int tmpHp, const int &tmpZeroToHundered)
        : Car(tmpNum, tmpColor, tmpCompany, tmpShape, tmpNoOfDoors), horsePower(tmpHp), zeroToHundered(tmpZeroToHundered) {}

    SportsCar() : Car(), horsePower(0), zeroToHundered(0) {}

    void setHp(int tmpHp)
    {
        tmpHp = horsePower;
    }

    int getHp()
    {
        return horsePower;
    }

    void setZeroToHundered(int tmpZeroToHundered)
    {
        tmpZeroToHundered = zeroToHundered;
    }

    int getZeroToHundered()
    {
        return zeroToHundered;
    }

    void display()
    {
        Car::display();
        cout << "Hp: " << getHp();
        cout << "Zero to Hundered in : " << getZeroToHundered();
    }

    void setAttributes(int x, int y)
    {
        horsePower = x;
        zeroToHundered = y;
    }

    string showAttributes()
    {
        string result = "\n\n\tThe Horsepower is: " + to_string(horsePower);
        result += "\n\tThe Car Reaches Zero to Hundered KMPH in: " + to_string(zeroToHundered);
        return result;
    }
};

class Bike : public Vehicle
{
private:
    string shape;

public:
    Bike(const int &tmpNum, const string &tmpColor, const string &tmpCompany, const string &tmpShape)
        : Vehicle(tmpNum, tmpColor, tmpCompany), shape(tmpShape) {}

    Bike() : Vehicle(), shape(0) {}

    void display()
    {
        Vehicle::display();
        cout << "Shape: " << shape << endl;
    }

    void setAttributes(string x)
    {
        shape = x;
    }

    string showAttributes()
    {
        string result = "\n\n\tThe shape is: " + shape;
        return result;
    }
};

class SportsBike : public Bike
{
private:
    string type;
    int zeroToHundered;

public:
    SportsBike(const int &tmpNum, const string &tmpColor, const string &tmpCompany, const string &tmpShape, string tmpType, int tmpZeroToHundered)
        : Bike(tmpNum, tmpColor, tmpCompany, tmpShape), type(tmpType), zeroToHundered(tmpZeroToHundered) {}

    SportsBike() : Bike(), type("null"), zeroToHundered(0) {}

    void setAttributes(string x, int y)
    {
        type = x;
        zeroToHundered = y;
    }

    string showAttributes()
    {
        string result = "\n\n\tThe Type is: " + type;
        result += "\n\tThe Bike Reaches Zero to Hundered KMPH in: " + to_string(zeroToHundered);
        return result;
    }
};

int main()
{
    Vehicle obj1(2098, "Black", "HKLSd");
    string z;
    bool x;
    ofstream write_file;
    ifstream read_file;
    cout << "Enter 1 if you want to continue :  ";
    if (x == 1)
    {
        x = true;
    }
    cin >> x;
    string d;
    string e;

    do
    {
        cout << "\t----------------------------\n\tEnter Any Of the options\n\t1- Create Object.\t\n\t2-Print Object.\n\t3-Write object to file\n\t4-Exit\n";
        int y;
        cout << "\n\tEnter your Choice: ";
        cin >> y;
        switch (y)
        {
        case 1:
            int c;
            cout << "\n\t----------------------\n";
            cout << "Enter the Number plate\n";
            cin >> c;
            obj1.setNumPlate(c);
            cout << "Enter the Color\n";
            cin >> d;
            obj1.setColor(d);
            cout << "Enter the Company\n";
            cin >> e;
            obj1.setCompany(e);
            cout << "\nThe Object is added Succesfully\n";

            break;
        case 2:
            cout << "\nt\tThese are the object values you added\n";
            cout << "\n\tThe number plate of car is : ";
            cout << obj1.getNumPlate();
            cout << endl;
            cout << "\n\tThe company of car is : ";
            cout << obj1.getCompany();
            cout << endl;
            cout << "\n\tThe Color of Car is : ";
            cout << obj1.getColor();
            cout << endl;
            break;
        case 3:
            write_file.open("Object_File.txt");
            write_file << obj1.showAttributes();
            cout << endl;
            write_file.close();
            cout << "\n\tThe Object is added to file\n \t Please refer to Object_File.txt\n";
            break;
        case 4:
            x = false;
            break;
        default:
            cout << "\n\tInvalid Option enter a correct one ";
            break;
        }
    } while (x == true);
    return 0;
}