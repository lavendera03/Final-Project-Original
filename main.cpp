#include <iostream>
#include <vector>
#include <string>
#include "Clothing.h"
#include "Closet.h"
#include "UserProfile.h"
#include "AuthSystem.h"

using namespace std;
// -------------------- HELPER METHODS --------------------
bool check_valid(string item, vector<Clothing*> closetItems) {
    bool exists;
    for (int i=0; i < closetItems.size(); i++){
        if (item == closetItems[i]->getName()) {
            return true;
        }
    } return false;
}

Clothing* get_Item(string item_name, vector<Clothing*> closetItems) {
    for (int i=0; i < closetItems.size(); i++){
        if (item_name == closetItems[i]->getName()) {
            return closetItems[i];
        }
    } return nullptr;
}

int login_menu();
int main_menu();

// -------------------- NAVIGATING MAIN MENU --------------------
int main() {
    UserProfile profile;
    AuthSystem auth;
    bool loggedIn = false;

    // -------------------- LOGGING IN / SIGNING UP --------------------
    while (!loggedIn) {
        int login_choice = login_menu();
        if (login_choice == 0) { // Exiting program
            cout << "Goodbye!" << endl;
            return false;
        } else if (login_choice == 1) { // Logging in
            loggedIn = auth.handleLogin(profile);
        } else if (login_choice == 2) { // Signing up 
            loggedIn = auth.handleSignup(profile);
        } else if (login_choice > 2) { 
            cout << "Invalid Input. Please enter one of the indices listed below." << endl;
        }
    }

     // -------------------- NAVIGATING MAIN MENU --------------------
    Closet<Clothing>& user_closet = profile.getCloset();
    while(true) {
        int choice = main_menu();
        if (choice == 0){
            profile.logout();
            break;
        } else if (choice == 1) { // ADD CLOTHING ITEM 
            user_closet.addClothing();
            profile.saveToFile();
            cout << "\n +++++Your clothing item has been added!+++++" << endl;
        } else if (choice == 2) { // REMOVE CLOTHING ITEM
            string itemToRemove;
            cout << "\nWhat item do you want to remove?: \n> "; 
            getline(cin, itemToRemove);
            user_closet.removeItem(itemToRemove);
            profile.saveToFile();
            cout << "\n+++++ " << itemToRemove << " has been removed from your closet!+++++" << endl;
        } else if (choice == 3) { // GENERATE OUTFIT
            int dressinessLevel;
            int temp;
            cout << "\nPlease enter dressiness: \n> "; 
            cin >> dressinessLevel;
            cin.ignore();
            cout << "\nPlease average temperature: \n> "; 
            cin >> temp;
            cin.ignore();
            vector<Clothing*> outfit = user_closet.generateOutfit(dressinessLevel, temp);
            if (outfit.empty()) {
                cout << "To use this feature please input more clothing items." << endl;
            } else {
                for (Clothing* item : outfit) {
                    cout << item->getName() << ": " << item->itemDescription() << endl;
                }
            }
        } else if (choice == 4) { // SAVE AN OUTFIT
            vector<Clothing*> outfitItems;
            string user_input;
            while (true) {
                cout << "What item do you want to add to this outfit?: \n> "; getline(cin, user_input);
                if (user_input == "Done") { 
                    break;
                } else if (check_valid(user_input, user_closet.closetItems)) {
                    outfitItems.push_back(get_Item(user_input, user_closet.closetItems));
                    cout << user_input << " was added to this outfit." << endl;
                } else if (!check_valid(user_input, user_closet.closetItems)) {
                    cout << "That item does not exist in the closet. Please enter a valid item: \n> ";
                }
            }
            user_closet.saveOutfit(outfitItems);
        } else if (choice == 5) { // SHOW SAVED OUTFITS
            user_closet.showOutfits();
        } else if (choice == 6) { // SHOW ITEMS IN CLOSET
            user_closet.showCloset();
        } else if (choice > 6) { 
            cout << "Invalid Input. Please enter one of the indices listed below." << endl;
        } 
    } return 0;
}

// -------------------- MENU AND SUBMENU OPTIONS --------------------
int main_menu() { // Main Menu Options
    cout << "\n\n==============================" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Generate Outfit" << endl;
    cout << "4. Save An Outfit" << endl;
    cout << "5. Show Saved Outfits" << endl;
    cout << "6. Show Items in Closet" << endl;
    cout << "0. Exit" << endl;
    cout << "==============================" << endl;
    cout << "Please choose an option: \n> ";
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

int login_menu() { // Login Menu Options
    cout << "\n===== ForecastFits =====\n";
    cout << "1. Login\n";
    cout << "2. Sign Up\n";
    cout << "0. Exit\n";
    cout << "==============================" << endl;
    cout << "Please choose an option: \n> ";
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}