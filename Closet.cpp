#include "Closet.h"

#include <iostream>
#include <string>

using namespace std;

// ----------------------- Constructor -----------------------
template <typename T>
Closet<T>::Closet(){}

// ----------------------- Methods -----------------------
template <typename T>
void Closet<T>::showCloset() {
/* Shows the item name and description for each item in the user's closet */
    cout << "----- CLOSET -----" << endl;
    if (closetItems.empty()) {
        cout << "(empty)" << endl;
    } else {
        for (int item = 0; item < closetItems.size(); item++) {
            cout << "+ " << closetItems[item].getName() << ": " << closetItems[item].itemDescription() << endl;
        }
    } cout << "---------------------" << endl;
    cout << endl;
}

template <typename T>
void Closet<T>::saveOutfit(vector<Clothing> newOutfit) {
/* Stores a group of clothing items that pair well together 
        - savedOutfits: The vector containg all of the current saved outfits
    */
    savedOutfits.push_back(newOutfit);
}

template <typename T>
void Closet<T>::showOutfits() {
/* Outputs all of the outfits that the user has saved */
    cout << "----- SAVED OUTFITS -----" << endl;
    if (savedOutfits.empty()) {
        cout << "(No saved outfits)" << endl;
    } else {
        for (int outfit = 0; outfit < savedOutfits.size(); outfit++) {
            cout << "Outfit " << outfit << endl;
            for (int item = 0; item < savedOutfits[outfit].size(); item++) {
                cout << "+ " << savedOutfits[outfit][item].getName() << ": " << savedOutfits[outfit][item].itemDescription() << endl;
            }       
        }
    } cout << "---------------------" << endl;
    cout << endl;
}

// ----------------------- Methods for adding clothing items to closets -----------------------
template <typename T>
void Closet<T>::addClothing() {

    cout << "Enter a name for your item" << endl;
    string name;
    getline(cin, name);

    cout << "Enter the type of your item" << endl;
    string type;
    getline(cin, type);

    cout << "Enter the color of your item" << endl;
    string color;
    getline(cin, color);

    cout << "Enter yes if your item is patterned if not enter no" << endl;
    string patt;
    getline(cin, patt);
    bool patty = false;
    if (patt = "yes"){
        patty = true;
    }

    cout << "On a scale 1-5 how warm is your item" << endl;
    int warmth;
    getline(cin, warmth);


    cout << "Enter yes if you would wear this item in the rain" << endl;
    string rain;
    getline(cin, rain);
    bool rainy = false;
    if (rain = "yes"){
        rainy = true;
    }

    cout << "Enter yes if you would consider this item to be a basic" << endl;
    string basic;
    getline(cin, basic);
    bool bassic = false;
    if (basic = "yes"){
        bassic = true;
    }

    cout << "On a scale 1-5 how dressy is your item" << endl;
    int dressy;
    getline(cin, dressy);


    if (type == "Top" ) { 
        cout << "Is your top 1 long sleeve, 2 short sleeve, or 3 sleevless. Enter a number " << endl;
        int length;
        getline(cin, length);
        Top newtop = Top(name, type, color, patty, warmth, rainy, bassic, length);
        closetItems.push_back(newtop);
    }
    
     else if (type == "Bottom"){
        cout << "Enter yes if this item is shorts" << endl;
        string short;
        getline(cin, short);
        bool shorty = false;
        if (short = "yes"){
            shorty = true;
        }
        cout << "Enter yes if this item is a skirt" << endl;
        string skirt;
        getline(cin, skirt);
        bool skirty = false;
        if (skirt = "yes"){
            skirty = true;
        }
        Bottom newBottom = Bottom(name, type, color, patty, warmth, rainy, bassic, shorty, skirty);
        closetItems.push_back(newBottom);
    }
    

    else if (type == "Dress") {
        cout << "How long is your dress" << endl;
        string length;
        getline(cin, length);
        Dress newDress = Dress(name, type, color, patty, warmth, rainy, bassic, length);
        closetItems.push_back(newDress);
    }
    

     else if (type == "Accessories") { 
        cout << "What type of accesory is this " << endl;
        string typpe;
        getline(cin, typpe);
        Accessories newAcc = Accessories(name, type, color, patty, warmth, rainy, bassic, typpe);
        closetItems.push_back(newAcc);
    } 
    
    
    else if (type == "Coat") { 
        Coat newCoat = Coat(name, type, color, patty, warmth, rainy, bassic);
        closetItems.push_back(newCoat);
    }  
    
    
    else if (type == "Shoes") { 
        cout << "Enter yes if these shoes are open toe" << endl;
        string open;
        getline(cin, open);
        bool openToe = false;
        if (open = "yes"){
            openToe = true;
        }

        cout << "Enter yes if these shoes are heels" << endl;
        string heel;
        getline(cin, heel);
        bool heely = false;
        if (heel = "yes"){
            heely = true;
        }

        cout << "Enter yes if these shoes ar athletic sneakers" << endl;
        string sneak;
        getline(cin, sneak);
        bool sneaky = false;
        if (sneak = "yes"){
            sneaky = true;
        }
        Shoes newShoes = Shoes(name, type, color, patty, warmth, rainy, bassic, openToe, heely, sneaky);
        closetItems.push_back(newShoes);
    }


}

template <typename T>
void Closet<T>::removeItem(string name) {
    int i = 0;
    bool exists = false;
    for(int i; i < closetItems.size(); i++ ){
        if(closetItems[i].name() == name){
            exists = true;
            break;
        }
    }
    if(exists){
        closetItems.erase(closetItems.begin() + i);
    }
    else{
        cout << "An item with that name was not found in your closet"
    }

}

template <typename T>
vector<Clothing> Closet<T>::generateOutfit(int dressiness, int avgTemp) {

}


