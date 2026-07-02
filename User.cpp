#include "User.h"
using namespace std;

User::User(int i, string n, string p) {
    id = i;
    username = n;
    password = p;
}

User::~User() {
    // Empty destructor for now
}

void User::setUsername(string n) { username = n; }
string User::getUsername() const { return username; }

void User::setPassword(string p) { password = p; }
string User::getPassword() const { return password; }

void User::setUserId(int ID){ id = ID; }
int User::getId() const { return id; }

bool User::Login(int Id, string User, string Pass) {
    if (Id == id && User == username && Pass == password) {
        cout << "Login Successful! Welcome " << username << endl;
        return true;
    } else {
        cout << "Invalid ID, Username, or Password." << endl;
        return false;
    }
}

bool User::checkPassword(string p) const {
    return password == p;
}