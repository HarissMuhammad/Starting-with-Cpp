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
		tmpNumPlate = numPlate;
	}

	string getNumPlate()
	{
		return to_string(numPlate);
	}

	void setColor(string tmpColor)
	{
		tmpColor = color;
	}

	string getColor()
	{
		return color;
	}

	void setCompany(string tmpCompany)
	{
		tmpCompany = company;
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
		result += "\n\tThe Car Reaches Zero to Hundered KMPH in: " + zeroToHundered;
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
		return "\n\n\tThe shape is: " + shape;
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
	cout << "\n Using Function in Vehicle Class : \n \t setAttributes() showAttributes() ";
	obj1.setAttributes(9959, "silver", "Company");
	obj1.showAttributes();

	cout << "___________________________________" << endl;
	cout << "OverLoading the Functions \tsetAttributes() \tshowAttributes()  " << endl;

	Car obj2(23, "red", "Honda", "HatchBack", 2);
	obj2.setAttributes("Sedan", 4);
	// obj2.showAttributes();

	cout << "\n___________________________________" << endl;
	cout << "\nOverLoading The Function of setAttributes() and showAttributes() in SportsCar Class" << endl;

	SportsCar obj3(23, "Black", "Nissan", "HatchBack", 4, 760, 3);
	obj3.setAttributes(760, 3);
	// obj3.showAttributes();

	ofstream newObjFile("Objects_attributes.txt");
	newObjFile << obj2.showAttributes();
	newObjFile << obj3.showAttributes();
	newObjFile.close();

	string n;
	ifstream ObjReadFile("Objects_attributes.txt");

	while (getline(ObjReadFile, n))
	{
		cout << n;
	}

	ObjReadFile.close();

	return 0;
}