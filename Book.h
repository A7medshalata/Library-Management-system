#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Book {
private:
    string bookTitle;
    string bookAuthor;
    string bookCategory;
    bool   borrowed;
    time_t dueDate;

public:
    
    Book();

    // Parameterized Constructor
    Book(string t, string a, string c);

    // Getters
    string getTitle();
    string getAuthor();
    string getCategory();
    bool isBorrowed(); 
    time_t getBorrowDate(); 

    // Setters
    void setBorrowed(bool status);
    void setBorrowDate(time_t d);

    void displayInfo();
};

#endif