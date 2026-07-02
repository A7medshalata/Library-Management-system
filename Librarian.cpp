#include<iostream>
#include"Librarian.h"
#include"Customer.h"
using namespace std;



Librarian::Librarian(int Id, string User, string Pass){
    id = Id;
    username=User;
    password=Pass;
    maxMembers=200;
    totalMembers=0;
    memberList=new Customer[maxMembers];

}

Librarian::~Librarian(){
    delete[] memberList;
}

void Librarian::addBook(Library& lib,const Book& b){
    lib.addBook(b);
}

void Librarian::removeBook(Library& lib, string title){
    lib.removeBook(title);
}

void Librarian::addCustomer(const Customer& c){
    if (totalMembers >= maxMembers) {
        cout << "Error: Cannot add more customers, list is full." << endl;
        return;
    }
    for (int i = 0; i < totalMembers; i++) {
        if (memberList[i].getId() == c.getId()) {
            cout << "Error: A customer with ID " << c.getId() << " already exists." << endl;
            return;
        }
    }
    memberList[totalMembers] = c;
    totalMembers++;
    cout << "Success: Customer '" << c.getUsername() << "' added successfully." << endl;
}

void Librarian::removeCustomer(int id){
    if (totalMembers == 0) {
        cout << "Error: No customers registered yet." << endl;
        return;
    }
    int index = -1;
    for(int i=0;i<totalMembers;i++){
        if(memberList[i].getId()==id){
            index=i;
            break;
        }
    }
    if(index != -1){
        cout << "Success: Customer '" << memberList[index].getUsername() << "' removed." << endl;
        for(int i = index ; i<totalMembers-1;i++){
            memberList[i]=memberList[i+1];
        }
        totalMembers--;
    } else {
        cout << "Error: No customer found with ID " << id << "." << endl;
    }
}

void Librarian::viewAllCustomers(){
    if (totalMembers == 0) {
        cout << "No customers registered yet." << endl;
        return;
    }
    cout << "\n--- Customer List (" << totalMembers << " customers) ---" << endl;
    for(int i=0;i<totalMembers;i++){
       cout << "ID: " << memberList[i].getId() << " | Name: " << memberList[i].getUsername() << endl;
    }
}

void Librarian::viewCustomerData(int id){
    for(int i =0;i<totalMembers;i++){
        if(memberList[i].getId()==id){
            cout << "Customer Found: " << memberList[i].getUsername()<<endl;
            return;
        }
    }
    cout << "Customer not found"<<endl;
}

Customer* Librarian::loginCustomer(int id ,string user, string pass) {
    for (int i = 0; i < totalMembers; i++) {
        if ( memberList[i].getId() == id && memberList[i].getUsername() == user && memberList[i].getPassword() == pass) {
            return &memberList[i];
        }
    }
    return nullptr;
}

void Librarian::searchByTitle(Library& lib, string title){
    lib.searchByTitle(title);
}


void Librarian::searchByAuthor(Library& lib, string author){
    lib.searchByAuthor(author);
}

void Librarian::searchByCategory(Library& lib, string categ){
    lib.searchByCategory(categ);
}

void Librarian::displayAvailable(Library& lib){
    lib.displayAvailableBooks();
}

void Librarian::displayBorrowed(Library& lib){
    lib.displayBorrowed();
}

void Librarian::displayAll(Library& lib){
    lib.displayAll();
}

void Librarian::viewOverdueBooks(Library& lib){
    lib.displayOverdueBooks();
}

int Librarian::getTotalMembers() {
    return totalMembers; // تأكد إن ده متغير عداد العملاء عندك
}

void Librarian::setMaxBorrowDays(Library& lib, int days) {
    lib.setMaxBorrowDays(days);
}
void Librarian::saveCustomersToFile(string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file for saving customers." << endl;
        return;
    }
    file << totalMembers << "\n";
    for (int i = 0; i < totalMembers; i++) {
        file << memberList[i].getId()       << "\n";
        file << memberList[i].getUsername() << "\n";
        file << memberList[i].getPassword() << "\n";
    }
    file.close();
    cout << ">> Customers saved to '" << filename << "' successfully.\n";
}

void Librarian::loadCustomersFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return; // no file yet, that's fine
    }
    int count;
    file >> count;
    file.ignore();
    totalMembers = 0;
    for (int i = 0; i < count && i < maxMembers; i++) {
        string uname, pass;
        int cid;
        file >> cid;
        file.ignore();
        getline(file, uname);
        getline(file, pass);
        memberList[totalMembers++] = Customer(cid, uname, pass);
    }
    file.close();
    cout << ">> " << totalMembers << " customers loaded successfully.\n";
}
