#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Product 
{
private:
    string name;
    int ID;
    float price;
    string description;
    int quantity;

public:
    Product(string n, int id, float p, string d) : name(n), ID(id), price(p), description(d) {}

    void setName(string n);
    string getName()const;

    void setID(int id);
    int getID()const;

    void setPrice(float p);
    float getPrice()const;

    void setDescription(string d);
    string getDescription();

    void display()const;
    
    void setQuantity(int q);
    int getQuantity();
    
    class Exceptions{};
};

class ProductListing {
private:
    vector<Product> productList;

public:
    void addProduct(Product product);
    void removeProductByID(int ID);
	void displayAllProducts();
	void readFromFile(const string &filename);
    void writeToFile(const string &filename);
    const Product* getProductById(int id)const;
    class Exceptions{};
    
};

