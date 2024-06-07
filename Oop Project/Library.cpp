#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Book class to represent each book in the library
class Book {
public:
    string title;
    string author;
    string isbn;
    bool available;

    // Constructor
    Book(string t, string a, string i) : title(t), author(a), isbn(i), available(true) {}

    // Display book information
    void display() const {
        cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << isbn << "\nStatus: "
             << (available ? "Available" : "Not Available") << endl;
    }
};

// Library class to manage the collection of books
class Library {
private:
    vector<Book> books;  // Collection of books

public:
    // Load books from file during initialization
    Library() {
        loadBooks();
    }

    // Destructor to save books to file before exiting
    ~Library() {
        saveBooks();
    }

    // Add a new book to the library
    void addBook() {
        string title, author, isbn;
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter ISBN: ";
        getline(cin, isbn);

        Book newBook(title, author, isbn);
        books.push_back(newBook);
        cout << "Book added successfully.\n";
    }

    // Remove a book from the library
    void removeBook() {
        string title;
        cout << "Enter the title of the book to remove: ";
        getline(cin, title);

        auto it = find_if(books.begin(), books.end(), [&](const Book &b) {
            return b.title == title;
        });

        if (it != books.end()) {
            books.erase(it);
            cout << "Book removed successfully.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    // Display the list of all books in the library
    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library.\n";
        } else {
            for (const auto &book : books) {
                book.display();
                cout << "------------------------\n";
            }
        }
    }

    // Search for a book by title or author
    void searchBook() const {
        string query;
        cout << "Enter title or author to search: ";
        getline(cin, query);

        auto it = find_if(books.begin(), books.end(), [&](const Book &b) {
            return (b.title.find(query) != string::npos) || (b.author.find(query) != string::npos);
        });

        if (it != books.end()) {
            it->display();
        } else {
            cout << "Book not found.\n";
        }
    }

    // Borrow a book (mark it as unavailable)
    void borrowBook() {
        string title;
        cout << "Enter the title of the book to borrow: ";
        getline(cin, title);

        auto it = find_if(books.begin(), books.end(), [&](const Book &b) {
            return b.title == title && b.available;
        });

        if (it != books.end()) {
            it->available = false;
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book not available for borrowing.\n";
        }
    }

    // Return a book (mark it as available)
    void returnBook() {
        string title;
        cout << "Enter the title of the book to return: ";
        getline(cin, title);

        auto it = find_if(books.begin(), books.end(), [&](const Book &b) {
            return b.title == title && !b.available;
        });

        if (it != books.end()) {
            it->available = true;
            cout << "Book returned successfully.\n";
        } else {
            cout << "Invalid book return.\n";
        }
    }

private:
    // Load books from a file
    void loadBooks() {
        ifstream file("library_data.txt");
        if (file.is_open()) {
            string title, author, isbn, available_str;
            while (getline(file, title) && getline(file, author) && getline(file, isbn) &&
                   getline(file, available_str)) {
                bool available = (available_str == "1");
                books.emplace_back(title, author, isbn);
                books.back().available = available;
            }
            file.close();
        }
    }

    // Save books to a file
    void saveBooks() const {
        ofstream file("library_data.txt");
        if (file.is_open()) {
            for (const auto &book : books) {
                file << book.title << "\n" << book.author << "\n" << book.isbn << "\n"
                     << (book.available ? "1" : "0") << "\n";
            }
            file.close();
        }
    }
};

// Function to display menu and handle user input
void displayMenu(Library &library) {
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a new book\n";
        cout << "2. Remove a book\n";
        cout << "3. Display all books\n";
        cout << "4. Search for a book\n";
        cout << "5. Borrow a book\n";
        cout << "6. Return a book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character left in the buffer

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.removeBook();
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                library.searchBook();
                break;
            case 5:
                library.borrowBook();
                break;
            case 6:
                library.returnBook();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

int main() {
    Library library;
    displayMenu(library);

    return 0;
}
