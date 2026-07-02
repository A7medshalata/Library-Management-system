#include "Book.h"


Book::Book() {
    bookTitle = "Unkown";
    bookAuthor = "Unkown";
    bookCategory = "Unkown";
    borrowed = false;
    dueDate = 0;
}

Book::Book(string t, string a, string c) {
    bookTitle = t;
    bookAuthor = a;
    bookCategory = c;
    borrowed = false; 
    dueDate = 0;
}

string Book::getTitle() {
    return bookTitle;
}

string Book::getAuthor() {
    return bookAuthor;
}

string Book::getCategory() {
    return bookCategory;
}


bool Book::isBorrowed() {
    return borrowed;
}

void Book::setBorrowed(bool status) {
    borrowed = status;
}

time_t Book::getBorrowDate() {
    return dueDate;
}

void Book::setBorrowDate(time_t d) {
    dueDate = d;
}

void Book::displayInfo() {
    cout << "------------------------------------" << endl;
    cout << "Title    : " << bookTitle << endl;
    cout << "Author   : " << bookAuthor << endl;
    cout << "Category : " << bookCategory << endl;
    cout << "Status   : " ;
    if(borrowed){
        cout << "[BORROWED]" << endl;
    } else {
        cout << "[Available]" << endl;
    }
    
    
    if (borrowed) {
        cout << "Borrowed on: " << ctime(&dueDate);
    }
    cout << "------------------------------------" << endl;
}