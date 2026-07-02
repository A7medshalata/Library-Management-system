#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"

using namespace std;

class Library {
private:
    Book* collection;
    int maxSize;
    int totalBooks;
    int loanPeriod = 14;
    

public:
    Library(int cap);
    ~Library();

    void addBook(Book b);
    void removeBook(string title);
    void searchByTitle(string title);
    void searchByAuthor(string author);
    void searchByCategory(string categ);
    void displayBorrowed();
    void displayAvailableBooks();
    void displayAll();
    void displayOverdueBooks();
    int getMaxBorrowDays();
    void setMaxBorrowDays(int days);
    Book* getAllBooks();
    int getTotalBooks();
    void displayBorrowedBookReport();
    void saveToFile(string filename);
    void loadFromFile(string filename);
};

#endif