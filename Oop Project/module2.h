#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "module1.cpp"

using namespace std;
class ShoppingCart
{
    // Ptype = Product Type
    double total;
    // PObj = Product Object
    
    vector<const Product*> pobj;

public:
    ShoppingCart() : total(0.0) {}

    
    string getTotal()const;
	void addProductToCart(ProductListing& list);
    void DisplayItemsFromCart() const;
    void clearCart();
    void processPayment();
    class Exceptions{
	};

};