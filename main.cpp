#include <iostream>
#include <string>
#include "Library.h"
#include "Book.h"
#include "User.h"
#include "Customer.h"
#include "Librarian.h"
#include "Library.cpp"
#include "Book.cpp"
#include "User.cpp"
#include "Customer.cpp"
#include "Librarian.cpp"

using namespace std;

//  Forward declarations 
void librarianMenu(Librarian& librarian, Library& library);
void customerMenu(Customer& customer, Library& library);

//  Safe input function 
int getChoice() {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Invalid input! Please enter a number: ";
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            return choice;
        }
    }
}

//  MAIN 
int main() {

    Library library(100);

    //  Load from file on startup (if file exists) 
    library.loadFromFile("library_data.txt");

    //  If file was empty/new, seed with default books
    if (library.getTotalBooks() == 0) {
        library.addBook(Book("The Great Gatsby",    "F. Scott Fitzgerald", "Fiction"));
        library.addBook(Book("Pride and Prejudice", "Jane Austen",         "Romance"));
        library.addBook(Book("Harry Potter",        "J.K. Rowling",        "Children"));
        library.addBook(Book("Sapiens",             "Yuval Noah Harari",   "Non-fiction"));
        library.addBook(Book("It",                  "Stephen King",        "Horror"));
        library.addBook(Book("1984",                "George Orwell",       "Fiction"));
    }

    //  Default librarian 
    Librarian librarian(1, "admin", "admin123");

    // Load customers from file on startup 
    librarian.loadCustomersFromFile("customers_data.txt");

    int choice;
    do {
        cout << "\n====================================\n";
        cout << "   LIBRARY MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << " 1. Login as Librarian\n";
        cout << " 2. Login as Customer\n";
        cout << " 0. Exit\n";
        cout << "------------------------------------\n";
        cout << " Choice: ";
        cin >> choice;

        //  LIBRARIAN LOGIN 
        if (choice == 1) {
            string uname, pwd;
            cout << " Username: "; getline(cin, uname);
            cout << " Password: "; getline(cin, pwd);

            if (librarian.Login(librarian.getId(), uname, pwd)) {
                cout << "\n Welcome, " << uname << "!\n";
                librarianMenu(librarian, library);
            } else {
                cout << " Invalid credentials.\n";
            }
        }

        // CUSTOMER LOGIN 
        else if (choice == 2) {
    int id;
    string uname, pwd;
    cout << "Id :" ; cin >> id; cin.ignore();
    cout << " Username: "; getline(cin, uname);
    cout << " Password: "; getline(cin, pwd);

    Customer* member = librarian.loginCustomer(id,uname, pwd);
    if (member != nullptr) {
        cout << "\n Welcome, " << uname << "!\n";
        customerMenu(*member, library);
    } else {
        cout << " Invalid credentials or account not found.\n";
    }
}

    } while (choice != 0);

    //  Auto save on exit 
    library.saveToFile("library_data.txt");
    librarian.saveCustomersToFile("customers_data.txt");
    cout << "\n Goodbye!\n";
    return 0;
}

//  LIBRARIAN MENU 
void librarianMenu(Librarian& librarian, Library& library) {
    int choice;
    do {
        cout << "\n=== LIBRARIAN MENU ==================\n";
        cout << " 1.  Add Book\n";
        cout << " 2.  Remove Book\n";
        cout << " 3.  Add Customer\n";
        cout << " 4.  Remove Customer\n";
        cout << " 5.  View All Customers\n";
        cout << " 6.  View Customer Data\n";
        cout << " 7.  View All Books\n";
        cout << " 8.  Search by Title\n";
        cout << " 9.  Search by Author\n";
        cout << " 10. Search by Category\n";
        cout << " 11. Display Borrowed Books\n";
        cout << " 12. Display Available Books\n";
        cout << " 13. View Overdue Books\n";
        cout << " 14. Set Max Borrow Days\n";
        cout << " 15. Save Library to File\n";
        cout << " 16. Load Library from File\n";
        cout << " 0.  Logout\n";
        cout << "-------------------------------------\n";
        cout << " Choice: ";
        choice = getChoice();

        try {
            if (choice == 1) {
                string title, author, category;
                cout << " Title   : "; getline(cin, title);
                cout << " Author  : "; getline(cin, author);
                cout << " Category (Fiction/Romance/Children/Non-fiction/Horror/History): ";
                getline(cin, category);
                librarian.addBook(library, Book(title, author, category));

            } else if (choice == 2) {
                string title;
                cout << " Book title to remove: "; getline(cin, title);
                librarian.removeBook(library, title);

            } else if (choice == 3) {
                string uname, pwd;
                int id;
                cout << " Customer ID      : "; cin >> id; cin.ignore();
                cout << " Customer Username: "; getline(cin, uname);
                cout << " Customer Password: "; getline(cin, pwd);
                Customer newCustomer(id,uname,pwd);
                librarian.addCustomer(newCustomer);

            } else if (choice == 4) {
                int id;
                cout << " Customer ID to remove: "; cin >> id; cin.ignore();
                librarian.removeCustomer(id);

            } else if (choice == 5) {
                librarian.viewAllCustomers();

            } else if (choice == 6) {
                int id;
                cout << " Customer ID: "; cin >> id; cin.ignore();
                librarian.viewCustomerData(id);

            } else if (choice == 7) {
                librarian.displayAll(library);

            } else if (choice == 8) {
                string title;
                cout << " Search title: "; getline(cin, title);
                librarian.searchByTitle(library, title);

            } else if (choice == 9) {
                string author;
                cout << " Search author: "; getline(cin, author);
                librarian.searchByAuthor(library, author);

            } else if (choice == 10) {
                string cat;
                cout << " Search category: "; getline(cin, cat);
                librarian.searchByCategory(library, cat);

            } else if (choice == 11) {
                librarian.displayBorrowed(library);

            } else if (choice == 12) {
                librarian.displayAvailable(library);

            } else if (choice == 13) {
                librarian.viewOverdueBooks(library);

            } else if (choice == 14) {
                int days;
                cout << " Max borrow days: "; cin >> days; cin.ignore();
                librarian.setMaxBorrowDays(library,days);

            } else if (choice == 15) {
                string fname;
                cout << " Filename to save (e.g. library.txt): "; getline(cin, fname);
                library.saveToFile(fname);

            } else if (choice == 16) {
                string fname;
                cout << " Filename to load (e.g. library.txt): "; getline(cin, fname);
                library.loadFromFile(fname);

            } else if (choice != 0) {
                cout << " Invalid choice.\n";
            }
        } catch (exception& e) {
            cout << " Error: " << e.what() << "\n";
        }

    } while (choice != 0);
    cout << " Logged out.\n";
}

//  CUSTOMER MENU 
void customerMenu(Customer& customer, Library& library) {
    int choice;
    do {
        cout << "\n=== CUSTOMER MENU ===================\n";
        cout << " 1. Search by Title\n";
        cout << " 2. Search by Author\n";
        cout << " 3. Search by Category\n";
        cout << " 4. Borrow a Book\n";
        cout << " 5. Return a Book\n";
        cout << " 6. View My Borrowed Books\n";
        cout << " 7. Display Available Books\n";
        cout << " 8. View Overdue Books\n";
        cout << " 0. Logout\n";
        cout << "-------------------------------------\n";
        cout << " Choice: ";
        choice = getChoice();

        try {
            if (choice == 1) {
                string title;
                cout << " Search title: "; getline(cin, title);
                customer.searchByTitle(library, title);

            } else if (choice == 2) {
                string author;
                cout << " Search author: "; getline(cin, author);
                customer.searchByAuthor(library, author);

            } else if (choice == 3) {
                string cat;
                cout << " Search category: "; getline(cin, cat);
                customer.searchByCategory(library, cat);

            } else if (choice == 4) {
                string title;
                cout << " Book title to borrow: "; getline(cin, title);
                customer.borrowBook(library, title);

            } else if (choice == 5) {
                string title;
                cout << " Book title to return: "; getline(cin, title);
                customer.returnBook(library, title);

            } else if (choice == 6) {
                customer.viewMyBooks();

            } else if (choice == 7) {
                customer.displayAvailable(library);

            } else if (choice == 8) {
                customer.viewOverdueBooks(library);

            } else if (choice != 0) {
                cout << " Invalid choice.\n";
            }
        } catch (exception& e) {
            cout << " Error: " << e.what() << "\n";
        }

    } while (choice != 0);
    cout << " Logged out.\n";
}
