#ifndef USERPROFILE_H
#define USERPROFILE_H

#include "Closet.h"
#include "Clothing.h"
#include <string>

using namespace std;

class UserProfile {
public:
    UserProfile();
    UserProfile(string username, string zipCode);

    bool login(const string& username, const string& password);
    void logout();

    string getLocation();
    string getUsername();

    Closet<Clothing>& getCloset();

    void saveToFile();

    bool loadFromFile();
private:
    string username;
    string zipCode;
    string password;
    Closet<Clothing> closet;
};

#endif