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

// saves username, password, zipCode to a txt file
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

// loads profile data from file — returns false if file doesn't exist
bool UserProfile::loadFromFile() {
    ifstream file(username + ".txt");
    if (!file.is_open()) {
        return false;
    }

    getline(file, username);
    getline(file, password);
    getline(file, zipCode);

    // load user's clothing items
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        // enables reading an individual line like a file/input stream
        // used to store the individual attribtues of an item as it appears in the txt file
        // e.g. Top,top1,Top,white,0,5,0,1,5,2
        stringstream ss(line);
        string attribute;
        vector<string> attributes;
        while (getline(ss, attribute, ',')) attributes.push_back(attribute);
        
        // each item has to have at least 9 attributes
        if (attributes.size() < 9) continue;

        // here are the 9 attributes assigned
        string classType  = attributes[0];
        string name       = attributes[1];
        string type       = attributes[2];
        string color      = attributes[3];
        bool pattern      = stoi(attributes[4]);
        int warmth        = stoi(attributes[5]);
        bool raining      = stoi(attributes[6]);
        bool basic        = stoi(attributes[7]);
        int dressiness    = stoi(attributes[8]);

        Clothing* item = nullptr;
        
        // additional attributes assignment
        if (classType == "Top" && attributes.size() >= 10) {
            item = new Top(name, type, color, pattern, warmth, raining, basic, dressiness, attributes[9]);
        } else if (classType == "Bottom" && attributes.size() >= 11) {
            item = new Bottom(name, type, color, pattern, warmth, raining, basic, dressiness,
                              stoi(attributes[9]), stoi(attributes[10]));
        } else if (classType == "Dress" && attributes.size() >= 10) {
            item = new Dress(name, type, color, pattern, warmth, raining, basic, dressiness, attributes[9]);
        } else if (classType == "Coat" && attributes.size() >= 11) {
            item = new Coat(name, type, color, pattern, warmth, raining, basic, dressiness,
                            attributes[9], stoi(attributes[10]));
        } else if (classType == "Shoes" && attributes.size() >= 12) {
            item = new Shoes(name, type, color, pattern, warmth, raining, basic, dressiness,
                             stoi(attributes[9]), stoi(attributes[10]), stoi(attributes[11]));
        } else if (classType == "Accessories" && attributes.size() >= 10) {
            item = new Accessories(name, type, color, pattern, warmth, raining, basic, dressiness, attributes[9]);
        }

        if (item != nullptr) {
            closet.closetItems.push_back(item);
        }
    }

    return true;
}