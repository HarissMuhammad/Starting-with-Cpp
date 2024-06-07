#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Product {
private:
    string name;
    int ID;
    float price;
    string description;
    int quantity;

public:
    Product(string n, int id, float p, string d, int q) : name(n), ID(id), price(p), description(d), quantity(q) {}

    void setName(string n) { name = n; }
    string getName() { return name; }

    void setID(int id) { ID = id; }
    int getID() { return ID; }

    void setPrice(float p) { price = p; }
    float getPrice() { return price; }

    void setDescription(string d) { description = d; }
    string getDescription() { return description; }
    
    void setQuantity(int q){ quantity = q;}
    int getQuantity() {return quantity;}

    void display() {
        cout << "name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "price: $" << price << endl;
        cout << "description: " << description << endl;
        cout << "quantity:" << quantity << endl;
    }
};

class ProductManager {
	public:
		virtual void addProduct(Product product)=0;
		virtual void removeProductByID(int ID)=0;
		virtual void searchProductByID(int ID)=0;
		virtual void displayAllproducts()=0;
		virtual void searchProductquantity(string name)=0;
		
		virtual ~ProductManager()
		{
			cout<<"The Virtual destructor Destroy The Class."<<endl;
		}

};

class ProductListing: public ProductManager {
private:
    vector <Product> productList;

public:
    void addProduct(Product product) override {
        productList.push_back(product);
    }
    
    void searchProductquantity(string name) override {
    	for (int i = 0; i < productList.size(); ++i){
    		if(productList[i].getName() == name){
    			productList[i].getQuantity();
    			cout<<"Quantity of the product is:"<<productList[i].getQuantity()<< endl;
    			return;
			}
		}
		cout<<"Product Not Found!"<<endl;
	}

    void removeProductByID(int ID) override {
        for (int i = 0; i < productList.size(); ++i) {
            if (productList[i].getID() == ID) {
                productList.erase(productList.begin() +i);
                cout << "Product removed successfully!" << endl;
            	return;
            }
        }
        cout << "Product not found!" << endl;
    }
    
    void searchProductByID(int ID) override {
	
    	for(int i=0; i < productList.size(); ++i){
    		if (productList[i].getID() == ID) {
    		productList[i].display();	
    			cout<<"Product Has been Found"<< endl;
    			return;
			} 
		}
		cout<<"Product Not Found!"<<endl;
	}
	
    void displayAllproducts() override {
        for (Product &product : productList) {
            product.display();
            cout << endl;
        }
    }
    
    void readFromFile(const string &filename) {
        fstream inputfile(filename, ios::in);
        if (inputfile.is_open()) {
            string name, description;
            int ID, quantity;
            float price;
            while (inputfile >> name >> ID >> price >> description >> quantity) {
				Product newProduct(name, ID, price, description, quantity);
				addProduct(newProduct);
            }
            inputfile.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }

    void writeToFile(const string &filename) {
        fstream outputfile(filename, ios::out);
        if (outputfile.is_open()) {
            for (Product &product : productList) {
                outputfile << product.getName() << " " << product.getID() << " " << product.getPrice() << " " << 
				product.getDescription() << " "<< product.getQuantity() << endl;
            }
            outputfile.close();
            cout << "Products saved to file." << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }
};

int main() {
    ProductListing productList;
    productList.readFromFile("updated_product.txt");

    int choice;
    do {
        cout << "\n==== Menu ====\n"
            "1. Display all products\n"
            "2. Add a product\n"
            "3. Remove a product\n"
            "4. Search a product\n"
            "5. How many quantities\n"
            "6. Save products to file\n"
            "7. Exit\n"
            "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            productList.displayAllproducts();
            break;
        case 2: {
            string name, description;
            int ID, quantity;
            float price;
            cout << "Enter Product name: ";
            cin >> name;
            cout << "Enter Product ID: ";
            cin >> ID;
            cout << "Enter Product price: ";
            cin >> price;
            cout<< "Enter Product quantity: ";
            cin>> quantity;
            cout << "Enter Product description: ";
            cin.ignore();
            getline(cin, description);
            Product newProduct(name, ID, price, description, quantity);
            productList.addProduct(newProduct);
            break;
        }
        case 3: {
            int ID;
            cout << "Enter Product ID to remove: ";
            cin >> ID;
            productList.removeProductByID(ID);
            break;
        }
        case 4:{
        	int ID;
        	cout<< "============Search product from ID==========="<<endl;
        	cout<<"Enter Product ID:";
        	cin>>ID;
        	productList.searchProductByID(ID);
			break;
		}
		
		case 5:{
            string name;
			cout<< " ============Search Product quantity============"<<endl;
			cout<<"Enter Product Name:";
			cin>> name;
			productList.searchProductquantity (name);
			break;
		}
        case 6:
            productList.writeToFile("updated_product.txt");
            break;
        case 7:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice. Enter a valid option." << endl;
        }
    } while (choice != 7);

    return 0;
}
