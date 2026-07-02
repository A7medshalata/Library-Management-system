#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

class User {
protected: // Protected so children (Customer/Librarian) can see them
    int id;
    string username;
    string password;

public:
    User(){};
    User(int i, string n, string p);
    
    // Virtual Destructor - important for inheritance!
     ~User();

    // Basic Getters & Setters
    void setUsername(string n);
    string getUsername() const;
    
    void setPassword(string p);
    string getPassword() const;

    void  setUserId(int ID);
    int getId() const;

    // Logic
    bool Login(int Id, string User, string Pass);

    bool checkPassword(string p) const;
    
    
};

#endif