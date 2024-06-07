#include "module2.cpp"

int main() 
{
try
{
		
    ProductListing productList;
    ShoppingCart item;
    productList.readFromFile("updated_product.txt");
    

	
    int choice;
    do {
        cout << "\n==== Menu ====\n"
            "1. Display all products\n"
            "2. Add a product\n"
            "3. Remove a product\n"
            "4. Save products to file\n"
            "5. Enter Product to cart\n"
            "6. Display Items from Cart\n"
            "7. Clear Items from Cart\n"
            "8. Get total Price\n"
            "9. Process Payment\n"
            "10. Exit\n"
            "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            productList.displayAllProducts();
            break;
        case 2: {
            string name, description;
            int ID;
            float price;
            cout << "Enter Product name: ";
            cin >> name;
            cout << "Enter Product ID: ";
            cin >> ID;
            cout << "Enter Product price: ";
            cin >> price;
            cout << "Enter Product description: ";
            cin.ignore();
            getline(cin, description);
            Product newProduct(name, ID, price, description);
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
        case 4:
            productList.writeToFile("updated_product.txt");
            break;
            
        case 5:
        	item.addProductToCart(productList);
			break;
		
		case 6:
			item.DisplayItemsFromCart();
			break;
			
		case 7:
			item.clearCart();
			break;
		
		case 8:	
			cout<<item.getTotal();
			break;
		
		case 9:
			item.processPayment();
			break;
		
        case 10:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice. Enter a valid option." << endl;
        }
    } while (choice != 10);

}
	catch(ProductListing::Exceptions)
	{
		cout<<"Invalid Input!\n";
	}
	
	catch(ShoppingCart::Exceptions)
	{
		cout<<"Invalid Input!";
	}
	
	  return 0;
}