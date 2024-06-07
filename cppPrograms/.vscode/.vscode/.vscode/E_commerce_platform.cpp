#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product
{
    int id;
    string name;
    double price;
    int quantity;

public:
    Product() : id(0), name("null"), price(0), quantity(0) {}

    void setId(int);
    int getId();
    void setName(string);
    string getName();
    void setPrice(double);
    double getPrice();
    void setQuantity(int);
    int getQuantity();

    string display();
};

void Product::setId(int tmpId)
{
    id = tmpId;
}

int Product::getId()
{
    return id;
}

void Product::setName(string tmpName)
{
    name = tmpName;
}

string Product::getName()
{
    return name;
}

void Product::setPrice(double tmpPrice)
{
    price = tmpPrice;
}

double Product::getPrice()
{
    return price;
}

void Product::setQuantity(int tmpQuantity)
{
    quantity = tmpQuantity;
}

int Product::getQuantity()
{
    return quantity;
}

string Product::display()
{
    string result = "Id: " + to_string(id);
    result += "\nName: " + name;
    result += "\nPrice: " + to_string(price);
    result += "\nQuantity: " + to_string(quantity);
    return result;
}

class Listing : Product
{
    // Ptype = Product Type
    string PType;
    // PObj = Product Object
    vector<Product &> PObj;

public:
    Listing() : PType("null") {}

    void setPtype(string tmpPtype);
    string getPType();

    void addProductObject(Product &tmpPObj);
    string getProductList();
};

void Listing::setPtype(string tmpPtype)
{
    PType = tmpPtype;
}

string Listing::getPType()
{
    return PType;
}

void Listing::addProductObject(Product &tmpPObj)
{
    PObj.push_back(tmpPObj);
}

string Listing::getProductList()
{
    string productList;
    for (Product &tmpPObj : PObj)
    {
        // productList = "Id:  " tmpPObj.getId() + " \n";
        // productList += "Name: "tmpPObj.getName() + "\n";
        // productList += ""to_string(tmpPObj.getPrice()) + "\n";
        // productList += tmpPObj.getQuantity() + "\n";
        productList = tmpPObj.display();
    }
    return productList;
}

int main()
{
    Product obj1;
    obj1.setId(1);
    obj1.setName("Rice");
    obj1.setPrice(300);
    obj1.setQuantity(1);

    Listing prod;
    prod.setPtype("General items");
    prod.addProductObject(obj1);

    cout << "Product: \n"
         << prod.getProductList()
         << "-----------------------" << endl;
}