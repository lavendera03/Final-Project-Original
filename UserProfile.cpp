#include "UserProfile.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
    cout << "\nWelcome to your closet, " << username << "!\n";
    return true;
}

// saving to file when logging out
void UserProfile::logout() {
    saveToFile();
    cout << "\nLogged out. Goodbye, " << username << "!\n";
}

// getters
string UserProfile::getLocation() {
    return zipCode;
}

Closet<Clothing>& UserProfile::getCloset() {
    return closet;
}

string UserProfile::getUsername() {
    return username;
}

// Saves username, password, zipCode to a flat file
void UserProfile::saveToFile() {
    ofstream file(username + ".txt");
    if (!file.is_open()) {
        return;
    }
    file << username << "\n";
    file << password << "\n";
    file << zipCode << "\n";

    // serialize items in user's closet
    for (Clothing* item : closet.closetItems) {
        file << item->serialize() << "\n"; 
    }
}

// Loads profile data from file — returns false if file doesn't exist
bool UserProfile::loadFromFile() {
    ifstream file(username + ".txt");
    if (!file.is_open()) {
        return false;
    }

    getline(file, username);
    getline(file, password);
    getline(file, zipCode);
    //return true;

    // load user's clothing items
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        vector<string> fields;
        while (getline(ss, token, ',')) fields.push_back(token);

        if (fields.size() < 9) continue;

        string classType  = fields[0];
        string name       = fields[1];
        string type       = fields[2];
        string color      = fields[3];
        bool pattern      = stoi(fields[4]);
        int warmth        = stoi(fields[5]);
        bool raining      = stoi(fields[6]);
        bool basic        = stoi(fields[7]);
        int dressiness    = stoi(fields[8]);

        Clothing* item = nullptr;

        if (classType == "Top" && fields.size() >= 10) {
            item = new Top(name, type, color, pattern, warmth, raining, basic, dressiness, fields[9]);
        } else if (classType == "Bottom" && fields.size() >= 11) {
            item = new Bottom(name, type, color, pattern, warmth, raining, basic, dressiness,
                              stoi(fields[9]), stoi(fields[10]));
        } else if (classType == "Dress" && fields.size() >= 10) {
            item = new Dress(name, type, color, pattern, warmth, raining, basic, dressiness, fields[9]);
        } else if (classType == "Coat" && fields.size() >= 11) {
            item = new Coat(name, type, color, pattern, warmth, raining, basic, dressiness,
                            fields[9], stoi(fields[10]));
        } else if (classType == "Shoes" && fields.size() >= 12) {
            item = new Shoes(name, type, color, pattern, warmth, raining, basic, dressiness,
                             stoi(fields[9]), stoi(fields[10]), stoi(fields[11]));
        } else if (classType == "Accessories" && fields.size() >= 10) {
            item = new Accessories(name, type, color, pattern, warmth, raining, basic, dressiness, fields[9]);
        }

        if (item) closet.closetItems.push_back(item);
    }

    return true;
}