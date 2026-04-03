#include "UserProfile.h"
#include <iostream>
#include <fstream>

using namespace std;

// default constructor
UserProfile::UserProfile() {}

// parametrized constructor
UserProfile::UserProfile(string username, string zipCode)
    : username(username), zipCode(zipCode) {}

// user trying to enter using a username and password
bool UserProfile::login(const string& inputUsername, const string& inputPassword) {
    username = inputUsername;
    if (!loadFromFile()) {
        cout << "No account found with that username.\n";
        return false;
    }
    if (password != inputPassword) {
        cout << "Incorrect password.\n";
        return false;
    }
    cout << "Welcome to your closet, " << username << "!\n";
    return true;
}

// saving to file when logging out
void UserProfile::logout() {
    saveToFile();
    cout << "Logged out. Goodbye, " << username << "!\n";
}

// getters
string UserProfile::getLocation() {
    return zipCode;
}

Closet& UserProfile::getCloset() {
    return closet;
}

string UserProfile::getUsername() {
    return username;
}

void UserProfile::updateProfile() {
    cout << "New zip code (or press Enter to keep '" << zipCode << "'): ";
    string input;
    getline(cin, input);
    if (!input.empty()) zipCode = input;
    saveToFile();
    cout << "Profile updated.\n";
}

// Saves username, password, zipCode to a flat file
void UserProfile::saveToFile() {
    ofstream file(username + ".txt");
    if (file.is_open()) {
        file << username << "\n";
        file << password << "\n";
        file << zipCode << "\n";
    }
}

// Loads profile data from file — returns false if file doesn't exist
bool UserProfile::loadFromFile() {
    ifstream file(username + ".txt");
    if (!file.is_open()) return false;

    getline(file, username);
    getline(file, password);
    getline(file, zipCode);
    return true;
}