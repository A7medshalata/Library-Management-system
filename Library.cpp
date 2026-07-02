#include <iostream>
#include <iomanip> 
#include <ctime>
#include <fstream>
#include "Library.h"

using namespace std;



string toLower(string s) {
    string result = s;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] + 32;
        }
    }
    return result;
}



Library::Library(int cap) {
    maxSize = cap;
    totalBooks = 0;
    loanPeriod = 14; 
    collection = new Book[maxSize];
}

Library::~Library() {
    delete[] collection;
}

void Library::addBook(Book b) {
    if (totalBooks < maxSize) {
        collection[totalBooks] = b;
        totalBooks++;
    } else {
        cout << "Library is full!" << endl;
    }
}

void Library::removeBook(string title) {
    int index = -1;
    for (int i = 0; i < totalBooks; i++) {
        if (collection[i].getTitle() == title) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < totalBooks - 1; i++) {
            collection[i] = collection[i + 1];
        }
        totalBooks--;
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Book not found." << endl;
    }
}

void Library::searchByTitle(string title) {
    if (totalBooks == 0) {
        cout << "The library has no books yet." << endl;
        return;
    }
    bool found = false;
    string searchTitle = toLower(title);
    cout << "\n--- Search Results (Title: " << title << ") ---\n";
    for (int i = 0; i < totalBooks; i++) {
        string currentTitle = toLower(collection[i].getTitle());
        if (currentTitle.find(searchTitle) != string::npos) {
            collection[i].displayInfo(); 
            found = true;
        }
    }
    if (!found) cout << ">> No books found with title '" << title << "'." << endl;
}

void Library::searchByAuthor(string author) {
    if (totalBooks == 0) {
        cout << "The library has no books yet." << endl;
        return;
    }
    bool found = false;
    string searchAuthor = toLower(author);
    cout << "\n--- Search Results (Author: " << author << ") ---\n";
    for (int i = 0; i < totalBooks; i++) {
        string currentAuthor = toLower(collection[i].getAuthor());
        if (currentAuthor.find(searchAuthor) != string::npos) {
            collection[i].displayInfo();
            found = true;
        }
    }
    if (!found) cout << ">> No books found for author '" << author << "'." << endl;
}

void Library::searchByCategory(string category) {
    if (totalBooks == 0) {
        cout << "The library has no books yet." << endl;
        return;
    }
    bool found = false;
    string searchCat = toLower(category);
    cout << "\n--- Search Results (Category: " << category << ") ---\n";
    for (int i = 0; i < totalBooks; i++) {
        string currentCat = toLower(collection[i].getCategory());
        if (currentCat.find(searchCat) != string::npos) {
            collection[i].displayInfo();
            found = true;
        }
    }
    if (!found) cout << ">> No books found in category '" << category << "'." << endl;
}

void Library::displayAll() {
    if (totalBooks == 0) {
        cout << "The library is empty!" << endl;
        return;
    }
    for (int i = 0; i < totalBooks; i++) {
        
        cout << i+1 << ". Title: " << collection[i].getTitle() 
             << " | Author: " << collection[i].getAuthor() << endl;
    }
}

void Library::displayBorrowed() {
    if (totalBooks == 0) {
        cout << "The library has no books yet." << endl;
        return;
    }
    bool found = false;
    cout << "\n--- Borrowed Books ---" << endl;
    for (int i = 0; i < totalBooks; i++) {
        if (collection[i].isBorrowed()) {
             collection[i].displayInfo();
             found = true;
        }
    }
    if (!found) cout << ">> No books are currently borrowed." << endl;
}

void Library::displayAvailableBooks() {
    bool found = false;
    cout << "\n--- Available Books ---\n";
    for (int i = 0; i < totalBooks; i++) {
        if (!collection[i].isBorrowed()) {
            collection[i].displayInfo(); 
            found = true;
        }
    }
    if (!found) cout << ">> No available books at the moment.\n";
}

int Library::getMaxBorrowDays() {
    return loanPeriod;
}

void Library::setMaxBorrowDays(int days) {
    loanPeriod = days;
    cout << ">> Maximum borrow days updated successfully to " << days << " days.\n";
}

Book* Library::getAllBooks() {
    return collection;
}

void Library::displayOverdueBooks() {
    if (totalBooks == 0) {
        cout << "The library has no books yet." << endl;
        return;
    }
    time_t now = time(0);
    bool found = false;
    cout << "\n--- Overdue Books ---" << endl;
    for (int i = 0; i < totalBooks; i++) {
        if (collection[i].isBorrowed()) {
            double seconds = difftime(now, collection[i].getBorrowDate());
            int daysBorrowed = seconds / (24 * 60 * 60);
            if (daysBorrowed > loanPeriod) {
                cout << "Overdue: " << collection[i].getTitle()
                     << " | Author: " << collection[i].getAuthor()
                     << " | Days overdue: " << (daysBorrowed - loanPeriod) << endl;
                found = true;
            }
        }
    }
    if (!found) cout << ">> No overdue books at the moment." << endl;
}

 int Library::getTotalBooks(){
    return totalBooks;
 }

 

void Library::displayBorrowedBookReport() {
    bool found = false;
    time_t now = time(0); 

    cout << "\n============================================================" << endl;
    cout << "                BORROWED BOOKS REPORT                       " << endl;
    cout << "============================================================" << endl;
    
    cout << left << setw(20) << "Book Title" 
         << setw(20) << "Days Remaining" 
         << "Status" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < totalBooks; i++) {
        
        if (collection[i].isBorrowed()) {
            found = true;
            
            
            double seconds = difftime(collection[i].getBorrowDate() + (14 * 24 * 60 * 60), now);
            int daysLeft = seconds / (24 * 60 * 60);

            cout << left << setw(20) << collection[i].getTitle();
            
            if (daysLeft < 0) {
                cout << setw(20) << "OVERDUE" << "[!] Please Return Immediately";
            } else {
                cout << setw(20) << to_string(daysLeft) + " Days" << "On Time";
            }
            cout << endl;
        }
    }

    if (!found) {
        cout << "No books are currently borrowed from the library." << endl;
    }
    cout << "============================================================" << endl;
}


void Library::saveToFile(string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file for saving." << endl;
        return;
    }
    file << totalBooks << "\n";
    for (int i = 0; i < totalBooks; i++) {
        file << collection[i].getTitle()    << "\n";
        file << collection[i].getAuthor()   << "\n";
        file << collection[i].getCategory() << "\n";
        file << collection[i].isBorrowed()  << "\n";
        file << collection[i].getBorrowDate() << "\n";
    }
    file.close();
    cout << ">> Library saved to '" << filename << "' successfully.\n";
}

void Library::loadFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file '" << filename << "'." << endl;
        return;
    }
    int count;
    file >> count;
    file.ignore();
    totalBooks = 0;
    for (int i = 0; i < count && i < maxSize; i++) {
        string title, author, category;
        bool borrowed;
        time_t borrowDate;
        getline(file, title);
        getline(file, author);
        getline(file, category);
        file >> borrowed >> borrowDate;
        file.ignore();
        Book b(title, author, category);
        b.setBorrowed(borrowed);
        b.setBorrowDate(borrowDate);
        collection[totalBooks++] = b;
    }
    file.close();
    cout << ">> Library loaded from '" << filename << "' successfully. (" << totalBooks << " books)\n";
}
