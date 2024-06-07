#include <iostream>
#include <vector>
#include <algorithm>

// Product class definition
class Product {
public:
    int productId;
    std::string name;
    std::string description;
    double price;
    int quantity;

    Product(int id, const std::string& n, const std::string& desc, double p, int q)
        : productId(id), name(n), description(desc), price(p), quantity(q) {}
};

// ProductListing class definition
class ProductListing {
private:
    std::vector<Product> products;

public:
    // Function to add a new product
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // Function to display available products
    void displayProducts() const {
        std::cout << "Available Products:\n";
        for (const auto& product : products) {
            std::cout << "ID: " << product.productId << ", Name: " << product.name
                      << ", Price: $" << product.price << ", Quantity: " << product.quantity << "\n";
        }
    }

    // Function to search for a product by name or category
    std::vector<Product> searchProducts(const std::string& searchTerm) const {
        std::vector<Product> result;
        for (const auto& product : products) {
            // For simplicity, consider a match if the search term is part of the product name or description
            if (product.name.find(searchTerm) != std::string::npos ||
                product.description.find(searchTerm) != std::string::npos) {
                result.push_back(product);
            }
        }
        return result;
    }
};

// ShoppingCart class definition
class ShoppingCart {
private:
    std::vector<Product> cart;
    double totalAmount;

public:
    ShoppingCart() : totalAmount(0.0) {}

    // Function to add a product to the shopping cart
    void addToCart(const Product& product, int quantity) const {
        // Check if the quantity is available
        if (quantity > 0 && quantity <= product.quantity) {
            cart.push_back(product);
            totalAmount += product.price * quantity;
            // Update the quantity in the inventory
            product.quantity -= quantity;
        } else {
            std::cout << "Invalid quantity or insufficient stock.\n";
        }
    }

    // Function to remove a product from the shopping cart
    void removeFromCart(const Product& product, int quantity) {
        auto it = std::find(cart.begin(), cart.end(), product);
        if (it != cart.end()) {
            // Remove the product from the cart
            cart.erase(it);
            // Update the quantity in the inventory
            product.quantity += quantity;
            totalAmount -= product.price * quantity;
        }
    }

    // Function to display the contents of the shopping cart
    void displayCart() const {
        std::cout << "Shopping Cart Contents:\n";
        for (const auto& product : cart) {
            std::cout << "ID: " << product.productId << ", Name: " << product.name
                      << ", Price: $" << product.price << ", Quantity: 1\n";
        }
        std::cout << "Total Amount: $" << totalAmount << "\n";
    }
};

int main() {
    // Sample usage
    ProductListing inventory;
    inventory.addProduct(Product(1, "Laptop", "High-performance laptop", 999.99, 10));
    inventory.addProduct(Product(2, "Smartphone", "Latest smartphone model", 499.99, 20));
    inventory.addProduct(Product(3, "Headphones", "Noise-canceling headphones", 149.99, 15));

    // Display available products
    inventory.displayProducts();

    // Search for products
    std::string searchTerm = "Laptop";
    std::vector<Product> searchResult = inventory.searchProducts(searchTerm);
    std::cout << "Search Results for '" << searchTerm << "':\n";
    for (const auto& product : searchResult) {
        std::cout << "ID: " << product.productId << ", Name: " << product.name
                  << ", Price: $" << product.price << ", Quantity: " << product.quantity << "\n";
    }

    // Shopping Cart
    ShoppingCart cart;

    // Add products to the cart
    cart.addToCart(searchResult[0], 1);
    cart.addToCart(searchResult[1], 2);

    // Display cart contents
    cart.displayCart();

    // Remove a product from the cart
    cart.removeFromCart(searchResult[0], 1);

    // Display updated cart contents
    cart.displayCart();

    return 0;
}
