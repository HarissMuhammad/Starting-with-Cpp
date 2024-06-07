#include "module1.h"

void Product::setName(string n) {name = n;}
string Product::getName()const {return name;}

void Product::setID(int id) { ID = id; }
int Product::getID()const { return ID; }

void Product::setPrice(float p) { price = p; }
float Product::getPrice()const { return price; }

void Product::setDescription(string d) { description = d; }
string Product::getDescription() { return description; }

void Product::display() const
	{
        cout << "name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "price: $" << price << endl;
        cout << "description: " << description << endl;
        cout<< "Quantity" << quantity << endl;
    }

void Product::setQuantity(int q){quantity = q;}
int Product::getQuantity() {return quantity;}

	
void ProductListing::addProduct(Product product)
	{
        productList.push_back(product);
    }
    
void ProductListing::removeProductByID(int ID)
	{
        for (int i = 0; i < productList.size(); ++i) {
            if (productList[i].getID() == ID) {
                productList.erase(productList.begin() +i);
                cout << "Product removed successfully!" << endl;
                return;
            }
            else
            	{
            	throw Exceptions();
				}
        }
        cout << "Product not found!" << endl;
    } 

void ProductListing::displayAllProducts()
	{
        for (Product &product : productList) {
            product.display();
            cout << endl;
        }
    }
	
void ProductListing::readFromFile(const string &filename)
	{
        ifstream inputfile(filename);
        if (inputfile.is_open()) {
            string name, description;
            int ID;
            float price;
            while (inputfile >> name >> ID >> price >> description) {
                Product newProduct(name, ID, price, description);
                addProduct(newProduct);
            }
            inputfile.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }	
	
void ProductListing::writeToFile(const string &filename) 
	{
        ofstream outputfile(filename);
        if (outputfile.is_open()) {
            for (Product &product : productList) {
                outputfile << product.getName() << " " << product.getID() << " " << product.getPrice() << " " << product.getDescription() << endl;
            }
            outputfile.close();
            cout << "Products saved to file." << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }
    
    const Product* ProductListing::getProductById(int id) const
    {
    	for(auto& product : productList)
    	{
    		if(product.getID()==id)
    		{	
    			cout<<"Product found \n";
    			return &product;
			}	
		}
		return nullptr;
	}
	
	   