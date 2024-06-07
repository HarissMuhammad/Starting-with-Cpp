#include "module2.h"


	void ShoppingCart::DisplayItemsFromCart() const 
	{
		cout<<"Products in Cart: \n";
		for(const Product* product : pobj)
		{
			cout<<product->getName()<<"\n";
		}
	}
	
	void ShoppingCart::addProductToCart(ProductListing& list)
	{
		
		int id;
		cout<<"Enter ID: \n";
		cin>>id;
		const Product* product = list.getProductById(id);
		
		if (product)
		{
			pobj.push_back(product);
			cout<<"Product added to cart successfully: \n";
			product->display();
		}
		else
		{
			throw Exceptions();
		}
	}
	
	
	void ShoppingCart::clearCart()
	{
		pobj.clear();
		cout<<"Cart Cleared\n";
	} 
   
	string ShoppingCart::getTotal()const
	{
		int calculateTotal = 0;
		for(const Product* product : pobj)
		{
			calculateTotal += product->getPrice();
		}

		return to_string(calculateTotal);
	}
	
	void ShoppingCart::processPayment()
	{
		int calculateTotal = 0;
		for(const Product* product : pobj)
		{
			calculateTotal += product->getPrice(); 
		} 
		
		cout<<"Total amount "<<calculateTotal<<endl;
		cout<<"Processed the payment Succesfully\n";
		clearCart();
	}
              
   