#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Library.h"
#include "Book.h"
#include <string>

class Customer : public User {
private:
    Book myBooks[5];    
    int bookCount=0;      

public:
    // Constructor & Destructor
    Customer(){};
    Customer(int id, string user, string pass);
    ~Customer();

    // Search Functions
    void searchByTitle(Library& lib, string title);
    void searchByAuthor(Library& lib, string author);
    void searchByCategory(Library& lib, string categ);

    // Borrow & Return
    void borrowBook(Library& lib, string title);
    void returnBook(Library& lib, string title);

    // View Functions
    void viewMyBooks();
    void displayAvailable(Library& lib);
    void viewOverdueBooks(Library& lib);
};

#endif