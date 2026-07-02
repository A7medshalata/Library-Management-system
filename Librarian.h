#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Customer.h"
#include "Library.h"
#include "Book.h"

using namespace std;

class Librarian : public User {
private:
    Customer* memberList;
    int maxMembers;
    int totalMembers;

public:
    Librarian(int id, string user, string pass);
    ~Librarian();

    void addBook(Library& lib, const Book& b);
    void removeBook(Library& lib, string title);
    void addCustomer(const Customer& c);
    void removeCustomer(int id);
    void viewAllCustomers();
    void viewCustomerData(int id);
    Customer* loginCustomer(int id , string user, string pass);
    void searchByTitle(Library& lib, string title);
    void searchByAuthor(Library& lib, string author);
    void searchByCategory(Library& lib, string categ);
    void displayAvailable(Library& lib);
    void displayBorrowed(Library& lib);
    void displayAll(Library& lib);
    void viewOverdueBooks(Library& lib);
    int getTotalMembers();
    void setMaxBorrowDays(Library& lib, int days);
    void saveCustomersToFile(string filename);
    void loadCustomersFromFile(string filename);
};

#endif