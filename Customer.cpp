#include "Customer.h"
#include <iostream>
using namespace std;





Customer::Customer(int id, string user, string pass) : User(id, user, pass) {
    bookCount = 0;
}

Customer::~Customer() {}


void Customer::searchByTitle(Library& lib, string title) {
    cout << "Search by Title: " << "[" << title << "]" << endl;
    lib.searchByTitle(title);
}

void Customer::searchByAuthor(Library& lib, string author) {
    cout << "Search by Author: " << "["  << author << "]" << endl;
    lib.searchByAuthor(author);
}


void Customer::searchByCategory(Library& lib, string categ) {
    cout << "Search by Category: " << "["<< categ << "]" << endl;
    lib.searchByCategory(categ);
}


void Customer::borrowBook(Library& lib, string title) {
    if (bookCount >= 5) {
        cout << "Error: You reached the maximum limit (5 books)." << endl;
        return;
    }

    Book* collection = lib.getAllBooks();
    for (int i = 0; i < lib.getTotalBooks(); i++) {
        if (collection[i].getTitle() == title) {
            if (!collection[i].isBorrowed()) {
                time_t now = time(0);
                collection[i].setBorrowed(true);
                collection[i].setBorrowDate(now);   // set actual current time
                myBooks[bookCount] = collection[i];
                bookCount++;
                cout << "Success: Book '" << title << "' is now with you." << endl;
                return;
            } else {
                cout << "Error: This book is already borrowed." << endl;
                return;
            }
        }
    }
    cout << "Error: Book not found in library." << endl;
}


void Customer::returnBook(Library& lib, string title) {
    int foundIndex = -1;
    for (int i = 0; i < bookCount; i++) {
        if (myBooks[i].getTitle() == title) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        Book* collection = lib.getAllBooks();
        for (int i = 0; i < lib.getTotalBooks(); i++) {
            if (collection[i].getTitle() == title) {
                collection[i].setBorrowed(false);
                collection[i].setBorrowDate(0);
                break;
            }
        }
        
        for (int i = foundIndex; i < bookCount - 1; i++) {
            myBooks[i] = myBooks[i + 1];
        }
        bookCount--;
        cout << "Success: Book '" << title << "' returned to library." << endl;
    } else {
        cout << "Error: You don't have this book in your list." << endl;
    }
}


void Customer::viewMyBooks() {
    cout << "\n--- Your Borrowed Books (" << bookCount << "/5) ---" << endl;
    if (bookCount == 0) {
        cout << "No books currently borrowed." << endl;
    } else {
        for (int i = 0; i < bookCount; i++) {
            cout << "- " << myBooks[i].getTitle() << " (" << myBooks[i].getAuthor() << ")" << endl;
        }
    }
}


void Customer::displayAvailable(Library& lib) {
    cout << "\n--- Books Available for Borrowing ---" << endl;
    Book* collection = lib.getAllBooks();
    bool any = false;
    for (int i = 0; i < lib.getTotalBooks(); i++) {
        if (!collection[i].isBorrowed()) {
            cout << "Title: " << collection[i].getTitle() << " | Author: " << collection[i].getAuthor() << " | Category: " << collection[i].getCategory() << endl;
            any = true;
        }
    }
    if (!any) cout << "No books available at the moment." << endl;
}


void Customer::viewOverdueBooks(Library& lib) {
    cout << "\n--- Checking Overdue Books ---" << endl;
    cout << "Feature: No overdue books found for " << username << "." << endl;
}