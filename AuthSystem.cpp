#include "AuthSystem.h"
#include <iostream>
#include <fstream>
using namespace std;

bool AuthSystem::handleLogin(UserProfile& profile) {
    string username, password;
    cout << "\n-- Login --\n";
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    return profile.login(username, password);
}

bool AuthSystem::handleSignup(UserProfile& profile) {
    string username, password, zip;
    cout << "\n-- Sign Up --\n";
    cout << "Choose a username: ";
    getline(cin, username);

    // check if username already exists
    ifstream check(username + ".txt");
    if (check.is_open()) {
        cout << "Username already taken. Please log in instead.\n";
        return false;
    }

    cout << "Choose a password: ";
    getline(cin, password);
    cout << "Enter your zip code: ";
    getline(cin, zip);

    // write the new profile file directly so login() can load it
    ofstream file(username + ".txt");
    file << username << "\n" << password << "\n" << zip << "\n";
    file.close();

    cout << "\nAccount created!\n";
    return profile.login(username, password);
}